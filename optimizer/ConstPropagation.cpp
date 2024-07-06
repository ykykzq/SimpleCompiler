/**
 * @file ConstPropagation.cpp
 * @author ykykzq(https://github.com/ykykzq)
 * @brief 基于CFG进行常数传播优化
 * @version 0.1
 * @date 2024-06-21
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "./ConstPropagation.h"

/// @brief 基于CFG进行常数传播优化
/// @return 优化是否成功，true：成功，false：失败
bool ConstPropagation::run()
{
    //为每个function维护一张表，存储着变量是否已经被赋值

    //每次切换block时清空
    for (auto cp_func: cp_functions) {
        for (auto block: cp_func->blocks) {
            //清空var_table
            cp_func->var_table_flag.clear();
            cp_func->var_table_value.clear();

            //对于每一条ir进行处理
            int i = 0; //方便删除ir
            for (auto ir_inst: block->irInstructions) {
                if (ir_inst->getOp() == IRInstOperator::IRINST_OP_ASSIGN) {
                    //如果是赋值语句
                    AssignIRInst * assignInst = dynamic_cast<AssignIRInst *>(ir_inst);

                    //处理左值
                    if (assignInst->getSrc()[0]->isConst()) {
                        //如果右值为常数

                        //更新表，记录左值新状态
                        cp_func->var_table_flag[assignInst->getDst()] = true;
                        cp_func->var_table_value[assignInst->getDst()] = assignInst->getSrc()[0]->intVal; //改为右值的值

                        //这条赋值ir可以删除
                        block->irInstructions.erase(block->irInstructions.begin() + i);
                    } else if (cp_func->var_table_flag[assignInst->getSrc()[0]]) {
                        //如果右值已经赋值

                        //更新表，记录左值新状态
                        cp_func->var_table_flag[assignInst->getDst()] = true;
                        cp_func->var_table_value[assignInst->getDst()] =
                            cp_func->var_table_value[assignInst->getSrc()[0]]; //改为右值的值

                        //这条赋值ir可以删除
                        block->irInstructions.erase(block->irInstructions.begin() + i);
                    }
                } // end if
                i++;
            } // end block for
        }
    } // end func for
    return true;
}

/// @brief 输出Dragon IR
/// @return 优化是否成功，true：成功，false：失败
bool ConstPropagation::outputIR(const std::string & filePath)
{
    // 这里使用C的文件操作，也可以使用C++的文件操作

    FILE * fp = fopen(filePath.c_str(), "w");
    if (nullptr == fp) {
        printf("fopen() failed\n");
        return false;
    }
    std::string instStr;
    // 遍历所有的线性IR指令，文本输出
    // 全局符号表
    for (auto var: symtab->getVarsList()) {

        if (var->isArray()) {
            //数组单独处理

            instStr = "declare " + var->type.toString() + " " + var->getName();
            for (auto index: var->arrayIndexVector) {
                instStr = instStr + "[" + std::to_string(index) + "]";
            }

            instStr = instStr + "\n";
            continue;
        }
        if (var->isLocalVar()) {
            if (var->intVal == 0) {
                //没有初始化
                instStr = "declare " + var->type.toString() + " " + var->getName() + "\n";
            } else {
                //进行初始化
                instStr = "declare " + var->type.toString() + " " + var->getName() + " = " +
                          std::to_string(var->intVal) + "\n";
            }
        }
    }
    // 全局函数列表
    for (auto cp_func: cp_functions) {

        auto func_in_symtab = symtab->findFunction(cp_func->name);
        if (func_in_symtab->isBuiltin()) {
            continue;
        }
        // 输出函数头
        instStr = "define " + func_in_symtab->getReturnType().toString() + " @" + cp_func->name + "(";

        bool firstParam = false;
        for (auto & param: func_in_symtab->getParams()) {

            if (!firstParam) {
                firstParam = true;
            } else {
                instStr += ", ";
            }

            std::string param_str = param.toString();

            instStr += param_str;
        }

        instStr += ")\n";

        instStr += "{\n";

        //输出局部变量
        for (auto & val: func_in_symtab->getVarValues()) {

            //不需要输出形参
            bool is_param = false;
            for (const auto & param: func_in_symtab->getParams()) {
                if (val->name == param.val->name) {
                    is_param = true;
                    break;
                }
            }

            if (val->isLocalVar() || val->isTemp()) {
                if (is_param) {
                    //如果是形参，则已经定义过，不需要再定义
                    continue;
                } else if (val->isArray()) {
                    //如果是数组
                    instStr += "\tdeclare " + val->type.toString() + " " + val->toString();
                    for (auto index: val->arrayIndexVector) {
                        instStr += "[" + std::to_string(index) + "]";
                    }
                    instStr += +"\n";
                } else if (val->isPointer()) {
                    //指针变量
                    //因为更改了value的toString()，不需要在此进行修改
                    instStr += "\tdeclare " + val->type.toString() + " " + val->toString() + "\n";
                } else

                {
                    //是普通变量
                    //第一次修改，替换为declare
                    //第二次修改，使得可以输出type。不在values中输出，而是在此处输出type
                    instStr += "\tdeclare " + val->type.toString() + " " + val->toString() + "\n";
                }
            }
        }

        // 遍历所有的线性IR指令，文本输出
        for (auto & inst: cp_func->getInsts()) {
            std::string temp_str;
            inst->toString(temp_str);

            if (!temp_str.empty()) {

                // Label指令不加Tab键
                if (inst->getOp() == IRInstOperator::IRINST_OP_LABEL) {
                    temp_str = "." + temp_str + "\n";
                } else {
                    temp_str = "\t" + temp_str + "\n";
                }
            }
            instStr += temp_str;
        }
        // 输出函数尾部
        instStr += "}\n";
    }
    fprintf(fp, "%s", instStr.c_str());
    fclose(fp);
    return true;
}