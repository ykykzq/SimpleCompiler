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
    return true;
}