/**
 * @file CalculatorRDParser.h
 * @author zenglj (zenglj@nwpu.edu.cn)
 * @brief 递归下降分析法实现的语法分析后产生抽象语法树的实现
 * @version 0.1
 * @date 2024-01-24
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <cstring>

#include "AST.h"
#include "RecursiveDescentFlex.h"
#include "RecursiveDescentParser.h"

// 定义全局变量给词法分析使用，用于填充值
RDSType rd_lval;

// 语法分析过程中的错误数目
static int errno_num = 0;

// 语法分析过程中的LookAhead，指向下一个Token
static RDTokenType lookaheadTag = RDTokenType::T_EMPTY;

// 定义两个宏，用于判断是否是对应的Token
#define _(T) || (lookaheadTag == T)
#define F(C) (lookaheadTag == C)

/// @brief lookahead指向下一个Token
static void advance()
{
    lookaheadTag = (RDTokenType) rd_flex();
}

/// @brief flag若匹配则是否向前移动
/// @param tag 是否匹配指定的Tag
/// @param flag 若未true则获取下一个Token
/// @return true：匹配，false：未匹配
static bool match(RDTokenType tag, bool flag = true)
{
    bool result = false;

    if (F(tag)) {
        result = true;

        // 若匹配，则向前获取下一个Token
        if (flag) {
            advance();
        }
    }

    return result;
}

static ast_node * expr();

/// @brief 语法错误输出
/// @param msg 错误信息字符串
static void semerror(char * msg)
{
    errno_num++;
    printf("Line(%d): %s\n", rd_line_no, msg);
}

// primaryExp: '(' expr ')' | T_DIGIT | lVal;
static ast_node * primaryExp()
{
    ast_node * node;

    if (match(T_LPAREN)) {
        // Factor -> T_LPAREN Expr T_RPAREN识别

        node = expr();

        if (!match(T_RPAREN)) {
            // 出错
            semerror("缺少右括号");
        }
    } else if (F(T_DIGIT)) {
        // Factor -> T_DIGIT识别

        node = new_ast_leaf_node(digit_int_attr{rd_lval.integer_num.val, rd_lval.integer_num.lineno});

        advance();
    } else if (F(T_ID)) {
        // Factor -> T_ID识别

        node = new_ast_leaf_node(var_id_attr{rd_lval.var_id.id, rd_lval.integer_num.lineno});

        // 对于字符型字面量的字符串空间需要释放，因词法用到了strdup进行了字符串复制
        free(rd_lval.var_id.id);

        advance();
    } else {
        // 出错
        if (F(T_SUB) _(T_ADD) _(T_RPAREN)) {
            semerror("缺少数值常量");
        } else {
            semerror("语法错误");
            advance();
        }

        // 产生一个默认的叶子节点，数值为0，能够继续分析后面的代码
        node = new_ast_leaf_node(digit_int_attr{(uint32_t) 0, rd_lval.integer_num.lineno});
    }

    return node;
}

/// @brief unaryExp: primaryExp | T_ID '(' realParamList? ')'
/// @return AST的节点
static ast_node * unaryExp()
{
    // 本函数目前只处理primaryExp
    // TODO 函数调用请自行处理，并且文法需要改造
    ast_node * node = primaryExp();

    return node;
}

/// @brief addExp -> unaryExp { T_ADD unaryExp) }
/// @return AST的节点
static ast_node * addExp()
{
    ast_node *left_node, *right_node;

    left_node = unaryExp();

    // 闭包{ T_ADD Term }通过循环识别
    // TODO 减法请自行增加
    while (F(T_ADD)) {

        // 取下一个Token
        advance();

        // 这里只处理加法运算
        right_node = unaryExp();

        // 创建加法节点
        left_node = new_ast_node(ast_operator_type::AST_OP_ADD, left_node, right_node, nullptr);
    }

    return left_node;
}

/// @brief expr -> addExp
/// @return AST的节点
static ast_node * expr()
{
    return addExp();
}

/// @brief assignstatement  -> Expr (T_ASSIGN Expr T_SEMICOLON | T_SEMICOLON | eps)
/// @return AST的节点
static ast_node * assignstatement()
{
    ast_node *left_node, *right_node;

    left_node = expr();

    if (match(T_ASSIGN)) {

        // 如果是等号，则说明是赋值语句，这时要求左侧的变量必须是左值，也就是变量
        if (left_node->node_type == ast_operator_type::AST_OP_LEAF_VAR_ID) {

            // 合法的赋值左侧

            right_node = expr();

            if (!F(T_ERR) && !match(T_SEMICOLON)) {
                semerror("赋值语句后没有分号");
            }

            left_node = new_ast_node(ast_operator_type::AST_OP_ASSIGN, left_node, right_node, nullptr);
        } else {

            // 非法的赋值右侧
            semerror("赋值运算符的左侧不是变量名");

            return left_node;
        }
    } else if (match(T_SEMICOLON)) {

        // 不显示值的表达式语句
        left_node = new_ast_node(ast_operator_type::AST_OP_EXPR, left_node, nullptr);
    } else {

        // 要显示值的表达式语句
        left_node = new_ast_node(ast_operator_type::AST_OP_EXPR_SHOW, left_node, nullptr);
    }

    return left_node;
}

/// @brief returnstatement -> T_RETURN expr ';'
/// @return AST的节点
static ast_node * returnstatement()
{
    ast_node * expr_node = expr();

    if (!match(T_SEMICOLON)) {
        // 返回语句后没有分号
        semerror("返回语句后没有分号");
    }

    return new_ast_node(ast_operator_type::AST_OP_RETURN_STATEMENT, expr_node, nullptr);
}

/// @brief statement  -> assignstatement | returnstatement
/// @return AST的节点
static ast_node * statement()
{
    if (F(T_RETURN)) {
        return returnstatement();
    } else {
        return assignstatement();
    }
}

// compileUnit: (statement | funcDef)+;
static void compileUnit()
{
    // 创建AST的根节点
    ast_root = create_contain_node(ast_operator_type::AST_OP_COMPILE_UNIT, nullptr);

    for (;;) {

        // TODO 请自行实现函数定义的识别

        if (F(T_LPAREN) _(T_DIGIT) _(T_ID) _(T_RETURN)) {
            ast_node * statement_node = statement();
            // 加入到父节点中
            ast_root->sons.push_back(statement_node);
            statement_node->parent = ast_root;
        } else if (F(T_EOF)) {
            // 文件解析完毕
            break;
        } else {
            // 这里发现错误
            break;
        }
    }
}

/// @brief 进入语法分析，若成功则生成抽象语法树，否则返回错误，输出错误信息
/// @return 0: 成功 -1:失败
int rd_parse()
{
    // 没有错误信息
    errno_num = 0;

    // lookahead指向第一个Token
    advance();

    compileUnit();

    // 如果有错误信息，则返回-1，否则返回0
    if (errno_num != 0) {
        return -1;
    }

    return 0;
}
