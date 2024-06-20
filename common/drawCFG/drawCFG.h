// 应当定义两个类：CFG_function与CFG_blcok。
// 其中CFG_block有如下参数：一个vector，存储该函数的所有CFG_blcok；一个unordered_map，保存从std::string到CFG_blcok的映射关系；一个currentBlcok，保存当前正在活动的CFG_block
// CFG_blcok类有如下参数：一个存储std::string的vector，存储该block所有的入口；一个存储std::string的vector，存储该函数所有的出口；一个存储std::string的vector，存储所有的ir指令
// 该头文件还定义一个全局变量： CFG_currentFunction，保存当前正在活动的CFG_function
#ifndef CFG_H
#define CFG_H

#include <vector>
#include <unordered_map>
#include <string>
#include <gvc.h>

// CFG_block类
class CFG_block {
public:
    std::vector<std::string> entries;        // 存储该block所有的入口
    std::vector<std::string> exits;          // 存储该block所有的出口
    std::vector<std::string> irInstructions; // 存储所有的ir指令

    CFG_block()
    {}
};

// CFG_function类
class CFG_function {
public:
    // 当前正在活动的CFG_block
    CFG_block * currentBlock;

    std::string name; //函数的名字

    std::vector<CFG_block *> blocks;                       // 存储该函数的所有CFG_block
    std::unordered_map<std::string, CFG_block *> blockMap; // entries到block的映射

    //用来画图
    std::vector<Agnode_t *> nodes; // 存储该函数的所有CFG_block
    std::unordered_map<CFG_block *, Agnode_t *> nodeMap;

public:
    CFG_function() : currentBlock(nullptr)
    {}

    /// @brief 新建一个block
    /// @param
    /// @return 指向新block的指针
    CFG_block * newBlock()
    {
        auto new_block = new CFG_block(); // Corrected the variable name from new_blcok to new_block
        blocks.push_back(new_block);
        return new_block;
    }

    /// @brief 向Block中添加entries
    /// @param entry 入口,是一个字符串
    /// @param cfg_block 对应的cfg_block
    /// @return 指向新block的指针
    bool addEntry2Block(std::string entry, CFG_block * cfg_block)
    {
        //向block中添加入口
        cfg_block->entries.push_back(entry);
        blockMap[entry] = cfg_block;
        return true;
    }

    // 添加一个新的node
    void addCFGnode(CFG_block * block, Agnode_t * node)
    {
        nodes.push_back(node);
        nodeMap[block] = node;
    }
};

// CFG_Generator类，管理多个CFG_function对象
class CFG_Generator {
protected:
    std::vector<CFG_function *> functions; // 存储所有的CFG_function对象
    std::unordered_map<std::string, CFG_function *> funcMap;
    CFG_function * currentFunction; // 当前活动的CFG_function
public:
    CFG_Generator() : currentFunction(nullptr)
    {}

    /// @brief 新建一个function
    /// @param name 新function的名字
    /// @return 指向新func的指针
    CFG_function * newFunction(std::string & name)
    {
        auto new_func = new CFG_function();
        functions.push_back(new_func);
        funcMap[name] = new_func;
        return new_func;
    }

    /// @brief 设置当前function
    /// @param function 变更的函数
    /// @return
    void setCurrentFunction(CFG_function * function)
    {
        currentFunction = function;
    }

    /// @brief 获取当前函数
    /// @param
    /// @return 指向当前函数的指针
    CFG_function * getCurrentFunction()
    {
        return currentFunction;
    }

    /// @brief 运行产生CFG
    /// @param file_name 文件路径
    /// @return 翻译是否成功，true：成功，false：失败
    bool run(std::string file_name);

protected:
    /// @brief 识别到函数定义语句
    /// @param line ir语句
    /// @return 翻译是否成功，true：成功，false：失败
    bool func_define(const std::string & line);

    /// @brief 识别到函数定义语句
    /// @param line ir语句
    /// @return 翻译是否成功，true：成功，false：失败
    bool label(const std::string & line);

    /// @brief 识别到跳转
    /// @param line ir语句
    /// @return 翻译是否成功，true：成功，false：失败
    bool goto_inst(const std::string & line);

    /// @brief 识别到其他语句
    /// @param line ir语句
    /// @return 翻译是否成功，true：成功，false：失败
    bool default_expr(const std::string & line);
};

#endif // CFG_H
