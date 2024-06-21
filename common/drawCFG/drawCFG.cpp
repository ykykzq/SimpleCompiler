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

/// @brief 识别到函数定义语句
/// @param line ir语句
/// @return 翻译是否成功，true：成功，false：失败
bool CFG_Generator::func_define(const std::string & line)
{
    //取出名字
    std::istringstream iss(line);
    std::string name;
    int wordCount = 0;

    while (iss >> name) {
        ++wordCount;
        if (wordCount == 3) {
            break;
        }
    }

    //取出@与(之间的函数名
    name = name.substr(1, name.find('(') - 1);
    // 新建并更换当前的fuction
    auto func = newFunction(name);
    setCurrentFunction(func);
    currentFunction->name = name;
    return true;
}

/// @brief 识别到label语句
/// @param line ir语句
/// @return 翻译是否成功，true：成功，false：失败
bool CFG_Generator::label(const std::string & line)
{

    //取出label的名字
    std::istringstream iss(line);
    std::string label_name;
    int wordCount = 0;

    while (iss >> label_name) {
        ++wordCount;
        if (wordCount == 1) {
            break;
        }
    }
    //去除label name中的第一个字符"."和最后的":""
    label_name = label_name.substr(1, label_name.find(':') - 1);

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
    auto ir_str = line.substr(1);
    getCurrentFunction()->currentBlock->irInstructions.push_back(ir_str);

    return true;
}

/// @brief 识别到跳转
/// @param line ir语句
/// @return 翻译是否成功，true：成功，false：失败
bool CFG_Generator::goto_inst(const std::string & line)
{
    // 跳转指令也去掉'\t'后塞入当前块内
    auto ir_str = line.substr(1);
    getCurrentFunction()->currentBlock->irInstructions.push_back(ir_str);

    // 取出两个label添加到出口中
    // 取出label的名字
    std::istringstream iss(line);
    std::string jump_type;

    // 区分 br 与 bc
    if (iss >> jump_type) {
        if (jump_type == "br") {
            // br，只添加一个出口
            std::istringstream iss(line);
            std::string label_name;
            int wordCount = 0;

            while (iss >> label_name) {
                ++wordCount;
                if (wordCount == 3) {
                    //去除label name中的第一个字符"."后，放进block中
                    label_name = label_name.substr(1);
                    getCurrentFunction()->currentBlock->exits.push_back(label_name);
                }
            }
        } else if (jump_type == "bc") {
            // bc，添加两个出口
            std::istringstream iss(line);
            std::string label_name;
            int wordCount = 0;

            while (iss >> label_name) {
                ++wordCount;
                if (wordCount == 4) {
                    //去除label name中的第一个字符"."和","，放进block中
                    label_name = label_name.substr(1, label_name.find(',') - 1);
                    getCurrentFunction()->currentBlock->exits.push_back(label_name);
                } else if (wordCount == 6) {
                    //去除label name中的第一个字符"."后，放进block中
                    label_name = label_name.substr(1);
                    getCurrentFunction()->currentBlock->exits.push_back(label_name);
                }
            }
        }

    } else {
        // 取出第一个单词失败
        return false;
    }
    return true;
}

/// @brief 识别到其他语句
/// @param line ir语句
/// @return 翻译是否成功，true：成功，false：失败
bool CFG_Generator::default_expr(const std::string & line)
{
    // 这里是对第二种情况的处理逻辑
    // 去除'\t'后塞入到当前function的当前block里
    auto ir_str = line.substr(1);
    getCurrentFunction()->currentBlock->irInstructions.push_back(ir_str);

    return true;
}

/// @brief 运行产生CFG
/// @param file_name 文件路径
/// @return 翻译是否成功，true：成功，false：失败
bool CFG_Generator::run(std::string file_name)
{
    std::ifstream file(file_name);
    if (!file.is_open()) {
        std::cerr << "Failed to open file" << std::endl;
        return false;
    }

    //根据首单词的不同进行不同的处理
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string firstWord;

        if (!(iss >> firstWord)) {
            std::cerr << "Error reading words from line: " << line << std::endl;
            continue;
        }

        if (firstWord == "define") {
            func_define(line);
        } else if (firstWord == "br" || firstWord == "bc") {
            goto_inst(line);
        } else if (firstWord.compare(0, 1, ".") == 0) {
            label(line);
        } else if (firstWord == "declare") {
            //忽略声明
            continue;
        } else if (firstWord == "{" || firstWord == "}") {
            //忽略花括号
            continue;
        } else {
            default_expr(line);
        }
    }

    file.close();

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
            for (const auto & ir_str: cfg_blcok->irInstructions) {
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

        // 渲染图并输出到文件
        FILE * fp = fopen(outputFile.c_str(), "w");
        gvRender(gvc, g, outputFormat.c_str(), fp);
        fclose(fp);

        // 释放资源
        gvFreeLayout(gvc, g);
        agclose(g);
        gvFreeContext(gvc);
    }

    return true;
}