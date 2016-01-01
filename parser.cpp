/* A Bison parser, made by GNU Bison 3.0.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

/*
#include "ast/ArrNewExpr.h"
#include "ast/BiOpExpr.h"
#include "ast/ClassDecl.h"
#include "ast/ClassDeclList.h"
#include "ast/Expr.h"
#include "ast/ExprList.h"
#include "ast/GetLenExpr.h"
#include "ast/GetMtdCallExpr.h"
#include "ast/Ident.h"
#include "ast/IdentAccessExpr.h"
#include "ast/LiterExpr.h"
#include "ast/MainClassDecl.h"
#include "ast/MtdDecl.h"
#include "ast/MtdDeclList.h"
#include "ast/ObjNewExpr.h"
#include "ast/Program.h"
#include "ast/SiOpExpr.h"
#include "ast/Stmt.h"
#include "ast/StmtList.h"
#include "ast/ThisExpr.h"
#include "ast/Type.h"
#include "ast/VarArg.h"
#include "ast/VarArgList.h"
#include "ast/VarDecl.h"
#include "ast/VarDeclList.h"
*/
#include "node.h"
    Program *programAst; /* the top level root node of our final AST */
    extern std::map<std::string, TemplateClassDecl*> NamedTemplateClassDecls;

    extern int yylex();
    void yyerror(const char *s) { printf("ERROR: %s\n", s); }

#line 102 "parser.cpp" /* yacc.c:339  */

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.hpp".  */
#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TIDENT = 258,
    TINT = 259,
    TDOUBLE = 260,
    TNUMBER = 261,
    TCEQ = 262,
    TCNE = 263,
    TCLT = 264,
    TCGT = 265,
    TCLE = 266,
    TCGE = 267,
    TEQUAL = 268,
    TLPAREN = 269,
    TRPAREN = 270,
    TLBRACE = 271,
    TRBRACE = 272,
    TCOMMA = 273,
    TDOT = 274,
    TSEMICOLON = 275,
    TSYSOUT = 276,
    TSYSIN = 277,
    TSYSOUTCHAR = 278,
    TSYSINCHAR = 279,
    TPLUS = 280,
    TMINUS = 281,
    TMUL = 282,
    TDIV = 283,
    TAND = 284,
    TLF = 285,
    TRF = 286,
    TCLASS = 287,
    TVOID = 288,
    TPUBLIC = 289,
    TSTATIC = 290,
    TMAIN = 291,
    TSTRING = 292,
    TEXTENDS = 293,
    TRETURN = 294,
    TFALSE = 295,
    TTRUE = 296,
    TBOOL = 297,
    TBANG = 298,
    TELSE = 299,
    TIF = 300,
    TLENGT = 301,
    TNEW = 302,
    TTHIS = 303,
    TWHILE = 304,
    TINVOKER = 305,
    TARROW = 306,
    TITFACE = 307,
    TIMPLEM = 308,
    TINSTANCEOF = 309,
    TOBJECT = 310
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 38 "parser.y" /* yacc.c:355  */

    Ident* ident;
    TypeInfo* type;
    Expr* expr;
    Stmt* stmt;
    BiOpExpr* biopexpr;
    MainClassDecl * mainclassdecl ;
    ClassDeclList * classdecllist ;
    ItfaceDeclList * itfacedecllist ;
    MtdDeclList * mtddecllist ;
    AbsMtdDeclList * absmtddecllist ;
    ExprList * exprlist ;
    StmtList * stmtlist ;
    Program * program ;
    ClassDecl * classdecl ;
    ItfaceDecl * itfacedecl ;
    MtdDecl * mtddecl ;
    AbsMtdDecl* absmtddecl ;
    VarDeclList * vardecllist ;
    VarArgList * vararglist ;
    VarDecl * vardecl ;
    VarArg * vararg ;
    ExtItface * extitface ;
    ExtItfaceList * extitfacelist ;
    ImpItface * impitface ;
    ImpItfaceList * impitfacelist ;
    std::string *string ;
    int token;

#line 228 "parser.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 243 "parser.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   547

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  248

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   310

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   124,   124,   126,   128,   130,   134,   138,   140,   142,
     143,   144,   147,   148,   149,   152,   155,   159,   161,   163,
     165,   169,   171,   175,   179,   183,   187,   191,   192,   193,
     194,   195,   196,   197,   200,   201,   203,   205,   207,   209,
     211,   213,   217,   218,   219,   220,   221,   222,   224,   225,
     226,   227,   228,   229,   231,   233,   235,   237,   239,   241,
     243,   245,   249,   250,   251,   252,   253,   254,   255,   256,
     258,   259,   263,   264,   265,   268,   269,   273,   274,   276,
     280,   281,   284,   285,   286,   289,   291,   293,   295,   297,
     299,   301,   303
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TIDENT", "TINT", "TDOUBLE", "TNUMBER",
  "TCEQ", "TCNE", "TCLT", "TCGT", "TCLE", "TCGE", "TEQUAL", "TLPAREN",
  "TRPAREN", "TLBRACE", "TRBRACE", "TCOMMA", "TDOT", "TSEMICOLON",
  "TSYSOUT", "TSYSIN", "TSYSOUTCHAR", "TSYSINCHAR", "TPLUS", "TMINUS",
  "TMUL", "TDIV", "TAND", "TLF", "TRF", "TCLASS", "TVOID", "TPUBLIC",
  "TSTATIC", "TMAIN", "TSTRING", "TEXTENDS", "TRETURN", "TFALSE", "TTRUE",
  "TBOOL", "TBANG", "TELSE", "TIF", "TLENGT", "TNEW", "TTHIS", "TWHILE",
  "TINVOKER", "TARROW", "TITFACE", "TIMPLEM", "TINSTANCEOF", "TOBJECT",
  "$accept", "program", "mainclassdecl", "extitface", "impitface",
  "extitfacelist", "impitfacelist", "templateclassdecl", "classdecl",
  "itfacedecl", "vardecl", "vararg", "mtddecl", "absmtddecl", "type",
  "stmt", "expr", "biopexpr", "stmtlist", "mtddecllist", "absmtddecllist",
  "exprlist", "vardecllist", "vararglist", "itfacedeclident",
  "classdeclident", "vardeclident", "argdeclident", "mtddeclident",
  "varuseident", "typeuseident", "mtduseident", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310
};
# endif

#define YYPACT_NINF -131

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-131)))

#define YYTABLE_NINF -92

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -20,    21,    11,  -131,  -131,    83,  -131,    21,    34,  -131,
    -131,  -131,   -17,    14,  -131,    16,   -16,   102,  -131,    21,
      34,    89,    34,   109,   125,    75,   -13,  -131,   178,  -131,
      80,  -131,     1,  -131,   204,  -131,   122,    20,  -131,   133,
      80,  -131,  -131,  -131,  -131,   167,    52,   168,  -131,    34,
    -131,    34,   192,  -131,  -131,    89,    34,   189,  -131,    21,
     173,   192,  -131,   190,  -131,  -131,   180,    75,   219,    75,
    -131,  -131,   207,    68,  -131,   199,    75,   222,  -131,   227,
    -131,   230,   232,    90,  -131,    93,    80,  -131,   214,   116,
    -131,    80,  -131,  -131,  -131,    75,  -131,  -131,   167,   114,
     215,  -131,    75,   194,   126,  -131,   225,    80,   244,   140,
     239,  -131,  -131,  -131,  -131,   233,  -131,  -131,   240,   399,
    -131,    22,  -131,   247,   248,   145,   249,   252,   167,  -131,
     148,   409,   439,   145,   145,   253,  -131,    97,   254,   260,
    -131,  -131,   145,   186,  -131,   146,  -131,  -131,   267,   145,
     145,   280,   145,   145,   270,  -131,   172,   198,   117,   224,
     196,   292,   295,   381,   234,     7,   145,   145,   145,   145,
      30,   294,   145,   145,   145,   145,   145,    80,   145,   250,
     276,  -131,   289,   263,  -131,   293,   300,  -131,   261,  -131,
    -131,   145,   226,   306,   381,   381,   381,   381,  -131,  -131,
     312,  -131,    19,    19,   493,   381,   315,  -131,   381,   200,
     449,   449,  -131,   314,  -131,  -131,   313,   328,   318,   321,
    -131,   145,  -131,  -131,   145,   288,  -131,   145,  -131,  -131,
     319,   325,   201,   381,   449,   341,   424,   337,   347,  -131,
    -131,  -131,   145,  -131,  -131,   367,   339,  -131
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,    86,     0,     1,     0,     0,     5,
       3,     4,     0,     0,    85,     0,     0,     0,    80,     0,
      12,     0,     9,     0,     0,    72,     0,    13,     0,     8,
       0,    76,     0,    10,     0,     7,     0,     0,    91,    28,
       0,    29,    30,    81,    74,     0,     0,    33,    80,    12,
      80,     0,     0,    22,    75,     0,     0,     0,    80,     0,
       0,     0,    87,     0,    20,    73,     0,    72,     0,    72,
      14,    89,     0,     0,    11,     0,    72,     0,    27,     0,
      23,     0,     0,     0,    80,     0,    82,    21,     0,     0,
      80,    82,    31,    32,    18,    72,    19,    83,     0,     0,
       0,    15,    72,     0,     0,    24,     0,     0,     0,     0,
       0,    17,    26,    84,    88,     0,    16,    70,     0,     0,
      70,    90,    70,     0,     0,     0,     0,     0,     0,    71,
       0,     0,     0,     0,     0,    87,    48,    82,     0,     0,
      50,    49,     0,     0,    52,     0,    42,    51,     0,     0,
       0,     0,     0,     0,     0,    34,     0,     0,    87,     0,
       0,     0,     0,    57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,     0,
       0,    41,     0,     0,     6,     0,     0,    58,     0,    43,
      44,     0,     0,     0,    66,    67,    64,    65,    92,    46,
       0,    25,    62,    63,    69,    68,     0,    61,    78,     0,
       0,     0,    39,     0,    37,    38,     0,     0,     0,     0,
      56,    77,    45,    60,     0,     0,    36,     0,    70,    53,
       0,     0,     0,    79,     0,     0,     0,     0,     0,    47,
      35,    40,     0,    54,    55,     0,     0,    59
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -131,  -131,  -131,   307,   322,  -131,   316,  -131,  -131,  -131,
    -131,   257,   -44,   -23,   -25,  -130,   -78,  -131,  -114,    39,
     317,   157,    78,   -84,    12,     3,   -41,  -131,   320,  -118,
     236,  -131
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    33,    27,    34,    28,     9,    10,    11,
      43,    97,    44,    31,   128,   129,   208,   146,   119,    46,
      32,   209,    25,    99,    29,     5,   147,   115,    72,   148,
      47,   200
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,   130,    65,    48,    63,    52,   131,   103,   132,    54,
      13,     6,     1,   130,   130,    61,   192,    16,    53,    23,
      15,   193,    26,    17,     4,   -91,   166,   167,   168,   169,
      18,   -91,    21,   198,    35,    30,    58,    14,   170,    65,
      49,    65,    45,     7,    45,    65,   174,   145,   175,   176,
      54,    45,    19,   160,    22,   156,   157,   105,    59,   159,
      65,    98,    77,     8,   163,    65,    98,    20,    35,    64,
      45,   179,   180,   177,   182,   183,   199,    45,    38,    39,
     225,   226,    98,    38,    39,    87,    40,   151,   194,   195,
     196,   197,   130,   130,   202,   203,   204,   205,   206,    12,
     158,    39,    30,   136,   240,    24,    83,    94,    85,    40,
      96,   137,    98,   217,   236,    89,   130,    41,   130,   138,
     -91,   139,    41,    30,    40,    42,    67,    40,    69,   106,
      42,   -90,   107,   101,   104,    37,    76,   140,   141,    41,
     142,   109,    36,   111,   143,   144,   233,    42,   135,   235,
      40,   136,   207,   166,   167,   168,   169,   116,    57,   137,
      40,   152,    95,    60,   245,   170,   171,   138,   102,   139,
      62,   172,   173,   174,    40,   175,   176,    66,   153,   166,
     167,   168,   169,    81,    82,   140,   141,   185,   142,    38,
     164,   170,   143,   144,    50,    71,    51,   172,   173,   174,
     177,   175,   176,    75,    78,   166,   167,   168,   169,   110,
      80,   188,   107,   186,   107,   223,   239,   170,   224,   224,
      55,    86,    56,   172,   173,   174,   177,   175,   176,   218,
     219,   166,   167,   168,   169,    84,    88,    51,    90,   187,
      92,    91,    93,   170,   100,   112,   108,   114,   118,   172,
     173,   174,   177,   175,   176,   117,   120,   166,   167,   168,
     169,   133,   134,   149,   191,   210,   150,   -90,   161,   170,
     166,   167,   168,   169,   162,   172,   173,   174,   177,   175,
     176,   178,   170,   166,   167,   168,   169,   184,   172,   173,
     174,   211,   175,   176,   213,   170,   166,   167,   168,   169,
     181,   172,   173,   174,   177,   175,   176,   189,   170,   212,
     190,   201,   216,   214,   172,   173,   174,   177,   175,   176,
     215,   220,   166,   167,   168,   169,   221,   227,   230,   228,
     177,   231,   234,   237,   170,   166,   167,   168,   169,   238,
     172,   173,   174,   177,   175,   176,   222,   170,   166,   167,
     168,   169,   243,   172,   173,   174,   247,   175,   176,   229,
     170,   241,   244,    74,   113,    68,   172,   173,   174,   177,
     175,   176,    73,    70,   166,   167,   168,   169,   232,   165,
       0,    79,   177,     0,     0,     0,   170,   246,   166,   167,
     168,   169,   172,   173,   174,   177,   175,   176,     0,     0,
     170,     0,   121,    39,     0,     0,   172,   173,   174,     0,
     175,   176,   121,    39,     0,   122,     0,     0,     0,     0,
     123,   177,   124,     0,     0,   122,   154,   121,    39,     0,
     123,     0,   124,     0,     0,   177,     0,     0,   125,     0,
     122,    41,   121,    39,   126,   123,     0,   124,   127,    42,
       0,    41,   121,    39,   126,   122,   155,     0,   127,    42,
     123,     0,   124,   242,     0,   122,    41,     0,     0,   126,
     123,     0,   124,   127,    42,     0,     0,     0,     0,     0,
       0,    41,     0,     0,   126,     0,     0,     0,   127,    42,
       0,    41,     0,     0,   126,     0,     0,     0,   127,    42,
     166,   167,   168,   169,     0,     0,     0,     0,     0,     0,
       0,     0,   170,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   175,   176,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   177
};

static const yytype_int16 yycheck[] =
{
      25,   119,    46,    16,    45,    30,   120,    91,   122,    32,
       7,     0,    32,   131,   132,    40,     9,    34,    17,    35,
       8,    14,    19,     9,     3,     3,     7,     8,     9,    10,
      16,     9,    16,     3,    22,    34,    16,     3,    19,    83,
      53,    85,    67,    32,    69,    89,    27,   125,    29,    30,
      73,    76,    38,   137,    38,   133,   134,    98,    38,   137,
     104,    86,    59,    52,   142,   109,    91,    53,    56,    17,
      95,   149,   150,    54,   152,   153,    46,   102,     3,     4,
     210,   211,   107,     3,     4,    17,    34,   128,   166,   167,
     168,   169,   210,   211,   172,   173,   174,   175,   176,    16,
       3,     4,    34,     6,   234,     3,    67,    17,    69,    34,
      17,    14,   137,   191,   228,    76,   234,    42,   236,    22,
       3,    24,    42,    34,    34,    50,    48,    34,    50,    15,
      50,    14,    18,    17,    95,    10,    58,    40,    41,    42,
      43,   102,    33,    17,    47,    48,   224,    50,     3,   227,
      34,     6,   177,     7,     8,     9,    10,    17,    36,    14,
      34,    13,    84,    30,   242,    19,    20,    22,    90,    24,
       3,    25,    26,    27,    34,    29,    30,     9,    30,     7,
       8,     9,    10,     3,     4,    40,    41,    15,    43,     3,
       4,    19,    47,    48,    16,     3,    18,    25,    26,    27,
      54,    29,    30,    14,    31,     7,     8,     9,    10,    15,
      20,    15,    18,    15,    18,    15,    15,    19,    18,    18,
      16,    14,    18,    25,    26,    27,    54,    29,    30,     3,
       4,     7,     8,     9,    10,    16,    37,    18,    16,    15,
      10,    14,    10,    19,    30,    20,    31,     3,    15,    25,
      26,    27,    54,    29,    30,    16,    16,     7,     8,     9,
      10,    14,    14,    14,    30,    15,    14,    14,    14,    19,
       7,     8,     9,    10,    14,    25,    26,    27,    54,    29,
      30,    14,    19,     7,     8,     9,    10,    17,    25,    26,
      27,    15,    29,    30,    31,    19,     7,     8,     9,    10,
      20,    25,    26,    27,    54,    29,    30,    15,    19,    20,
      15,    17,    51,    20,    25,    26,    27,    54,    29,    30,
      20,    15,     7,     8,     9,    10,    14,    13,    10,    16,
      54,    10,    44,    14,    19,     7,     8,     9,    10,    14,
      25,    26,    27,    54,    29,    30,    31,    19,     7,     8,
       9,    10,    15,    25,    26,    27,    17,    29,    30,    31,
      19,    20,    15,    56,   107,    49,    25,    26,    27,    54,
      29,    30,    55,    51,     7,     8,     9,    10,   221,   143,
      -1,    61,    54,    -1,    -1,    -1,    19,    20,     7,     8,
       9,    10,    25,    26,    27,    54,    29,    30,    -1,    -1,
      19,    -1,     3,     4,    -1,    -1,    25,    26,    27,    -1,
      29,    30,     3,     4,    -1,    16,    -1,    -1,    -1,    -1,
      21,    54,    23,    -1,    -1,    16,    17,     3,     4,    -1,
      21,    -1,    23,    -1,    -1,    54,    -1,    -1,    39,    -1,
      16,    42,     3,     4,    45,    21,    -1,    23,    49,    50,
      -1,    42,     3,     4,    45,    16,    17,    -1,    49,    50,
      21,    -1,    23,    39,    -1,    16,    42,    -1,    -1,    45,
      21,    -1,    23,    49,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    -1,    45,    -1,    -1,    -1,    49,    50,
      -1,    42,    -1,    -1,    45,    -1,    -1,    -1,    49,    50,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    57,    58,     3,    81,     0,    32,    52,    63,
      64,    65,    16,    81,     3,    80,    34,     9,    16,    38,
      53,    16,    38,    35,     3,    78,    81,    60,    62,    80,
      34,    69,    76,    59,    61,    80,    33,    10,     3,     4,
      34,    42,    50,    66,    68,    70,    75,    86,    16,    53,
      16,    18,    70,    17,    69,    16,    18,    36,    16,    38,
      30,    70,     3,    82,    17,    68,     9,    78,    62,    78,
      60,     3,    84,    76,    59,    14,    78,    81,    31,    84,
      20,     3,     4,    75,    16,    75,    14,    17,    37,    75,
      16,    14,    10,    10,    17,    78,    17,    67,    70,    79,
      30,    17,    78,    79,    75,    82,    15,    18,    31,    75,
      15,    17,    20,    67,     3,    83,    17,    16,    15,    74,
      16,     3,    16,    21,    23,    39,    45,    49,    70,    71,
      85,    74,    74,    14,    14,     3,     6,    14,    22,    24,
      40,    41,    43,    47,    48,    72,    73,    82,    85,    14,
      14,    82,    13,    30,    17,    17,    72,    72,     3,    72,
      79,    14,    14,    72,     4,    86,     7,     8,     9,    10,
      19,    20,    25,    26,    27,    29,    30,    54,    14,    72,
      72,    20,    72,    72,    17,    15,    15,    15,    15,    15,
      15,    30,     9,    14,    72,    72,    72,    72,     3,    46,
      87,    17,    72,    72,    72,    72,    72,    70,    72,    77,
      15,    15,    20,    31,    20,    20,    51,    72,     3,     4,
      15,    14,    31,    15,    18,    71,    71,    13,    16,    31,
      10,    10,    77,    72,    44,    72,    74,    14,    14,    15,
      71,    20,    39,    15,    15,    72,    20,    17
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    57,    57,    57,    58,    59,    60,    61,
      61,    61,    62,    62,    62,    63,    63,    64,    64,    64,
      64,    65,    65,    66,    67,    68,    69,    70,    70,    70,
      70,    70,    70,    70,    71,    71,    71,    71,    71,    71,
      71,    71,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    73,    73,    73,    73,    73,    73,    73,    73,
      74,    74,    75,    75,    75,    76,    76,    77,    77,    77,
      78,    78,    79,    79,    79,    80,    81,    82,    83,    84,
      85,    86,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,    17,     1,     1,     0,
       1,     3,     0,     1,     3,     9,    11,    10,     8,     8,
       6,     7,     5,     3,     2,    12,     7,     3,     1,     1,
       1,     4,     4,     1,     3,     7,     5,     5,     5,     4,
       7,     3,     1,     3,     3,     4,     3,     6,     1,     1,
       1,     1,     1,     5,     7,     7,     4,     2,     3,    10,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       0,     2,     0,     2,     1,     2,     1,     0,     1,     3,
       0,     2,     0,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 125 "parser.y" /* yacc.c:1646  */
    { programAst = new Program( (yyvsp[0].mainclassdecl) ) ; }
#line 1526 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 127 "parser.y" /* yacc.c:1646  */
    { programAst->AddClassDecl( (yyvsp[0].classdecl) ) ; }
#line 1532 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 129 "parser.y" /* yacc.c:1646  */
    { programAst->AddItfaceDecl( (yyvsp[0].itfacedecl) ) ; }
#line 1538 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 131 "parser.y" /* yacc.c:1646  */
    { }
#line 1544 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 135 "parser.y" /* yacc.c:1646  */
    { (yyval.mainclassdecl) = new MainClassDecl( (yyvsp[-15].ident) , (yyvsp[-5].ident) , (yyvsp[-2].stmtlist) ) ; }
#line 1550 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 138 "parser.y" /* yacc.c:1646  */
    { (yyval.extitface) = new ExtItface( (yyvsp[0].ident) ) ; }
#line 1556 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 140 "parser.y" /* yacc.c:1646  */
    { (yyval.impitface) = new ImpItface( (yyvsp[0].ident) ) ; }
#line 1562 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 142 "parser.y" /* yacc.c:1646  */
    { (yyval.extitfacelist) = new ExtItfaceList() ; }
#line 1568 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 143 "parser.y" /* yacc.c:1646  */
    { (yyval.extitfacelist) = ( new ExtItfaceList() )->AddExtItface( (yyvsp[0].extitface) ) ; }
#line 1574 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 144 "parser.y" /* yacc.c:1646  */
    { (yyval.extitfacelist) = (yyvsp[-2].extitfacelist) -> AddExtItface( (yyvsp[0].extitface) ) ; }
#line 1580 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 147 "parser.y" /* yacc.c:1646  */
    { (yyval.impitfacelist) = new ImpItfaceList() ; }
#line 1586 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 148 "parser.y" /* yacc.c:1646  */
    { (yyval.impitfacelist) = ( new ImpItfaceList() )->AddImpItface( (yyvsp[0].impitface) ) ; }
#line 1592 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 149 "parser.y" /* yacc.c:1646  */
    { (yyval.impitfacelist) = (yyvsp[-2].impitfacelist) -> AddImpItface( (yyvsp[0].impitface) ) ; }
#line 1598 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 153 "parser.y" /* yacc.c:1646  */
    { NamedTemplateClassDecls.insert(std::pair<std::string, TemplateClassDecl*>
			((yyvsp[-7].ident)->name, new TemplateClassDecl( (yyvsp[-7].ident), *(yyvsp[-5].string), NULL, new ImpItfaceList(), (yyvsp[-2].vardecllist), (yyvsp[-1].mtddecllist)))); }
#line 1605 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 156 "parser.y" /* yacc.c:1646  */
    { NamedTemplateClassDecls.insert(std::pair<std::string, TemplateClassDecl*>
			((yyvsp[-9].ident)->name, new TemplateClassDecl( (yyvsp[-9].ident), *(yyvsp[-7].string), (yyvsp[-4].ident), new ImpItfaceList(), (yyvsp[-2].vardecllist), (yyvsp[-1].mtddecllist)))); }
#line 1612 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 160 "parser.y" /* yacc.c:1646  */
    { (yyval.classdecl) = new ClassDecl( (yyvsp[-8].ident) , (yyvsp[-6].ident) , (yyvsp[-4].impitfacelist) , (yyvsp[-2].vardecllist) , (yyvsp[-1].mtddecllist) ) ;  }
#line 1618 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 162 "parser.y" /* yacc.c:1646  */
    { (yyval.classdecl) = new ClassDecl( (yyvsp[-6].ident) , (yyvsp[-4].ident) , new ImpItfaceList() , (yyvsp[-2].vardecllist) , (yyvsp[-1].mtddecllist) ) ;  }
#line 1624 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 164 "parser.y" /* yacc.c:1646  */
    { (yyval.classdecl) = new ClassDecl( (yyvsp[-6].ident) , NULL , (yyvsp[-4].impitfacelist) , (yyvsp[-2].vardecllist) , (yyvsp[-1].mtddecllist) ) ;  }
#line 1630 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 166 "parser.y" /* yacc.c:1646  */
    { (yyval.classdecl) = new ClassDecl( (yyvsp[-4].ident) , NULL , new ImpItfaceList() , (yyvsp[-2].vardecllist) , (yyvsp[-1].mtddecllist) ) ; }
#line 1636 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 170 "parser.y" /* yacc.c:1646  */
    { (yyval.itfacedecl) = new ItfaceDecl( (yyvsp[-5].ident) , (yyvsp[-3].extitfacelist) , (yyvsp[-1].absmtddecllist) ) ; }
#line 1642 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 172 "parser.y" /* yacc.c:1646  */
    { (yyval.itfacedecl) = new ItfaceDecl( (yyvsp[-3].ident) , new ExtItfaceList() , (yyvsp[-1].absmtddecllist) ) ; }
#line 1648 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 176 "parser.y" /* yacc.c:1646  */
    { (yyval.vardecl) = new VarDecl( (yyvsp[-2].type) , (yyvsp[-1].ident) ) ; }
#line 1654 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 180 "parser.y" /* yacc.c:1646  */
    { (yyval.vararg) = new VarArg( (yyvsp[-1].type), (yyvsp[0].ident) ) ; }
#line 1660 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 184 "parser.y" /* yacc.c:1646  */
    { (yyval.mtddecl) = new MtdDecl( (yyvsp[-10].type) , (yyvsp[-9].ident) , (yyvsp[-7].vararglist) , (yyvsp[-4].stmtlist) , (yyvsp[-2].expr) ); }
#line 1666 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 188 "parser.y" /* yacc.c:1646  */
    { (yyval.absmtddecl) = new AbsMtdDecl( (yyvsp[-5].type) , (yyvsp[-4].ident) , (yyvsp[-2].vararglist) ); }
#line 1672 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 191 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = new ArrType( new IntType() ) ; }
#line 1678 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 192 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = new IntType() ; }
#line 1684 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 193 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = new BoolType() ; }
#line 1690 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 194 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = new InvokerType() ; }
#line 1696 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 195 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = new TemplateUsrDefIdentType( (yyvsp[-3].ident), *(yyvsp[-1].string)); }
#line 1702 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 196 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = new TemplateUsrDefIdentType( (yyvsp[-3].ident), string("int") ); }
#line 1708 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 197 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = new UsrDefIdentType( (yyvsp[0].ident) ) ; }
#line 1714 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 200 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new BlockStmt((yyvsp[-1].stmtlist)) ; }
#line 1720 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 202 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new IfThenElseStmt( (yyvsp[-4].expr) , (yyvsp[-2].stmt) , (yyvsp[0].stmt) ) ; }
#line 1726 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 204 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new WhileStmt( (yyvsp[-2].expr) , (yyvsp[0].stmt) ) ; }
#line 1732 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 206 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new SysOutPrtStmt( (yyvsp[-2].expr) ) ; }
#line 1738 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 208 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new SysOutPrtCharStmt( (yyvsp[-2].expr) ) ; }
#line 1744 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 210 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new AssignStmt( (yyvsp[-3].ident) , (yyvsp[-1].expr) ) ; }
#line 1750 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 212 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new ArrAssignStmt( (yyvsp[-6].ident) , (yyvsp[-4].expr) , (yyvsp[-1].expr) ) ; }
#line 1756 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 214 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new VarDeclStmt( (yyvsp[-2].type) , (yyvsp[-1].ident) ) ; }
#line 1762 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 217 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].biopexpr) ; }
#line 1768 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 218 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new SysInReadExpr( ) ; }
#line 1774 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 219 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new SysInReadCharExpr( ) ; }
#line 1780 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 220 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ArrAcsExpr( (yyvsp[-3].expr) , (yyvsp[-1].expr) ) ; }
#line 1786 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 221 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new GetLenExpr( (yyvsp[-2].expr) ) ; }
#line 1792 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 223 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new GetMtdCallExpr( (yyvsp[-5].expr) , (yyvsp[-3].ident) , (yyvsp[-1].exprlist) ) ; }
#line 1798 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 224 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new IntLiterExpr( atol((yyvsp[0].string)->c_str()) ) ; }
#line 1804 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 225 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new TrueLiterExpr( ) ; }
#line 1810 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 226 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new FalseLiterExpr( ) ; }
#line 1816 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 227 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new IdentAccessExpr( (yyvsp[0].ident) ) ; }
#line 1822 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 228 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ThisExpr( ) ; }
#line 1828 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 230 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ArrNewExpr( (yyvsp[-1].expr) ) ; }
#line 1834 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 232 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new TemplateObjNewExpr( (yyvsp[-5].ident), *(yyvsp[-3].string) ); }
#line 1840 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 234 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new TemplateObjNewExpr( (yyvsp[-5].ident), string("int") ); }
#line 1846 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 236 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ObjNewExpr( (yyvsp[-2].ident) ) ; }
#line 1852 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 238 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new NegExpr( (yyvsp[0].expr) ) ; }
#line 1858 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 240 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ParenExpr( (yyvsp[-1].expr) ) ; }
#line 1864 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 242 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new LamdaGenExpr( (yyvsp[-8].vararglist) , (yyvsp[-4].stmtlist) , (yyvsp[-2].expr) ) ; }
#line 1870 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 244 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new LamdaAppExpr( (yyvsp[-3].ident) , (yyvsp[-1].exprlist) ) ; }
#line 1876 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 246 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new InsOfExpr( (yyvsp[-2].expr) , (yyvsp[0].type) ) ; }
#line 1882 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 249 "parser.y" /* yacc.c:1646  */
    { (yyval.biopexpr) = new AddExpr( (yyvsp[-2].expr) , (yyvsp[0].expr) ) ; }
#line 1888 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 250 "parser.y" /* yacc.c:1646  */
    { (yyval.biopexpr) = new SubExpr( (yyvsp[-2].expr) , (yyvsp[0].expr) ) ; }
#line 1894 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 251 "parser.y" /* yacc.c:1646  */
    { (yyval.biopexpr) = new LessCmpExpr( (yyvsp[-2].expr) , (yyvsp[0].expr) ) ; }
#line 1900 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 252 "parser.y" /* yacc.c:1646  */
    { (yyval.biopexpr) = new GreaterCmpExpr( (yyvsp[-2].expr) , (yyvsp[0].expr) ) ; }
#line 1906 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 253 "parser.y" /* yacc.c:1646  */
    { (yyval.biopexpr) = new EqualCmpExpr( (yyvsp[-2].expr) , (yyvsp[0].expr) ) ; }
#line 1912 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 254 "parser.y" /* yacc.c:1646  */
    { (yyval.biopexpr) = new NotEqualCmpExpr( (yyvsp[-2].expr) , (yyvsp[0].expr) ) ; }
#line 1918 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 255 "parser.y" /* yacc.c:1646  */
    { (yyval.biopexpr) = new AndExpr( (yyvsp[-2].expr) , (yyvsp[0].expr) ) ; }
#line 1924 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 256 "parser.y" /* yacc.c:1646  */
    { (yyval.biopexpr) = new MultExpr( (yyvsp[-2].expr) , (yyvsp[0].expr) ) ; }
#line 1930 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 258 "parser.y" /* yacc.c:1646  */
    { (yyval.stmtlist) = new StmtList() ; }
#line 1936 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 260 "parser.y" /* yacc.c:1646  */
    { (yyval.stmtlist) = new StmtList( (yyvsp[-1].stmtlist) , (yyvsp[0].stmt) ) ; }
#line 1942 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 263 "parser.y" /* yacc.c:1646  */
    { (yyval.mtddecllist) = new MtdDeclList() ; }
#line 1948 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 264 "parser.y" /* yacc.c:1646  */
    { (yyval.mtddecllist) = new MtdDeclList( (yyvsp[-1].mtddecllist) , (yyvsp[0].mtddecl) ) ; }
#line 1954 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 265 "parser.y" /* yacc.c:1646  */
    { (yyval.mtddecllist) = new MtdDeclList ( new MtdDeclList() , (yyvsp[0].mtddecl) ) ; }
#line 1960 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 268 "parser.y" /* yacc.c:1646  */
    { (yyval.absmtddecllist) = new AbsMtdDeclList( (yyvsp[-1].absmtddecllist) , (yyvsp[0].absmtddecl) ) ; }
#line 1966 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 269 "parser.y" /* yacc.c:1646  */
    { (yyval.absmtddecllist) = new AbsMtdDeclList ( new AbsMtdDeclList() , (yyvsp[0].absmtddecl) ) ; }
#line 1972 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 273 "parser.y" /* yacc.c:1646  */
    { (yyval.exprlist) = new ExprList() ; }
#line 1978 "parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 275 "parser.y" /* yacc.c:1646  */
    { (yyval.exprlist) = new ExprList( new ExprList() , (yyvsp[0].expr) ) ; }
#line 1984 "parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 277 "parser.y" /* yacc.c:1646  */
    { (yyval.exprlist) = new ExprList( (yyvsp[-2].exprlist) , (yyvsp[0].expr) ) ;}
#line 1990 "parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 280 "parser.y" /* yacc.c:1646  */
    { (yyval.vardecllist) = new VarDeclList() ; }
#line 1996 "parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 281 "parser.y" /* yacc.c:1646  */
    { (yyval.vardecllist) = new VarDeclList( (yyvsp[-1].vardecllist) , (yyvsp[0].vardecl) ) ; }
#line 2002 "parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 284 "parser.y" /* yacc.c:1646  */
    { (yyval.vararglist) = new VarArgList() ; }
#line 2008 "parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 285 "parser.y" /* yacc.c:1646  */
    { (yyval.vararglist) = new VarArgList( new VarArgList() , (yyvsp[0].vararg) ) ; }
#line 2014 "parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 286 "parser.y" /* yacc.c:1646  */
    { (yyval.vararglist) = new VarArgList( (yyvsp[-2].vararglist), (yyvsp[0].vararg) ) ; }
#line 2020 "parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 289 "parser.y" /* yacc.c:1646  */
    { (yyval.ident) = new ItfaceDeclIdent( *(yyvsp[0].string)  ) ;  }
#line 2026 "parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 291 "parser.y" /* yacc.c:1646  */
    { (yyval.ident) = new ClassDeclIdent( *(yyvsp[0].string)  ) ;  }
#line 2032 "parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 293 "parser.y" /* yacc.c:1646  */
    { (yyval.ident) = new VarDeclIdent( *(yyvsp[0].string)  ) ;  }
#line 2038 "parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 295 "parser.y" /* yacc.c:1646  */
    { (yyval.ident) = new ArgDeclIdent( *(yyvsp[0].string)  ) ;  }
#line 2044 "parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 297 "parser.y" /* yacc.c:1646  */
    { (yyval.ident) = new MtdDeclIdent( *(yyvsp[0].string)  ) ;  }
#line 2050 "parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 299 "parser.y" /* yacc.c:1646  */
    { (yyval.ident) = new VarUseIdent( *(yyvsp[0].string)  ) ;  }
#line 2056 "parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 301 "parser.y" /* yacc.c:1646  */
    { (yyval.ident) = new TypeUseIdent( *(yyvsp[0].string)  ) ;  }
#line 2062 "parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 303 "parser.y" /* yacc.c:1646  */
    { (yyval.ident) = new MtdUseIdent( *(yyvsp[0].string)  ) ;  }
#line 2068 "parser.cpp" /* yacc.c:1646  */
    break;


#line 2072 "parser.cpp" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 305 "parser.y" /* yacc.c:1906  */

