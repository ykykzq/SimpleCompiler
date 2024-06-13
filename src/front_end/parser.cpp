/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"


#include "../../include/ast.h"
#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
#include <string>

#define YYERROR_VERBOSE true
#define YYDEBUG 1

extern ast::Root *ast_root; // the root node of final AST
extern int yydebug;
extern int yylex();
extern int yylex_destroy();
extern int yyget_lineno();
extern std::unordered_map<std::string, std::unordered_set<ast::FunctionCall*>> called_func_map;


void yyerror(const char *s) {
     std::printf("Error(line: %d): %s\n", yyget_lineno(), s); 
     yylex_destroy(); 
     if (!yydebug) std::exit(1); 
}


#line 99 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ADD = 3,                        /* ADD  */
  YYSYMBOL_SUB = 4,                        /* SUB  */
  YYSYMBOL_NOT = 5,                        /* NOT  */
  YYSYMBOL_MUL = 6,                        /* MUL  */
  YYSYMBOL_DIV = 7,                        /* DIV  */
  YYSYMBOL_MOD = 8,                        /* MOD  */
  YYSYMBOL_LT = 9,                         /* LT  */
  YYSYMBOL_LE = 10,                        /* LE  */
  YYSYMBOL_GT = 11,                        /* GT  */
  YYSYMBOL_GE = 12,                        /* GE  */
  YYSYMBOL_EQ = 13,                        /* EQ  */
  YYSYMBOL_NE = 14,                        /* NE  */
  YYSYMBOL_AND = 15,                       /* AND  */
  YYSYMBOL_OR = 16,                        /* OR  */
  YYSYMBOL_ASSIGN = 17,                    /* ASSIGN  */
  YYSYMBOL_LPAREN = 18,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 19,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 20,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 21,                    /* RBRACE  */
  YYSYMBOL_LSQUARE = 22,                   /* LSQUARE  */
  YYSYMBOL_RSQUARE = 23,                   /* RSQUARE  */
  YYSYMBOL_COMMA = 24,                     /* COMMA  */
  YYSYMBOL_SEMI = 25,                      /* SEMI  */
  YYSYMBOL_IF = 26,                        /* IF  */
  YYSYMBOL_ELSE = 27,                      /* ELSE  */
  YYSYMBOL_WHILE = 28,                     /* WHILE  */
  YYSYMBOL_FOR = 29,                       /* FOR  */
  YYSYMBOL_BREAK = 30,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 31,                  /* CONTINUE  */
  YYSYMBOL_RETURN = 32,                    /* RETURN  */
  YYSYMBOL_CONST = 33,                     /* CONST  */
  YYSYMBOL_INT = 34,                       /* INT  */
  YYSYMBOL_VOID = 35,                      /* VOID  */
  YYSYMBOL_IDENT = 36,                     /* IDENT  */
  YYSYMBOL_NUMBER = 37,                    /* NUMBER  */
  YYSYMBOL_YYACCEPT = 38,                  /* $accept  */
  YYSYMBOL_Root = 39,                      /* Root  */
  YYSYMBOL_CompUnit = 40,                  /* CompUnit  */
  YYSYMBOL_Decl = 41,                      /* Decl  */
  YYSYMBOL_ConstDecl = 42,                 /* ConstDecl  */
  YYSYMBOL_BType = 43,                     /* BType  */
  YYSYMBOL_ConstDef = 44,                  /* ConstDef  */
  YYSYMBOL_ConstDefOne = 45,               /* ConstDefOne  */
  YYSYMBOL_InitVal = 46,                   /* InitVal  */
  YYSYMBOL_ConstDefArray = 47,             /* ConstDefArray  */
  YYSYMBOL_ArrayIdent = 48,                /* ArrayIdent  */
  YYSYMBOL_InitValArray = 49,              /* InitValArray  */
  YYSYMBOL_InitValArrayList = 50,          /* InitValArrayList  */
  YYSYMBOL_VarDecl = 51,                   /* VarDecl  */
  YYSYMBOL_Def = 52,                       /* Def  */
  YYSYMBOL_DefOne = 53,                    /* DefOne  */
  YYSYMBOL_DefArray = 54,                  /* DefArray  */
  YYSYMBOL_FuncDef = 55,                   /* FuncDef  */
  YYSYMBOL_FuncFParamList = 56,            /* FuncFParamList  */
  YYSYMBOL_FuncFParam = 57,                /* FuncFParam  */
  YYSYMBOL_FuncFParamOne = 58,             /* FuncFParamOne  */
  YYSYMBOL_FuncFParamArray = 59,           /* FuncFParamArray  */
  YYSYMBOL_Block = 60,                     /* Block  */
  YYSYMBOL_BlockItemList = 61,             /* BlockItemList  */
  YYSYMBOL_BlockItem = 62,                 /* BlockItem  */
  YYSYMBOL_Stmt = 63,                      /* Stmt  */
  YYSYMBOL_AssignStmt = 64,                /* AssignStmt  */
  YYSYMBOL_IfStmt = 65,                    /* IfStmt  */
  YYSYMBOL_WhileStmt = 66,                 /* WhileStmt  */
  YYSYMBOL_ReturnStmt = 67,                /* ReturnStmt  */
  YYSYMBOL_Exp = 68,                       /* Exp  */
  YYSYMBOL_Cond = 69,                      /* Cond  */
  YYSYMBOL_LVal = 70,                      /* LVal  */
  YYSYMBOL_PrimaryExp = 71,                /* PrimaryExp  */
  YYSYMBOL_UnaryExp = 72,                  /* UnaryExp  */
  YYSYMBOL_FuncCall = 73,                  /* FuncCall  */
  YYSYMBOL_FuncRParamList = 74,            /* FuncRParamList  */
  YYSYMBOL_MulExp = 75,                    /* MulExp  */
  YYSYMBOL_AddExp = 76,                    /* AddExp  */
  YYSYMBOL_RelExp = 77,                    /* RelExp  */
  YYSYMBOL_EqExp = 78,                     /* EqExp  */
  YYSYMBOL_LAndExp = 79,                   /* LAndExp  */
  YYSYMBOL_LOrExp = 80,                    /* LOrExp  */
  YYSYMBOL_Ident = 81,                     /* Ident  */
  YYSYMBOL_Number = 82,                    /* Number  */
  YYSYMBOL_EqOp = 83,                      /* EqOp  */
  YYSYMBOL_RelOp = 84,                     /* RelOp  */
  YYSYMBOL_AddOp = 85,                     /* AddOp  */
  YYSYMBOL_MulOp = 86,                     /* MulOp  */
  YYSYMBOL_UnaryOp = 87                    /* UnaryOp  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   232

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  176

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   100,   100,   106,   110,   114,   118,   124,   125,   128,
     132,   138,   141,   142,   145,   150,   153,   158,   162,   168,
     171,   179,   183,   187,   191,   197,   201,   207,   208,   211,
     214,   219,   222,   228,   231,   234,   237,   243,   247,   253,
     254,   257,   262,   270,   276,   279,   284,   288,   294,   295,
     301,   302,   303,   304,   305,   308,   311,   314,   317,   322,
     327,   331,   337,   344,   347,   353,   356,   359,   362,   367,
     370,   373,   378,   379,   382,   387,   391,   397,   401,   407,
     408,   413,   414,   419,   420,   425,   426,   431,   432,   437,
     442,   447,   452,   457,   458,   461,   462,   463,   464,   467,
     468,   471,   472,   473,   476,   477,   478
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ADD", "SUB", "NOT",
  "MUL", "DIV", "MOD", "LT", "LE", "GT", "GE", "EQ", "NE", "AND", "OR",
  "ASSIGN", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LSQUARE", "RSQUARE",
  "COMMA", "SEMI", "IF", "ELSE", "WHILE", "FOR", "BREAK", "CONTINUE",
  "RETURN", "CONST", "INT", "VOID", "IDENT", "NUMBER", "$accept", "Root",
  "CompUnit", "Decl", "ConstDecl", "BType", "ConstDef", "ConstDefOne",
  "InitVal", "ConstDefArray", "ArrayIdent", "InitValArray",
  "InitValArrayList", "VarDecl", "Def", "DefOne", "DefArray", "FuncDef",
  "FuncFParamList", "FuncFParam", "FuncFParamOne", "FuncFParamArray",
  "Block", "BlockItemList", "BlockItem", "Stmt", "AssignStmt", "IfStmt",
  "WhileStmt", "ReturnStmt", "Exp", "Cond", "LVal", "PrimaryExp",
  "UnaryExp", "FuncCall", "FuncRParamList", "MulExp", "AddExp", "RelExp",
  "EqExp", "LAndExp", "LOrExp", "Ident", "Number", "EqOp", "RelOp",
  "AddOp", "MulOp", "UnaryOp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-145)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      69,    -1,  -145,    18,    56,    69,  -145,    22,    18,    75,
    -145,    18,  -145,    79,  -145,  -145,  -145,    18,  -145,    26,
    -145,  -145,  -145,    19,    18,  -145,  -145,  -145,  -145,    27,
      38,    -5,  -145,    20,   195,   195,     4,   195,  -145,    40,
      20,   195,    73,    18,    39,  -145,  -145,    85,   151,  -145,
    -145,  -145,  -145,   195,  -145,    86,    87,  -145,  -145,  -145,
    -145,   129,    23,    49,  -145,   195,  -145,    23,    73,    53,
      92,  -145,  -145,    48,  -145,   101,    73,    -1,   195,  -145,
    -145,  -145,    68,    95,  -145,  -145,  -145,  -145,   195,  -145,
    -145,   195,   178,  -145,  -145,    73,  -145,  -145,  -145,   106,
     108,   102,   107,   186,  -145,    18,  -145,   113,  -145,  -145,
    -145,  -145,  -145,  -145,   115,   125,   134,  -145,  -145,   135,
    -145,   157,  -145,  -145,   129,  -145,  -145,    64,  -145,   195,
     195,  -145,  -145,  -145,   123,  -145,  -145,  -145,   195,  -145,
    -145,  -145,  -145,  -145,   195,   140,    23,   110,    51,   149,
     147,   146,  -145,   142,  -145,   148,  -145,  -145,  -145,  -145,
     195,  -145,  -145,   195,   195,   195,   148,  -145,   143,    23,
     110,    51,   149,  -145,   148,  -145
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    11,     0,     0,     2,     3,     0,     0,     0,
       5,     0,    91,     0,     1,     4,     6,     0,     7,    31,
      25,    27,    28,    29,     0,     8,     9,    12,    13,     0,
       0,     0,    10,     0,     0,     0,     0,     0,    26,    29,
       0,     0,     0,     0,     0,    37,    39,    40,     0,    32,
     104,   105,   106,     0,    92,    68,     0,    71,    72,    79,
      74,    81,    65,    67,    70,     0,    30,    15,     0,     0,
       0,    16,    14,     0,    34,    41,     0,     0,     0,    19,
      23,    21,     0,     0,    18,   101,   102,   103,     0,    99,
     100,     0,     0,    73,    36,     0,    17,    44,    57,     0,
       0,     0,     0,     0,    49,     0,    54,     0,    46,    48,
      50,    51,    52,    53,     0,    71,     0,    33,    38,     0,
      20,     0,    69,    80,    82,    75,    77,     0,    35,     0,
       0,    55,    56,    63,     0,    45,    47,    58,     0,    42,
      43,    24,    22,    76,     0,     0,    83,    85,    87,    89,
      66,     0,    64,     0,    78,     0,    97,    98,    95,    96,
       0,    93,    94,     0,     0,     0,     0,    59,    60,    84,
      86,    88,    90,    62,     0,    61
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -145,  -145,  -145,    91,  -145,     2,   169,  -145,   -20,  -145,
       8,   -31,  -145,  -145,   168,  -145,  -145,   190,   165,   126,
    -145,  -145,   -34,  -145,    98,  -144,  -145,  -145,  -145,  -145,
     -33,    72,   -68,  -145,   -53,  -145,  -145,   116,   -35,    43,
      44,    45,  -145,     7,  -145,  -145,  -145,  -145,  -145,  -145
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,     5,   104,     7,    43,    26,    27,    66,    28,
      55,    49,    82,     9,    20,    21,    22,    10,    44,    45,
      46,    47,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   145,    57,    58,    59,    60,   127,    61,    62,   147,
     148,   149,   150,    63,    64,   163,   160,    91,    88,    65
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      67,    56,     8,    11,    70,   115,    67,     8,    74,    71,
      13,   168,    93,    67,    42,    23,    19,    81,    30,    29,
      83,    72,   173,    68,    30,    29,    89,    90,    80,     2,
     175,    39,    19,     2,    94,   123,    35,    36,     2,   115,
      48,    37,   117,    33,    40,   119,    17,    18,    34,    34,
      75,    50,    51,    52,    12,    41,    14,    35,    76,   126,
      37,   128,    37,    77,   161,   162,    53,    92,    73,    97,
     134,    37,    95,    98,    99,   105,   100,    77,   101,   102,
     103,     1,     2,   143,    12,    54,    67,   115,   144,   120,
     142,     6,   121,    73,   146,   146,    15,    31,   115,    24,
      25,   141,     1,     2,     3,   153,   115,    78,    34,   105,
      84,   154,    39,    19,   122,    96,    50,    51,    52,   156,
     157,   158,   159,   116,   129,   169,   130,   131,   146,   146,
     146,    53,   132,    73,   135,    85,    86,    87,    98,    99,
     137,   100,   138,   101,   102,   103,     1,     2,   152,    12,
      54,    50,    51,    52,    50,    51,    52,   139,   140,   155,
      50,    51,    52,   165,   164,   166,    53,   167,    73,    53,
     174,    48,    79,    98,    99,    53,   100,    48,   101,   102,
     103,    50,    51,    52,    12,    54,    32,    12,    54,    50,
      51,    52,    38,    12,    54,    16,    53,   125,    50,    51,
      52,    69,   151,   118,    53,   136,   170,   124,   171,     0,
     172,   133,     0,    53,    12,    54,     0,     0,     0,     0,
       0,     0,    12,    54,     0,     0,     0,     0,     0,     0,
       0,    12,    54
};

static const yytype_int16 yycheck[] =
{
      35,    34,     0,     1,    37,    73,    41,     5,    42,    40,
       3,   155,    65,    48,    19,     8,     8,    48,    11,    11,
      53,    41,   166,    19,    17,    17,     3,     4,    48,    34,
     174,    24,    24,    34,    68,    88,    17,    18,    34,   107,
      20,    22,    76,    17,    17,    78,    24,    25,    22,    22,
      43,     3,     4,     5,    36,    17,     0,    17,    19,    92,
      22,    95,    22,    24,    13,    14,    18,    18,    20,    21,
     103,    22,    19,    25,    26,    73,    28,    24,    30,    31,
      32,    33,    34,    19,    36,    37,   121,   155,    24,    21,
     121,     0,    24,    20,   129,   130,     5,    18,   166,    24,
      25,   121,    33,    34,    35,   138,   174,    22,    22,   107,
      23,   144,   105,   105,    19,    23,     3,     4,     5,     9,
      10,    11,    12,    22,    18,   160,    18,    25,   163,   164,
     165,    18,    25,    20,    21,     6,     7,     8,    25,    26,
      25,    28,    17,    30,    31,    32,    33,    34,    25,    36,
      37,     3,     4,     5,     3,     4,     5,    23,    23,    19,
       3,     4,     5,    16,    15,    19,    18,    25,    20,    18,
      27,    20,    21,    25,    26,    18,    28,    20,    30,    31,
      32,     3,     4,     5,    36,    37,    17,    36,    37,     3,
       4,     5,    24,    36,    37,     5,    18,    19,     3,     4,
       5,    36,   130,    77,    18,   107,   163,    91,   164,    -1,
     165,    25,    -1,    18,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    37
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    33,    34,    35,    39,    40,    41,    42,    43,    51,
      55,    43,    36,    81,     0,    41,    55,    24,    25,    48,
      52,    53,    54,    81,    24,    25,    44,    45,    47,    48,
      81,    18,    44,    17,    22,    17,    18,    22,    52,    81,
      17,    17,    19,    43,    56,    57,    58,    59,    20,    49,
       3,     4,     5,    18,    37,    48,    68,    70,    71,    72,
      73,    75,    76,    81,    82,    87,    46,    76,    19,    56,
      68,    49,    46,    20,    60,    81,    19,    24,    22,    21,
      46,    49,    50,    68,    23,     6,     7,     8,    86,     3,
       4,    85,    18,    72,    60,    19,    23,    21,    25,    26,
      28,    30,    31,    32,    41,    43,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    70,    22,    60,    57,    68,
      21,    24,    19,    72,    75,    19,    68,    74,    60,    18,
      18,    25,    25,    25,    68,    21,    62,    25,    17,    23,
      23,    46,    49,    19,    24,    69,    76,    77,    78,    79,
      80,    69,    25,    68,    68,    19,     9,    10,    11,    12,
      84,    13,    14,    83,    15,    16,    19,    25,    63,    76,
      77,    78,    79,    63,    27,    63
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    40,    40,    40,    40,    41,    41,    42,
      42,    43,    44,    44,    45,    46,    47,    48,    48,    49,
      49,    50,    50,    50,    50,    51,    51,    52,    52,    53,
      53,    54,    54,    55,    55,    55,    55,    56,    56,    57,
      57,    58,    59,    59,    60,    60,    61,    61,    62,    62,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    64,
      65,    65,    66,    67,    67,    68,    69,    70,    70,    71,
      71,    71,    72,    72,    72,    73,    73,    74,    74,    75,
      75,    76,    76,    77,    77,    78,    78,    79,    79,    80,
      80,    81,    82,    83,    83,    84,    84,    84,    84,    85,
      85,    86,    86,    86,    87,    87,    87
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     2,     2,     3,
       3,     1,     1,     1,     3,     1,     3,     4,     4,     2,
       3,     1,     3,     1,     3,     2,     3,     1,     1,     1,
       3,     1,     3,     6,     5,     6,     5,     1,     3,     1,
       1,     2,     4,     4,     2,     3,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     1,     2,     4,
       5,     7,     5,     2,     3,     1,     1,     1,     1,     3,
       1,     1,     1,     2,     1,     3,     4,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Root: CompUnit  */
#line 100 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
               {
    (yyval.root)=(yyvsp[0].root);
    ast_root=(yyval.root);
}
#line 1313 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 3: /* CompUnit: Decl  */
#line 106 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
               {
    (yyval.root)=new ast::Root(yyget_lineno());
    (yyval.root)->compunit_list_.push_back(static_cast<ast::CompUnit*>((yyvsp[0].declare)));
}
#line 1322 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 4: /* CompUnit: CompUnit Decl  */
#line 110 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                    {
        (yyval.root)=(yyvsp[-1].root);
        (yyval.root)->compunit_list_.push_back(static_cast<ast::CompUnit*>((yyvsp[0].declare)));
    }
#line 1331 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 5: /* CompUnit: FuncDef  */
#line 114 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
              {
        (yyval.root)=new ast::Root(yyget_lineno());
        (yyval.root)->compunit_list_.push_back(static_cast<ast::CompUnit*>((yyvsp[0].funcdef)));
    }
#line 1340 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 6: /* CompUnit: CompUnit FuncDef  */
#line 118 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                       {
        (yyval.root)=(yyvsp[-1].root);
        (yyval.root)->compunit_list_.push_back(static_cast<ast::CompUnit*>((yyvsp[0].funcdef)));
    }
#line 1349 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 9: /* ConstDecl: CONST BType ConstDef  */
#line 128 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                                {
    (yyval.declare)=new ast::DeclareStatement(yyget_lineno(), (yyvsp[-1].token));
    (yyval.declare)->define_list_.push_back((yyvsp[0].define));
}
#line 1358 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 10: /* ConstDecl: ConstDecl COMMA ConstDef  */
#line 132 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                               {
        (yyval.declare)=(yyvsp[-2].declare);
        (yyval.declare)->define_list_.push_back((yyvsp[0].define));
    }
#line 1367 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 14: /* ConstDefOne: Ident ASSIGN InitVal  */
#line 145 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                                  {
    (yyval.define)=static_cast<ast::Define*>(new ast::VariableDefineWithInit(yyget_lineno(), *(yyvsp[-2].ident),*(yyvsp[0].expr),true));
}
#line 1375 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 16: /* ConstDefArray: ArrayIdent ASSIGN InitValArray  */
#line 153 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                                              {
    (yyval.define)=static_cast<ast::Define*>(new ast::ArrayDefineWithInit(yyget_lineno(), *(yyvsp[-2].array_ident),*(yyvsp[0].array_initval),true));
}
#line 1383 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 17: /* ArrayIdent: Ident LSQUARE Exp RSQUARE  */
#line 158 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                                      {
    (yyval.array_ident)=new ast::ArrayIdentifier(yyget_lineno(), *(yyvsp[-3].ident));
    (yyval.array_ident)->shape_list_.push_back(std::shared_ptr<ast::Expression>((yyvsp[-1].expr)));
}
#line 1392 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 18: /* ArrayIdent: ArrayIdent LSQUARE Exp RSQUARE  */
#line 162 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                                     {
        (yyval.array_ident)=(yyvsp[-3].array_ident);
        (yyval.array_ident)->shape_list_.push_back(std::shared_ptr<ast::Expression>((yyvsp[-1].expr)));
    }
#line 1401 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 19: /* InitValArray: LBRACE RBRACE  */
#line 168 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                            {
    (yyval.array_initval)=new ast::ArrayInitVal(yyget_lineno(), false, nullptr);
}
#line 1409 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 20: /* InitValArray: LBRACE InitValArrayList RBRACE  */
#line 171 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                                     {
        (yyval.array_initval)=new ast::ArrayInitVal(yyget_lineno(), false, nullptr);
        (yyval.array_initval)->initval_list_.swap(*(yyvsp[-1].array_initval_list));
        delete (yyvsp[-1].array_initval_list);
    }
#line 1419 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 21: /* InitValArrayList: InitValArray  */
#line 179 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                               {
    (yyval.array_initval_list)=new std::vector<ast::ArrayInitVal*>;
    (yyval.array_initval_list)->push_back((yyvsp[0].array_initval));
}
#line 1428 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 22: /* InitValArrayList: InitValArrayList COMMA InitValArray  */
#line 183 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                                          {
        (yyval.array_initval_list)=(yyvsp[-2].array_initval_list);
        (yyval.array_initval_list)->push_back((yyvsp[0].array_initval));
    }
#line 1437 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 23: /* InitValArrayList: InitVal  */
#line 187 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
              {
        (yyval.array_initval_list)=new std::vector<ast::ArrayInitVal*>;
        (yyval.array_initval_list)->push_back(new ast::ArrayInitVal(yyget_lineno(), true, (yyvsp[0].expr)));
    }
#line 1446 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 24: /* InitValArrayList: InitValArrayList COMMA InitVal  */
#line 191 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                                     {
        (yyval.array_initval_list)=(yyvsp[-2].array_initval_list);
        (yyval.array_initval_list)->push_back(new ast::ArrayInitVal(yyget_lineno(), true, (yyvsp[0].expr)));
    }
#line 1455 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 25: /* VarDecl: BType Def  */
#line 197 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                   {
    (yyval.declare)=new ast::DeclareStatement(yyget_lineno(), (yyvsp[-1].token));
    (yyval.declare)->define_list_.push_back((yyvsp[0].define));
}
#line 1464 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 26: /* VarDecl: VarDecl COMMA Def  */
#line 201 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                        {
        (yyval.declare)=(yyvsp[-2].declare);
        (yyval.declare)->define_list_.push_back((yyvsp[0].define));
    }
#line 1473 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 29: /* DefOne: Ident  */
#line 211 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
              {
    (yyval.define)=static_cast<ast::Define*>(new ast::VariableDefine(yyget_lineno(), *(yyvsp[0].ident)));
}
#line 1481 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 30: /* DefOne: Ident ASSIGN InitVal  */
#line 214 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                           {
        (yyval.define)=static_cast<ast::Define*>(new ast::VariableDefineWithInit(yyget_lineno(), *(yyvsp[-2].ident),*(yyvsp[0].expr),false));
    }
#line 1489 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 31: /* DefArray: ArrayIdent  */
#line 219 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                     {
    (yyval.define)=static_cast<ast::Define*>(new ast::ArrayDefine(yyget_lineno(), *(yyvsp[0].array_ident)));
}
#line 1497 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 32: /* DefArray: ArrayIdent ASSIGN InitValArray  */
#line 222 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                                     {
        (yyval.define)=static_cast<ast::Define*>(new ast::ArrayDefineWithInit(yyget_lineno(), *(yyvsp[-2].array_ident),*(yyvsp[0].array_initval),false));
    }
#line 1505 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 33: /* FuncDef: VOID Ident LPAREN FuncFParamList RPAREN Block  */
#line 228 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                                                       {
    (yyval.funcdef)=new ast::FunctionDefine(yyget_lineno(), (yyvsp[-5].token),*(yyvsp[-4].ident),*(yyvsp[-2].funcfparams),*(yyvsp[0].block));
}
#line 1513 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 34: /* FuncDef: VOID Ident LPAREN RPAREN Block  */
#line 231 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                                     {
        (yyval.funcdef)=new ast::FunctionDefine(yyget_lineno(), (yyvsp[-4].token), *(yyvsp[-3].ident), *(new ast::FunctionFormalParameterList(yyget_lineno())), *(yyvsp[0].block));
    }
#line 1521 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 35: /* FuncDef: BType Ident LPAREN FuncFParamList RPAREN Block  */
#line 234 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                                                     {
        (yyval.funcdef)=new ast::FunctionDefine(yyget_lineno(), (yyvsp[-5].token),*(yyvsp[-4].ident),*(yyvsp[-2].funcfparams),*(yyvsp[0].block));
    }
#line 1529 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 36: /* FuncDef: BType Ident LPAREN RPAREN Block  */
#line 237 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                                      {
        (yyval.funcdef)=new ast::FunctionDefine(yyget_lineno(), (yyvsp[-4].token), *(yyvsp[-3].ident), *(new ast::FunctionFormalParameterList(yyget_lineno())), *(yyvsp[0].block));
    }
#line 1537 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 37: /* FuncFParamList: FuncFParam  */
#line 243 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                           {
    (yyval.funcfparams)=new ast::FunctionFormalParameterList(yyget_lineno());
    (yyval.funcfparams)->arg_list_.push_back((yyvsp[0].funcfparam));
}
#line 1546 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 38: /* FuncFParamList: FuncFParamList COMMA FuncFParam  */
#line 247 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                                      {
        (yyval.funcfparams)=(yyvsp[-2].funcfparams);
        (yyval.funcfparams)->arg_list_.push_back((yyvsp[0].funcfparam));
    }
#line 1555 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 41: /* FuncFParamOne: BType Ident  */
#line 257 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                           {
    (yyval.funcfparam)=new ast::FunctionFormalParameter(yyget_lineno(), (yyvsp[-1].token), *static_cast<ast::LeftValue*>((yyvsp[0].ident)));
}
#line 1563 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 42: /* FuncFParamArray: BType Ident LSQUARE RSQUARE  */
#line 262 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                                             {
    auto array_ident = new ast::ArrayIdentifier(yyget_lineno(), *(yyvsp[-2].ident));
    // NOTE
    // array_ident->shape_list_.push_back(static_cast<ast::Expression*>(new ast::Number(yyget_lineno(), 1)));
    (yyval.funcfparam)=new ast::FunctionFormalParameter(yyget_lineno(),(yyvsp[-3].token),
                           static_cast<ast::LeftValue&>(*(array_ident))
                          );
}
#line 1576 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 43: /* FuncFParamArray: FuncFParamArray LSQUARE Exp RSQUARE  */
#line 270 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                                          {
        (yyval.funcfparam)=(yyvsp[-3].funcfparam);
        dynamic_cast<ast::ArrayIdentifier&>((yyval.funcfparam)->name_).shape_list_.push_back(std::shared_ptr<ast::Expression>((yyvsp[-1].expr)));
    }
#line 1585 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 44: /* Block: LBRACE RBRACE  */
#line 276 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                     {
    (yyval.block)=new ast::Block(yyget_lineno());
}
#line 1593 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 45: /* Block: LBRACE BlockItemList RBRACE  */
#line 279 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                                  {
        (yyval.block)=(yyvsp[-1].block);
    }
#line 1601 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 46: /* BlockItemList: BlockItem  */
#line 284 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                         {
    (yyval.block)=new ast::Block(yyget_lineno());
    (yyval.block)->statement_list_.push_back((yyvsp[0].statement));
}
#line 1610 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 47: /* BlockItemList: BlockItemList BlockItem  */
#line 288 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                              {
        (yyval.block)=(yyvsp[-1].block);
        (yyval.block)->statement_list_.push_back((yyvsp[0].statement));
    }
#line 1619 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 49: /* BlockItem: Decl  */
#line 295 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
           {
        (yyval.statement)=static_cast<ast::Statement*>((yyvsp[0].declare));
    }
#line 1627 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 54: /* Stmt: Block  */
#line 305 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
            {
        (yyval.statement)=static_cast<ast::Statement*>((yyvsp[0].block));
    }
#line 1635 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 55: /* Stmt: BREAK SEMI  */
#line 308 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                 {
        (yyval.statement)=static_cast<ast::Statement*>(new ast::BreakStatement(yyget_lineno()));
    }
#line 1643 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 56: /* Stmt: CONTINUE SEMI  */
#line 311 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                    {
        (yyval.statement)=static_cast<ast::Statement*>(new ast::ContinueStatement(yyget_lineno()));
    }
#line 1651 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 57: /* Stmt: SEMI  */
#line 314 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
           {
        (yyval.statement)=static_cast<ast::Statement*>(new ast::VoidStatement(yyget_lineno()));
    }
#line 1659 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 58: /* Stmt: Exp SEMI  */
#line 317 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
               {
        (yyval.statement)=static_cast<ast::Statement*>(new ast::EvalStatement(yyget_lineno(), *(yyvsp[-1].expr)));
    }
#line 1667 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 59: /* AssignStmt: LVal ASSIGN Exp SEMI  */
#line 322 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                                 {
    (yyval.statement)=static_cast<ast::Statement*>(new ast::AssignStatement(yyget_lineno(), *(yyvsp[-3].left_val),*(yyvsp[-1].expr)));
}
#line 1675 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 60: /* IfStmt: IF LPAREN Cond RPAREN Stmt  */
#line 327 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                                   {
    (yyval.statement)=static_cast<ast::Statement*>(
        new ast::IfElseStatement(yyget_lineno(), (dynamic_cast<ast::ConditionExpression&>(*(yyvsp[-2].expr))), *(yyvsp[0].statement), nullptr));
}
#line 1684 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 61: /* IfStmt: IF LPAREN Cond RPAREN Stmt ELSE Stmt  */
#line 331 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                                           {
        (yyval.statement)=static_cast<ast::Statement*>(
            new ast::IfElseStatement(yyget_lineno(), (dynamic_cast<ast::ConditionExpression&>(*(yyvsp[-4].expr))), *(yyvsp[-2].statement), (yyvsp[0].statement)));
    }
#line 1693 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 62: /* WhileStmt: WHILE LPAREN Cond RPAREN Stmt  */
#line 337 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                                         {
    (yyval.statement)=static_cast<ast::Statement*>(
        new ast::WhileStatement(yyget_lineno(), (dynamic_cast<ast::ConditionExpression&>(*(yyvsp[-2].expr))), *(yyvsp[0].statement))
    );
}
#line 1703 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 63: /* ReturnStmt: RETURN SEMI  */
#line 344 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                        {
    (yyval.statement)=static_cast<ast::Statement*>(new ast::ReturnStatement(yyget_lineno(), nullptr));
}
#line 1711 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 64: /* ReturnStmt: RETURN Exp SEMI  */
#line 347 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                      {
        (yyval.statement)=static_cast<ast::Statement*>(new ast::ReturnStatement(yyget_lineno(), (yyvsp[-1].expr)));
    }
#line 1719 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 67: /* LVal: Ident  */
#line 359 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
            {
    (yyval.left_val)=static_cast<ast::LeftValue*>((yyvsp[0].ident));
}
#line 1727 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 68: /* LVal: ArrayIdent  */
#line 362 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                 {
        (yyval.left_val)=static_cast<ast::LeftValue*>((yyvsp[0].array_ident));
    }
#line 1735 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 69: /* PrimaryExp: LPAREN Exp RPAREN  */
#line 367 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                              {  // TODO: Exp or Cond
    (yyval.expr)=static_cast<ast::Expression*>((yyvsp[-1].expr));
}
#line 1743 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 70: /* PrimaryExp: Number  */
#line 370 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
             {
        (yyval.expr)=static_cast<ast::Expression*>((yyvsp[0].number));
    }
#line 1751 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 71: /* PrimaryExp: LVal  */
#line 373 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
           {
        (yyval.expr)=static_cast<ast::Expression*>((yyvsp[0].left_val));
    }
#line 1759 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 73: /* UnaryExp: UnaryOp UnaryExp  */
#line 379 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                       {
        (yyval.expr)=static_cast<ast::Expression*>(new ast::UnaryExpression(yyget_lineno(), (yyvsp[-1].token),*(yyvsp[0].expr)));
    }
#line 1767 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 74: /* UnaryExp: FuncCall  */
#line 382 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
               {
        (yyval.expr)=static_cast<ast::Expression*>((yyvsp[0].funccall));
    }
#line 1775 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 75: /* FuncCall: Ident LPAREN RPAREN  */
#line 387 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                              {
    (yyval.funccall)=new ast::FunctionCall(yyget_lineno(), *(yyvsp[-2].ident),*(new ast::FunctionActualParameterList(yyget_lineno())));
    called_func_map[(yyvsp[-2].ident)->name_].insert((yyval.funccall));
}
#line 1784 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 76: /* FuncCall: Ident LPAREN FuncRParamList RPAREN  */
#line 391 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                                         {
        (yyval.funccall)=new ast::FunctionCall(yyget_lineno(), *(yyvsp[-3].ident),*(yyvsp[-1].funcaparams));
        called_func_map[(yyvsp[-3].ident)->name_].insert((yyval.funccall));
    }
#line 1793 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 77: /* FuncRParamList: Exp  */
#line 397 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                    {
    (yyval.funcaparams)=new ast::FunctionActualParameterList(yyget_lineno());
    (yyval.funcaparams)->arg_list_.push_back((yyvsp[0].expr));
}
#line 1802 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 78: /* FuncRParamList: FuncRParamList COMMA Exp  */
#line 401 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                               {
        (yyval.funcaparams)=(yyvsp[-2].funcaparams);
        (yyval.funcaparams)->arg_list_.push_back((yyvsp[0].expr));
    }
#line 1811 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 80: /* MulExp: MulExp MulOp UnaryExp  */
#line 408 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                            {
        (yyval.expr)=static_cast<ast::Expression*>(new ast::BinaryExpression(yyget_lineno(), (yyvsp[-1].token), std::shared_ptr<ast::Expression>((yyvsp[-2].expr)), *(yyvsp[0].expr)));
    }
#line 1819 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 82: /* AddExp: AddExp AddOp MulExp  */
#line 414 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                          {
        (yyval.expr)=static_cast<ast::Expression*>(new ast::BinaryExpression(yyget_lineno(), (yyvsp[-1].token), std::shared_ptr<ast::Expression>((yyvsp[-2].expr)), *(yyvsp[0].expr)));
    }
#line 1827 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 84: /* RelExp: RelExp RelOp AddExp  */
#line 420 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                          {
        (yyval.expr)=static_cast<ast::Expression*>(new ast::ConditionExpression(yyget_lineno(), (yyvsp[-1].token),*(yyvsp[-2].expr),*(yyvsp[0].expr)));
    }
#line 1835 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 86: /* EqExp: EqExp EqOp RelExp  */
#line 426 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                        {
        (yyval.expr)=static_cast<ast::Expression*>(new ast::ConditionExpression(yyget_lineno(), (yyvsp[-1].token),*(yyvsp[-2].expr),*(yyvsp[0].expr)));
    }
#line 1843 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 88: /* LAndExp: LAndExp AND EqExp  */
#line 432 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                        {
        (yyval.expr)=static_cast<ast::Expression*>(new ast::ConditionExpression(yyget_lineno(), (yyvsp[-1].token),*(yyvsp[-2].expr),*(yyvsp[0].expr)));
    }
#line 1851 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 89: /* LOrExp: LAndExp  */
#line 437 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                {
    if(auto ptr=dynamic_cast<ast::ConditionExpression*>((yyvsp[0].expr))){ (yyval.expr) = (yyvsp[0].expr); }
    else{// NOTE: ($1 || 0)
        (yyval.expr) = static_cast<ast::Expression*>(new ast::ConditionExpression(yyget_lineno(), OR, *(yyvsp[0].expr), *(new ast::Number(yyget_lineno(), 0)))); }
}
#line 1861 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 90: /* LOrExp: LOrExp OR LAndExp  */
#line 442 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
                        {
        (yyval.expr)=static_cast<ast::Expression*>(new ast::ConditionExpression(yyget_lineno(), (yyvsp[-1].token),*(yyvsp[-2].expr),*(yyvsp[0].expr)));
    }
#line 1869 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 91: /* Ident: IDENT  */
#line 447 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
             {
    (yyval.ident)=new ast::Identifier(yyget_lineno(), *(yyvsp[0].string));
}
#line 1877 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;

  case 92: /* Number: NUMBER  */
#line 452 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
              {
    (yyval.number)=new ast::Number(yyget_lineno(), (yyvsp[0].token));
}
#line 1885 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"
    break;


#line 1889 "/home/code/Github_repo/compiler-main/src/front_end/parser.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 481 "/home/code/Github_repo/compiler-main/src/front_end/parser.y"
