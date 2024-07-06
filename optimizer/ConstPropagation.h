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
#include "Value.h"
#include <vector>

// ConstPropagation
class CP_function : public CFG_function {
public:
    /// @brief 一张表，记录是否进行了赋值
    std::unordered_map<Value *, bool> var_table_flag;
    std::unordered_map<Value *, int> var_table_value;

public:
    /// @brief 构造函数
    CP_function()
    {}

    /// @brief 构造函数，从cfg_function
    CP_function(CFG_function _cfg_func)
    {
        //拷贝
        name = _cfg_func.name;
        blocks = _cfg_func.blocks;
        blockMap = _cfg_func.blockMap;
        nodes = _cfg_func.nodes;
        nodeMap = _cfg_func.nodeMap;
        code = _cfg_func.code;
    }
};
class ConstPropagation {
protected:
    /// @brief 存储函数
    std::vector<CP_function *> cp_functions;
    std::unordered_map<std::string, CP_function *> funcMap;
    /// @brief 符号表
    SymbolTable * symtab;

public:
    /// @brief 构造函数
    ConstPropagation(CFG_Generator * cfg_generator)
    {
        symtab = cfg_generator->getSymtab();
        //初始化func
        for (auto cfg_fun: cfg_generator->getFunctions()) {
            //拷贝到func中
            CP_function * cp_func = new CP_function(*cfg_fun);

            //把函数加入到当前ConstPropagation中
            cp_functions.push_back(cp_func);
            funcMap[cp_func->name] = cp_func;
        }
    }

    /// @brief 基于CFG进行常数传播优化
    /// @return 优化是否成功，true：成功，false：失败
    bool run();

    /// @brief 输出Dragon IR
    /// @return 输出是否成功，true：成功，false：失败
    bool outputIR(const std::string & filePath);
};