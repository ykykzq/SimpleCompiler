#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "./drawCFG.h"

/// @brief 识别到函数定义语句
/// @param line ir语句
/// @return 翻译是否成功，true：成功，false：失败
bool func_define(const std::string & line)
{
    // 这里是对第一种情况的处理逻辑
    // 新建并更换当前的fuction
    auto func = new CFG_function;
    CFG_manager.addFunction(func);
    CFG_manager.setCurrentFunction(func);
    return true;
}

/// @brief 识别到函数定义语句
/// @param line ir语句
/// @return 翻译是否成功，true：成功，false：失败
bool label(const std::string & line)
{
    // 这里是默认处理逻辑
    //新建并更换当前function的block
    //并把label作为当前block的唯一索引，添加到block入口中
    return true;
}

/// @brief 识别到跳转
/// @param line ir语句
/// @return 翻译是否成功，true：成功，false：失败
bool goto_inst(const std::string & line)
{
    // 这里是默认处理逻辑
    // 取出两个label添加到出口中

    return true;
}

/// @brief 识别到其他语句
/// @param line ir语句
/// @return 翻译是否成功，true：成功，false：失败
bool default_expr(const std::string & line)
{
    // 这里是对第二种情况的处理逻辑
    //塞入到当前function的当前block里

    return true;
}

//处理ir
int main()
{
    std::ifstream file("1.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open file 1.txt" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string firstWord, secondWord;

        if (!(iss >> firstWord >> secondWord)) {
            std::cerr << "Error reading words from line: " << line << std::endl;
            continue;
        }

        if (firstWord == "define") {
            func_define(line);
        } else if (firstWord == "br" || firstWord == "bc") {
            goto_inst(line);
        } else if (firstWord.compare(0, 1, ".") == 0) {
            label(line);
        } else {
            default_expr(line);
        }
    }

    file.close();
    return 0;
}
