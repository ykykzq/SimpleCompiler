﻿/**
 * @file symboltable.h
 * @author zenglj (zenglj@nwpu.edu.cn)
 * @brief 符号表管理：变量、函数等管理的头文件
 * @version 0.1
 * @date 2023-09-24
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once

#include <unordered_map>
#include <vector>

#include "Function.h"
// #include "Block.h"
//#include "IRCode.h"
#include "../frontend/DragonIR/IRCode.h"
#include "Value.h"

class Function;

/// @brief 符号表管理类
class SymbolTable {

public:
    /// @brief 构造函数
    SymbolTable();

    /// @brief 根据函数名查找函数信息
    /// @param name 函数名
    /// @return 函数信息
    Function * findFunction(std::string name);

    /// @brief 插入函数。如果函数存在，则返回false，否则返回true
    /// @param func 函数信息
    /// @return true: 可以插入函数 false: 不能插入函数
    bool insertFunction(Function * func);

    /// @brief 移动到函数列表的尾部
    /// @param func
    void moveFunctionEnd(Function * func);

    /// @brief 输出线性IR指令列表
    /// @param filePath
    void outputIR(const std::string & filePath);

    /// @brief 获得函数列表
    std::vector<Function *> & getFunctionList()
    {
        return funcVector;
    }

    /// @brief 根据变量名获取当前符号（只管理全局变量）
    /// \param name 变量名
    /// \param create 变量查找不到时若为true则自动创建，否则不创建
    /// \return 变量对应的值
    Value * findValue(std::string name, bool create = false);

    /// @brief 新建变量型Value，全局变量
    /// @param name 变量ID
    /// @param type 变量类型
    Value * newVarValue(std::string name, BasicType type = BasicType::TYPE_INT);

    /// @brief 新建全局变量型Value
    /// @param name 变量ID
    /// @param type 变量类型
    /// @param index 下标集合
    Value * newArrayValue(std::string name, BasicType type, std::vector<int32_t> index);

    /// @brief 新建一个整型数值的Value，并加入到符号表，用于后续释放空间
    /// \param intVal 整数值
    /// \return 临时Value
    Value * newConstValue(int32_t intVal);

    /// @brief 新建一个实数数值的Value，并加入到符号表，用于后续释放空间
    /// \param intVal 整数值
    /// \return 临时Value
    Value * newConstValue(float realVal);

    /// @brief 清理注册的所有Value资源
    void freeValues();

    /// @brief 新建函数并放到函数列表中
    /// @param name 函数名
    /// @param returnType 返回值类型
    /// @param params 形参列表
    /// @param builtin 是否内置函数
    /// @return 新建的函数对象实例
    Function *
    newFunction(std::string name, BasicType returnType, std::vector<FuncFormalParam> params, bool builtin = false);

    /// @brief 新建函数并放到函数列表中
    /// @param name 函数名
    /// @param returnType 返回值类型
    /// @param builtin 是否内置函数
    /// @return 新建的函数对象实例
    Function * newFunction(std::string name, BasicType returnType, bool builtin = false);

protected:
    /// @brief Value插入到符号表中
    /// @param val Value信息
    void insertValue(Value * val);

public:
    /// @brief main函数
    // Function * mainFunc = nullptr;

    /// 遍历抽象树过程中的当前处理函数
    Function * currentFunc = nullptr;

    // /// 遍历抽象树过程中的当前语句块
    // Block * currentBlock = nullptr;

private:
    /// @brief 变量名映射表，变量名-变量，只保存全局变量以及常量
    std::unordered_map<std::string, Value *> varsMap;

    /// @brief 只保存全局变量以及常量
    std::vector<Value *> varsVector;

    /// @brief 函数映射表，函数名-函数，便于检索
    std::unordered_map<std::string, Function *> funcMap;

    /// @brief  函数列表
    std::vector<Function *> funcVector;
};
