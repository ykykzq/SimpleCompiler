/**
 * @file CalculatorRDFlex.cpp
 * @author zenglj (zenglj@nwpu.edu.cn)
 * @brief 词法分析的手动实现源文件
 * @version 0.1
 * @date 2024-01-24
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <cctype>
#include <cstdio>
#include <cstring>
#include <string>

#include "RecursiveDescentParser.h"
#include "Common.h"

/// @brief 词法分析的行号信息
int rd_line_no = 1;

/// @brief 输入源文件指针
FILE * rd_filein;

/// @brief 关键字与Token类别的数据结构
struct KeywordToken {
    std::string name;
    enum RDTokenType type;
};

/// @brief  关键字与Token对应表
static KeywordToken allKeywords[] = {
    {"function", RDTokenType::T_FUNC},
    {"return", RDTokenType::T_RETURN},
};

/// @brief 在标识符中检查是否时关键字，若是关键字则返回对应关键字的Token，否则返回T_ID
/// @param id 标识符
/// @return Token
static RDTokenType getKeywordToken(std::string id)
{
    for (auto & keyword: allKeywords) {
        if (keyword.name == id) {
            return keyword.type;
        }
    }

    return RDTokenType::T_ID;
}

/// @brief 词法文法，获取下一个Token
/// @return  Token，值保存在rd_lval中
int rd_flex()
{
    int c;

    /* Skip white space. */
    while ((c = fgetc(rd_filein)) == ' ' || c == '\t' || c == '\n') {

        // TODO 请支持Linux/Windows/Mac系统的行号分析
        if (c == '\n') {
            rd_line_no++;
        }
    }

    // file end
    if (c == EOF) {
        /* Return end-of-input. */
        return RDTokenType::T_EOF;
    }

    // TODO 请自行实现删除源文件中的注释，含单行注释和多行注释等

    /* Process numbers. */
    if (isdigit(c)) {

        // 识别无符号数，这里只处理正整数或者0
        // 0开头的整数这里也识别成了10进制整数，请注意

        rd_lval.integer_num.lineno = rd_line_no;
        rd_lval.integer_num.val = c - '0';

        // 最长匹配，直到非数字结束
        while (isdigit(c = fgetc(rd_filein))) {
            rd_lval.integer_num.val = rd_lval.integer_num.val * 10 + c - '0';
        }

        // 多读的字符回退
        ungetc(c, rd_filein);

        c = RDTokenType::T_DIGIT;
    } else if (c == '-') {
        // 识别字符-
        c = RDTokenType::T_SUB;
    } else if (c == '+') {
        // 识别字符+
        c = RDTokenType::T_ADD;
    } else if (c == '(') {
        // 识别字符(
        c = RDTokenType::T_LPAREN;
    } else if (c == ')') {
        // 识别字符)
        c = RDTokenType::T_RPAREN;
    } else if (c == '=') {
        // 识别字符=
        c = RDTokenType::T_ASSIGN;
    } else if (c == ';') {
        // 识别字符;
        c = RDTokenType::T_SEMICOLON;
    } else if (isLetterUnderLine(c)) {
        // 识别标识符，包含关键字/保留字或自定义标识符

        // 最长匹配标识符
        std::string name;

        do {
            // 记录字符
            name.push_back(c);
            c = fgetc(rd_filein);
        } while (isLetterDigitalUnderLine(c));

        // 多读的字符恢复，下次可继续读到该字符
        ungetc(c, rd_filein);

        // 检查是否是关键字，若是则返回对应的Token，否则返回T_ID
        c = getKeywordToken(name);
        if (c == RDTokenType::T_ID) {

            // 设置ID的值
            rd_lval.var_id.id = strdup(name.c_str());

            // 设置行号
            rd_lval.var_id.lineno = rd_line_no;
        }
    } else {
        printf("Line(%d): Invalid char %c\n", rd_line_no, c);
        c = RDTokenType::T_ERR;
    }

    /* Return a single char. */
    return c;
}
