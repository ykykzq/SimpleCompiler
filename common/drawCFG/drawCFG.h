// 应当定义两个类：CFG_function与CFG_blcok。
// 其中CFG_block有如下参数：一个vector，存储该函数的所有CFG_blcok；一个unordered_map，保存从std::string到CFG_blcok的映射关系；一个currentBlcok，保存当前正在活动的CFG_block
// CFG_blcok类有如下参数：一个存储std::string的vector，存储该block所有的入口；一个存储std::string的vector，存储该函数所有的出口；一个存储std::string的vector，存储所有的ir指令
// 该头文件还定义一个全局变量： CFG_currentFunction，保存当前正在活动的CFG_function
#ifndef CFG_H
#define CFG_H

#include <vector>
#include <unordered_map>
#include <string>

// 前向声明
class CFG_block;

// CFG_function类
class CFG_function {
public:
    std::vector<CFG_block *> blocks;                       // 存储该函数的所有CFG_block
    std::unordered_map<std::string, CFG_block *> blockMap; // 保存从std::string到CFG_block的映射关系
    CFG_block * currentBlock;                              // 保存当前正在活动的CFG_block

    CFG_function() : currentBlock(nullptr)
    {}

    // 添加一个新的块
    void addBlock(const std::string & name, CFG_block * block)
    {
        blocks.push_back(block);
        blockMap[name] = block;
    }

    // 设置当前块
    void setCurrentBlock(const std::string & name)
    {
        auto it = blockMap.find(name);
        if (it != blockMap.end()) {
            currentBlock = it->second;
        } else {
            // 处理找不到块的情况，比如抛出异常或记录错误
            currentBlock = nullptr;
        }
    }
};

// CFG_block类
class CFG_block {
public:
    std::vector<std::string> entries;        // 存储该block所有的入口
    std::vector<std::string> exits;          // 存储该block所有的出口
    std::vector<std::string> irInstructions; // 存储所有的ir指令

    CFG_block()
    {}
};

// CFG_Manager类，管理多个CFG_function对象
class CFG_Manager {
public:
    std::vector<CFG_function *> functions; // 存储所有的CFG_function对象
    CFG_function * currentFunction;        // 当前活动的CFG_function

    CFG_Manager() : currentFunction(nullptr)
    {}

    // 添加一个新的函数
    void addFunction(CFG_function * function);

    // 设置当前函数
    void setCurrentFunction(CFG_function * function);
};

// 全局变量，保存当前正在活动的CFG_function
extern CFG_Manager CFG_manager;

#endif // CFG_H
