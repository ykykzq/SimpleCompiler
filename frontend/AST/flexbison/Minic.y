%{
#include <cstdio>
#include <cstring>

// 词法分析头文件
#include "FlexLexer.h"

// bison生成的头文件
#include "BisonParser.h"

// 抽象语法树函数定义原型头文件
#include "AST.h"

// LR分析失败时所调用函数的原型声明
void yyerror(char * msg);

%}

// 联合体声明，用于后续终结符和非终结符号属性指定使用
%union {
    class ast_node * node;

    struct digit_int_attr integer_num;
    struct digit_real_attr float_num;
    struct var_id_attr var_id;
};

// 文法的开始符号
%start  CompileUnit

// 指定文法的终结符号，<>可指定文法属性
// 对于单个字符的算符或者分隔符，在词法分析时可直返返回对应的字符即可
%token <integer_num> T_DIGIT
%token <var_id> T_ID
%token T_FUNC T_RETURN T_IF T_ELSE T_WHILE T_CONST T_INT T_VOID
%token T_BREAK T_CONTINUE

%token T_ADD T_SUB T_NOT T_MUL T_DIV T_MOD
%token T_GTH T_LTH T_AND T_OR


%type <node> CompileUnit

// 指定文法的非终结符号，<>可指定文法属性
%type <node> FuncDef
%type <node> FuncFParams
%type <node> Block

%type <node> FuncFParam
//%type <node> FuncBasicParam

%type <node> BlockItemList
%type <node> BlockItem

%type <node> Statement
%type <node> Expr
%type <node> AddExp UnaryExp LVal MulExp
%type <node> RelExp EqExp LAndExp LOrExp Cond
%type <node> PrimaryExp
%type <node> FuncRParams

%type <node> Decl
%type <node> VarDecl VarDefList VarDef InitVal
%type <node> ConstDef ConstDefList ConstDecl ConstInitVal ConstExp Btype
%type <node> Array ArrayInitVal ArrayInitValList ExpList
%type <node> ConstExpList ConstArrayInitValList ConstArrayInitVal FuncFParamArray
%%

/* 编译单元可包含若干个函数，main函数作为程序的入口，必须存在 */
CompileUnit : FuncDef {
        $$ = create_contain_node(ast_operator_type::AST_OP_COMPILE_UNIT, $1);
        ast_root = $$;
    }
    | CompileUnit FuncDef {
        $$ = insert_ast_node($1, $2);
    }
    | Decl {
        $$ = create_contain_node(ast_operator_type::AST_OP_COMPILE_UNIT, $1);
        ast_root = $$;
    }
    | CompileUnit Decl {
        $$ = insert_ast_node($1, $2);
    }
    ;

// 函数定义
FuncDef : T_VOID T_ID '(' ')' Block  {
		/* 0代表void */
        $$ = create_func_def(0, $2.lineno, $2.id, $5, nullptr);
    }
    | T_VOID T_ID '(' FuncFParams ')' Block {
        /* 0代表void */
		$$ = create_func_def(0, $2.lineno, $2.id, $6, $4);
    }
	| Btype T_ID '(' ')' Block  {
        /* 1代表int */
		$$ = create_func_def(1, $2.lineno, $2.id, $5, nullptr);
    }
    | Btype T_ID '(' FuncFParams ')' Block {
        /* 1代表int */
		$$ = create_func_def(1, $2.lineno, $2.id, $6, $4);
    }
	| T_VOID T_ID '(' ')'   ';'{
		/* 0代表void */
        $$ = create_func_def(0, $2.lineno, $2.id, nullptr);
    }
    | T_VOID T_ID '(' FuncFParams ')' ';' {
        /* 0代表void */
		$$ = create_func_def(0, $2.lineno, $2.id, $4);
    }
	| Btype T_ID '(' ')'  ';' {
        /* 1代表int */
		$$ = create_func_def(1, $2.lineno, $2.id,  nullptr);
    }
    | Btype T_ID '(' FuncFParams ')' ';' {
        /* 1代表int */
		$$ = create_func_def(1, $2.lineno, $2.id, $4);
    }
    ;

// 函数参数
FuncFParams : FuncFParam  {
        $$ = create_contain_node(ast_operator_type::AST_OP_FUNC_FORMAL_PARAMS, $1);
    }
    | FuncFParams ',' FuncFParam {
        $$ = insert_ast_node($1, $3);
    }
    ;

// 函数参数，目前只支持int，且支持数组
FuncFParam : Btype T_ID  {
		ast_node * new_node = create_func_formal_param($2.lineno, $2.id);
        $$ = new_ast_node(ast_operator_type::AST_PARAM, $1, new_node, nullptr);
    }
	/* 实际上编译器不会检查数组第一个[]内有无参数 */
	| Btype FuncFParamArray{
		$$ = new_ast_node(ast_operator_type::AST_PARAM, $1, $2, nullptr);
	}
    ;

FuncFParamArray : T_ID '[' ']'{
		ast_node * id_node = new_ast_leaf_node(var_id_attr{$1.id, $1.lineno});
		free($1.id);

		char para[2]="*";
		ast_node * para_node = new_ast_leaf_node(var_id_attr{para, $1.lineno});
		$$ = new_ast_node(ast_operator_type::AST_ARRAY,id_node, para_node, nullptr);
	}
	|
	T_ID '[' ConstExp ']'{
		ast_node * id_node = new_ast_leaf_node(var_id_attr{$1.id, $1.lineno});

		free($1.id);

		char para[2]="*";
		ast_node * para_node = new_ast_leaf_node(var_id_attr{para, $1.lineno});
		$$ = new_ast_node(ast_operator_type::AST_ARRAY,id_node, para_node, nullptr);
	}
	| FuncFParamArray '[' ConstExp ']'	{
		$$ = insert_ast_node($1, $3);
	}
	;

// 基本类型函数参数，默认整型
//FuncBasicParam : T_ID {
//        $$ = create_func_formal_param($1.lineno, $1.id,nullptr);
//    }
//    ;

// 语句块
Block : '{' '}' {
        // 语句块没有语句
        $$ = nullptr;
    }
    | '{' BlockItemList '}' {
        // 语句块含有语句
        $$ = $2;
    }
    ;

// 语句块内语句列表
BlockItemList : BlockItem {
        // 第一个左侧的孩子节点归约成Block父节点，后续语句可不断作为孩子追加到block中
        // 创建一个AST_OP_BLOCK类型的中间节点，孩子为Statement($1)
        $$ = new_ast_node(ast_operator_type::AST_OP_BLOCK, $1, nullptr);
    }
    | BlockItemList BlockItem  {
        // 采用左递归的文法产生式，可以使得Block节点在上个产生式创建，后续递归追加孩子节点
        // 请注意，不要采用右递归，左递归翻遍孩子的追加
        // BlockItem($2)作为Block($1)的孩子 
        $$ = insert_ast_node($1, $2);
    }
    ;

// 目前语句块内项目只能是语句和声明
BlockItem : Statement  {
        $$ = $1;
    }
	| Decl{
		$$ = $1;
	}
    ;

/* 语句 */
Statement : LVal '=' Expr ';' {
        // 归约到Statement时要执行的语义动作程序
        // 赋值语句，不显示值

        // 创建一个AST_OP_ASSIGN类型的中间节点，孩子为Id和Expr($3)
        $$ = new_ast_node(ast_operator_type::AST_OP_ASSIGN, $1, $3, nullptr);
    }
	| Expr ';' {
        // Expr归约到Statement时要执行的语义动作程序
        // 表达式语句，不显示表达式的值

        // 创建一个AST_OP_EXPR类型的中间节点，孩子为Expr($1)
        $$ = new_ast_node(ast_operator_type::AST_OP_EXPR, $1, nullptr);
    }
    //| Expr {
        // Expr归约到Statement时要执行的语义动作程序
        // 表达式语句，需要显示表达式的值

        // 创建一个AST_OP_EXPR_SHOW类型的中间节点，孩子为Expr($1)
    //    $$ = new_ast_node(ast_operator_type::AST_OP_EXPR_SHOW, $1, nullptr);
    //}
	| Block{
		$$ = $1;
	}
	| T_IF '(' Cond ')'Statement{
		// to do something
		$$ = new_ast_node(ast_operator_type::AST_OP_IF, $3, $5, nullptr);
	}
	| T_IF '(' Cond ')' Statement T_ELSE Statement{
		// 变量节点
		// ast_node * new_node = new_ast_node(ast_operator_type::AST_ELSE, $7, nullptr);
		ast_node * new_node = new_ast_node(ast_operator_type::AST_OP_BLOCK, $7, nullptr);
		$$ = new_ast_node(ast_operator_type::AST_OP_IF, $3, $5, new_node, nullptr);
	}
	| T_WHILE '(' Cond ')' Statement{
		$$ = new_ast_node(ast_operator_type::AST_WHILE, $3, $5, nullptr);
	}
	| T_BREAK ';'{
		$$ = new_ast_node(ast_operator_type::AST_BREAK, nullptr);
	}
	| T_CONTINUE ';'{
		$$ = new_ast_node(ast_operator_type::AST_CONTINUE, nullptr);
    }
    | T_RETURN Expr ';' {
        // 返回语句
        $$ = new_ast_node(ast_operator_type::AST_OP_RETURN_STATEMENT, $2, nullptr);
    }
	|
	T_RETURN ';' {
        // 返回语句 没有子节点代表不return
        $$ = new_ast_node(ast_operator_type::AST_OP_RETURN_STATEMENT, nullptr);
    }
    ;
/* 条件表达式 */
Cond  : LOrExp{
		$$ = new_ast_node(ast_operator_type::AST_COND, $1, nullptr);
}

Expr : AddExp {
        $$ = $1;
    }
    ;

/* 加法表达式 */
AddExp : AddExp T_ADD MulExp {
        /* Expr = Expr + MulExp */

        // 创建一个AST_OP_ADD类型的中间节点，孩子为Expr($1)和Term($3)
        $$ = new_ast_node(ast_operator_type::AST_OP_ADD, $1, $3, nullptr);
    }
    | AddExp T_SUB MulExp {
        /* Expr = Expr + MulExp */

        // 创建一个AST_OP_ADD类型的中间节点，孩子为Expr($1)和Term($3)
        $$ = new_ast_node(ast_operator_type::AST_OP_SUB, $1, $3, nullptr);
    }
	| MulExp{
		$$ = $1;
	}
    ;

/* 乘除表达式 */
MulExp : MulExp T_MUL UnaryExp {
        $$ = new_ast_node(ast_operator_type::AST_OP_MUL, $1, $3, nullptr);
    }
	|
	 MulExp T_DIV UnaryExp {
        $$ = new_ast_node(ast_operator_type::AST_OP_DIV, $1, $3, nullptr);
    }
	|
	 MulExp T_MOD UnaryExp {
        $$ = new_ast_node(ast_operator_type::AST_OP_MOD, $1, $3, nullptr);
    }
	|
	 UnaryExp {
        $$ = $1;
    }
    ;
/*关系表达式*/
RelExp : AddExp {
		$$ = $1;
	}
	|
	 RelExp T_GTH AddExp {
		$$ = new_ast_node(ast_operator_type::AST_OP_GTH, $1, $3, nullptr);
	}
	|
	 RelExp T_LTH AddExp {
		$$ = new_ast_node(ast_operator_type::AST_OP_STH, $1, $3, nullptr);
	}
	|
	 RelExp T_GTH '=' AddExp {
		$$ = new_ast_node(ast_operator_type::AST_OP_GOE, $1, $4, nullptr);
	}
	|
	 RelExp T_LTH '=' AddExp {
		$$ = new_ast_node(ast_operator_type::AST_OP_SOE, $1, $4, nullptr);
	}
	;
/*相等性表达式*/
EqExp : RelExp {
		$$ = $1;
	}
	|
	 EqExp '=' '=' RelExp {
		$$ = new_ast_node(ast_operator_type::AST_OP_EE, $1, $4, nullptr);
	}
	|
	 EqExp T_NOT '=' RelExp {
		$$ = new_ast_node(ast_operator_type::AST_OP_NE, $1, $4, nullptr);
	}
	|'('EqExp')'{
		$$ = $2;
	}
	;
/*逻辑与表达式*/
LAndExp : EqExp {
		$$ = $1;
	}
	|
	 LAndExp T_AND T_AND EqExp {
		$$ = new_ast_node(ast_operator_type::AST_OP_ANDAND, $1, $4, nullptr);
	}
	|
	 LAndExp T_AND T_AND LAndExp {
		$$ = new_ast_node(ast_operator_type::AST_OP_ANDAND, $1, $4, nullptr);
	}
	|'('LAndExp')'{
		$$ = $2;
	}
	| T_NOT LAndExp{
		$$ = new_ast_node(ast_operator_type::AST_OP_NOT, $2, nullptr);
	}
	;
/*逻辑或表达式*/
LOrExp : LAndExp {
		$$ = $1;
	}
	|
	 LOrExp T_OR T_OR LAndExp {
		$$ = new_ast_node(ast_operator_type::AST_OP_OROR, $1, $4, nullptr);
	}
	;
/*一元表达式*/
UnaryExp : PrimaryExp {
        $$ = $1;
    }
    | T_ID '(' ')' {
        // 用户自定义的不含实参的函数调用
        $$ = create_func_call($1.lineno, $1.id, nullptr);
    }
    | T_ID '(' FuncRParams ')' {
        // 用户自定义的含有实参的参数调用
        $$ = create_func_call($1.lineno, $1.id, $3);
    }
	| T_ADD UnaryExp {
		// 一元表达式
        $$ = new_ast_node(ast_operator_type::AST_OP_ADD, $2, nullptr);
	}
	| T_SUB UnaryExp {
		// 一元表达式
        $$ = new_ast_node(ast_operator_type::AST_OP_SUB, $2, nullptr);
	}
	| T_NOT UnaryExp {
		// 一元表达式
        $$ = new_ast_node(ast_operator_type::AST_OP_NOT, $2, nullptr);
	}
	;

/* 变量/常量数组 不区分类型 也就是一串a[][][] */
Array: T_ID '[' ConstExp ']'{
		ast_node * id_node = new_ast_leaf_node(var_id_attr{$1.id, $1.lineno});

		free($1.id);
		$$ = new_ast_node(ast_operator_type::AST_ARRAY,id_node, $3, nullptr);
	}
	| Array '[' ConstExp ']'	{
		$$ = insert_ast_node($1, $3);
	}
	;

/* 变量数组初始化式 类似 {{1,2,3},{4,5,6}} 或者 {1} */
ArrayInitVal: '{' ExpList '}'{
		// 变量节点
		$$ = new_ast_node(ast_operator_type::AST_ARRAY_INIT_VAL, $2, nullptr);
	}
	| '{' ArrayInitValList '}'	{
		$$ = new_ast_node(ast_operator_type::AST_ARRAY_INIT_VAL, $2, nullptr);
	}
	;

/* 类似{1},{2},{3}这样的式子  */
ArrayInitValList:  ArrayInitVal {
		$$ = new_ast_node(ast_operator_type::AST_ARRAY_INIT_VAL_LIST, $1, nullptr);
	}
	| ArrayInitValList ',' ArrayInitVal{
		$$ = insert_ast_node($1, $3);
    }
	;

/* 变量数组初始化值 表达式 类似 1,2,3 */
ExpList : Expr{
        $$ = new_ast_node(ast_operator_type::AST_EXP_LIST, $1, nullptr);
    }
    | ExpList ',' Expr{
		$$ = insert_ast_node($1, $3);
	}
	;


/* 常量数组初始化式 类似 {{1,2,3},{4,5,6}} 或者 {1} */
ConstArrayInitVal: '{' ConstExpList '}'{
		// 变量节点
		$$ = new_ast_node(ast_operator_type::AST_CONST_ARRAY_INIT_VAL, $2, nullptr);
	}
	| '{' ConstArrayInitValList '}'	{
		$$ = new_ast_node(ast_operator_type::AST_CONST_ARRAY_INIT_VAL, $2, nullptr);
	}
	;

/* 类似{1},{2},{3}这样的式子  */
ConstArrayInitValList:  ConstArrayInitVal {
		$$ = new_ast_node(ast_operator_type::AST_CONST_ARRAY_INIT_VAL_LIST, $1, nullptr);
	}
	| ConstArrayInitValList ',' ConstArrayInitVal{
		$$ = insert_ast_node($1, $3);
    }
	;

/* 常量数组初始化值 表达式 类似 1,2,3 */
ConstExpList : ConstExp{
        $$ = new_ast_node(ast_operator_type::AST_CONST_EXP_LIST, $1, nullptr);
    }
    | ConstExpList ',' ConstExp{
		$$ = insert_ast_node($1, $3);
	}
	;


Decl	: VarDecl {
	    $$ = $1;
    }
    | ConstDecl{
        $$ = $1;
    }
    ;

/*常量声明*/
ConstDecl : T_CONST Btype ConstDefList ';'{
		$$ = new_ast_node(ast_operator_type::AST_VAR_CONST_DECL, $2, $3, nullptr);
	}
ConstDefList : ConstDef{
		$$ = new_ast_node(ast_operator_type::AST_VAR_CONST_DEF, $1, nullptr);
	}
	| ConstDefList ',' ConstDef{
		$$ = insert_ast_node($1 , $3);
	}
	;

/* 常数定义 暂时不考虑数组*/
ConstDef : T_ID  '=' ConstInitVal {
		// 变量节点
		ast_node * id_node = new_ast_leaf_node(var_id_attr{$1.id, $1.lineno});

		free($1.id);
		$$ = new_ast_node(ast_operator_type::AST_OP_ASSIGN, id_node, $3, nullptr);
	}
	| Array '=' ConstArrayInitVal{
		$$ = new_ast_node(ast_operator_type::AST_OP_ASSIGN, $1, $3, nullptr);
	}
	;
/*变量表达式*/
ConstExp : AddExp{
	    $$ = $1;
    }
    ;
/*常量初值 暂时不考虑数组*/
ConstInitVal : ConstExp {
        $$ = $1;
    }
    ;
/* 变量声明 */
VarDecl : Btype VarDefList ';'{
		$$ = new_ast_node(ast_operator_type::AST_VAR_VAR_DECL, $1, $2, nullptr);
	}
	;
/* 变量定义 */
VarDefList :VarDef{
		$$ = new_ast_node(ast_operator_type::AST_VAR_VAR_DEF, $1, nullptr);
	}
	| VarDefList ',' VarDef{
		$$ = insert_ast_node($1 , $3);
	}
	;

VarDef : T_ID  '=' InitVal {
		// 变量节点
		ast_node * id_node = new_ast_leaf_node(var_id_attr{$1.id, $1.lineno});

		free($1.id);
		$$ = new_ast_node(ast_operator_type::AST_OP_ASSIGN, id_node, $3, nullptr);
	}
	|
	T_ID {
		// 变量节点
        ast_node * id_node = new_ast_leaf_node(var_id_attr{$1.id, $1.lineno});

        free($1.id);
		$$ = new_ast_node(ast_operator_type::AST_OP_ASSIGN, id_node, nullptr);
	}
	| Array '=' ArrayInitVal {
		// 变量节点

		$$ = new_ast_node(ast_operator_type::AST_OP_ASSIGN, $1, $3, nullptr);
	}
	| Array {
		// 变量节点

		$$ = new_ast_node(ast_operator_type::AST_OP_ASSIGN, $1, nullptr);
	}
	;
/*变量初始化式子*/
InitVal : Expr{
		/* 可以是多种式子 */
		$$ = $1;
	}
	;


/*基本类型*/
Btype : T_INT{
		$$ = new_ast_node(ast_operator_type::AST_TYPE_INT, nullptr);
	}
	;

PrimaryExp :  '(' Expr ')' {
        /* PrimaryExp = Expr */
        $$ = $2;
    }
    | T_DIGIT {
        // 无符号整数识别

        // 终结符作为抽象语法树的叶子节点进行创建
        $$ = new_ast_leaf_node(digit_int_attr{$1.val, $1.lineno});
    }
    | LVal  {
        // 左值
        $$ = $1;
    }
    ;

/* 左值，暂时不支持数组 */
LVal : T_ID {
        // 终结符作为抽象语法树的叶子节点进行创建
        $$ = new_ast_leaf_node(var_id_attr{$1.id, $1.lineno});

		// 对于字符型字面量的字符串空间需要释放，因词法用到了strdup进行了字符串复制
		free($1.id);
    }
	| Array{
		// 左值
        $$ = $1;
	}
	;
/* 实参列表 */
FuncRParams : Expr {
        $$ = create_contain_node(ast_operator_type::AST_OP_FUNC_REAL_PARAMS, $1);
    }
    | FuncRParams ',' Expr {
        $$ = insert_ast_node($1, $3);
    }
    ;
%%

// 语法识别错误要调用函数的定义
void yyerror(char * msg)
{
    printf("Line %d: %s\n", yylineno, msg);
}
