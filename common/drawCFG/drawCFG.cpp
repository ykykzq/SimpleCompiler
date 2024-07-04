/**
 * @file drawCFG.cpp
 * @author ykykzq(https://github.com/ykykzq)
 * @brief 根据已经生成的ir文件，生成CFG
 * @version 0.1
 * @date 2024-06-21
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <gvc.h>
#include "./drawCFG.h"
#include "IRInst.h"

/// @brief 识别到label语句
/// @param ir_inst ir语句
/// @return 翻译是否成功，true：成功，false：失败
bool CFG_Generator::label_inst(IRInst * ir_inst)
{

    //取出label的名字
    //去除label name中的第一个字符"."和最后的":""
    auto label_name = ir_inst->getLabelName();

    //同时还需要检查当前的block是否已经有出口。
    //没有出口代表平滑流入新的block，设置出口
    if (getCurrentFunction()->currentBlock != nullptr) {
        if (getCurrentFunction()->currentBlock->exits.empty()) {
            getCurrentFunction()->currentBlock->exits.push_back(label_name);
        }
    }

    //新建并更换当前function的block
    //并把label作为当前block的唯一索引，添加到block入口中
    auto new_block = getCurrentFunction()->newBlock();
    getCurrentFunction()->addEntry2Block(label_name, new_block);
    getCurrentFunction()->currentBlock = new_block;

    // label塞入当前块内
    getCurrentFunction()->currentBlock->irInstructions.push_back(ir_inst);

    return true;
}

/// @brief 识别到跳转
/// @param ir_inst ir语句
/// @return 翻译是否成功，true：成功，false：失败
bool CFG_Generator::goto_inst(IRInst * ir_inst)
{
    // 跳转指令也去掉'\t'后塞入当前块内
    getCurrentFunction()->currentBlock->irInstructions.push_back(ir_inst);

    GotoIRInst * gotoInst = dynamic_cast<GotoIRInst *>(ir_inst);
    // 区分 br 与 bc

    if (gotoInst->getTrueLabel() == gotoInst->getFalseLabel()) {
        // br，只添加一个出口

        auto label_name = gotoInst->getTrueLabel()->getLabelName();
        getCurrentFunction()->currentBlock->exits.push_back(label_name);
    }

    else if (gotoInst->getTrueLabel() != gotoInst->getFalseLabel()) {
        // bc，添加两个出口

        auto label_name1 = gotoInst->getTrueLabel()->getLabelName();
        getCurrentFunction()->currentBlock->exits.push_back(label_name1);

        //去除label name中的第一个字符"."后，放进block中
        auto label_name2 = gotoInst->getFalseLabel()->getLabelName();
        getCurrentFunction()->currentBlock->exits.push_back(label_name2);
    }

    else {
        // 取出第一个单词失败
        return false;
    }
    return true;
}

/// @brief 识别到其他语句
/// @param ir_inst ir语句
/// @return 翻译是否成功，true：成功，false：失败
bool CFG_Generator::default_expr_inst(IRInst * ir_inst)
{
    // 这里是对第二种情况的处理逻辑
    // 去除'\t'后塞入到当前function的当前block里
    getCurrentFunction()->currentBlock->irInstructions.push_back(ir_inst);

    return true;
}

/// @brief 运行产生CFG
/// @param print_flag true:生成并打印;false:只生成CFG
/// @return 翻译是否成功，true：成功，false：失败
bool CFG_Generator::run(bool print_flag)
{
    //遍历每个function
    for (auto ir_func: symtab->getFunctionList()) {
        // 新建并更换当前的fuction
        auto func = newFunction(ir_func->getName());
        setCurrentFunction(func);
        currentFunction->name = ir_func->getName();

        //遍历ir
        for (auto ir: ir_func->getInterCode().getInsts()) {
            if (ir->getOp() == IRInstOperator::IRINST_OP_GOTO) {
                //跳转指令
                goto_inst(ir);
            } else if (ir->getOp() == IRInstOperator::IRINST_OP_LABEL) {
                // label
                label_inst(ir);
            } else {
                //其他指令均塞进去
                default_expr_inst(ir);
            }
        }
    }

    //下面遍历func和func中的block，生成CFG
    //遍历函数
    for (auto cfg_func: functions) {
        // 创建一个Graphviz上下文
        GVC_t * gvc = gvContext();

        // 创建一个空的图
        Agraph_t * g = agopen("g", Agdirected, nullptr);

        //遍历block，创建所有node
        for (auto cfg_blcok: cfg_func->blocks) {
            //创建节点
            Agnode_t * n1 = agnode(g, cfg_blcok->entries[0].data(), 1);
            std::string all_ir_str;
            //把ir添加进去
            for (const auto & ir: cfg_blcok->irInstructions) {
                std::string ir_str;
                ir->toString(ir_str);
                all_ir_str = all_ir_str + ir_str + "\n";
            }
            agsafeset(n1, "shape", "box", "");
            agsafeset(n1, "label", all_ir_str.data(), "");
            cfg_func->addCFGnode(cfg_blcok, n1);
        }

        //再遍历一次block，创建所有edge
        for (auto cfg_blcok1: cfg_func->blocks) {
            //创建边
            auto from_node = cfg_func->nodeMap[cfg_blcok1];
            for (const auto & exit_label: cfg_blcok1->exits) {
                auto to_block = cfg_func->blockMap[exit_label];
                if (to_block != nullptr) {
                    auto to_node = cfg_func->nodeMap[to_block];
                    agedge(g, from_node, to_node, nullptr, 1);
                }
            }
        }
        //输出图片；每一个函数输出一张图
        // 设置布局
        gvLayout(gvc, g, "dot");
        // 设置输出格式
        std::string dest_directory = ""; //暂时不设置输出文件夹
        std::string outputFormat = "png";
        std::string outputFile = dest_directory + cfg_func->name + ".png";

        if (print_flag) {
            // 渲染图并输出到文件
            FILE * fp = fopen(outputFile.c_str(), "w");
            gvRender(gvc, g, outputFormat.c_str(), fp);
            fclose(fp);
        }

        // 释放资源
        gvFreeLayout(gvc, g);
        agclose(g);
        gvFreeContext(gvc);
    }

    return true;
}