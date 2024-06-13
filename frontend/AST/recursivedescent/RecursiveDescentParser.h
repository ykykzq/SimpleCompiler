/**
 * @file CalculatorRDParser.h
 * @author zenglj (zenglj@nwpu.edu.cn)
 * @brief 递归下降分析法实现的语法分析后产生抽象语法树的头文件
 * @version 0.1
 * @date 2024-01-24
 *
 * @copyright Copyright (c) 2024
 *
 */
#pragma once

#include "AST.h"
#include "AttrType.h"

/// @brief Token类型
enum RDTokenType {
    T_EMPTY = -2,
    T_ERR = -1,
    T_EOF = 0,

    T_DIGIT,
    T_ID,
    T_ADD,
    T_SUB,
    T_LPAREN,
    T_RPAREN,
    T_ASSIGN,
    T_SEMICOLON,
    T_FUNC,
    T_RETURN,
};

/// @brief 词法与语法分析数据交互的Token的值类型
union RDSType {
    ast_node * node;
    digit_int_attr integer_num; // 整型字面量
    digit_real_attr float_num;  // 实数字面量
    var_id_attr var_id;         // 标识符（变量名）
};

/// @brief 词法与语法分析数据交互的Token的值
extern RDSType rd_lval;

/// @brief 语法分析函数的原型
int rd_parse();
