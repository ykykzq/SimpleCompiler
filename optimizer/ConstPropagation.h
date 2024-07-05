/**
 * @file ConstPropagation.h
 * @author ykykzq(https://github.com/ykykzq)
 * @brief 基于CFG进行常数传播优化
 * @version 0.1
 * @date 2024-06-21
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../../common/SymbolTable.h"
#include "../common/drawCFG/drawCFG.h"

// ConstPropagation
class ConstPropagation {
protected:
    CFG_Generator * cfg_generator;

public:
    ConstPropagation(CFG_Generator * _cfg_generator) : cfg_generator(_cfg_generator)
    {}

    /// @brief 基于CFG进行常数传播优化
    /// @return 优化是否成功，true：成功，false：失败
    bool run();
};
