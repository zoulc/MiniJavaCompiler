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

    extern int yylex();
    void yyerror(const char *s) { printf("ERROR: %s\n", s); }

#line 101 "parser.cpp" /* yacc.c:339  */

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
    TCLE = 265,
    TCGT = 266,
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
    TPLUS = 278,
    TMINUS = 279,
    TMUL = 280,
    TDIV = 281,
    TAND = 282,
    TLF = 283,
    TRF = 284,
    TCLASS = 285,
    TVOID = 286,
    TPUBLIC = 287,
    TSTATIC = 288,
    TMAIN = 289,
    TSTRING = 290,
    TEXTENDS = 291,
    TRETURN = 292,
    TFALSE = 293,
    TTRUE = 294,
    TBOOL = 295,
    TBANG = 296,
    TELSE = 297,
    TIF = 298,
    TLENGT = 299,
    TNEW = 300,
    TTHIS = 301,
    TWHILE = 302
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 37 "parser.y" /* yacc.c:355  */

    Ident* ident;
    TypeInfo* type;
    Expr* expr;
    Stmt* stmt;
    BiOpExpr* biopexpr;
    MainClassDecl * mainclassdecl ; 
    ClassDeclList * classdecllist ;
    MtdDeclList * mtddecllist ;
    ExprList * exprlist ; 
    StmtList * stmtlist ;
    Program * program ;
    ClassDecl * classdecl ;
    MtdDecl * mtddecl ;
    VarDeclList * vardecllist ; 
    VarArgList * vararglist ;
    VarDecl * vardecl ; 
    VarArg * vararg ; 
    std::string *string ;
    int token;

#line 211 "parser.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 226 "parser.cpp" /* yacc.c:358  */

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
#define YYLAST   290

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  55
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  144

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

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
      45,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   105,   105,   109,   113,   115,   117,   119,   123,   127,
     131,   135,   136,   137,   138,   141,   142,   144,   146,   148,
     150,   152,   156,   157,   158,   159,   160,   162,   163,   164,
     165,   166,   167,   169,   171,   173,   177,   178,   179,   180,
     181,   183,   184,   188,   189,   192,   193,   197,   198,   200,
     204,   205,   208,   209,   210,   213
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TIDENT", "TINT", "TDOUBLE", "TNUMBER",
  "TCEQ", "TCNE", "TCLT", "TCLE", "TCGT", "TCGE", "TEQUAL", "TLPAREN",
  "TRPAREN", "TLBRACE", "TRBRACE", "TCOMMA", "TDOT", "TSEMICOLON",
  "TSYSOUT", "TSYSIN", "TPLUS", "TMINUS", "TMUL", "TDIV", "TAND", "TLF",
  "TRF", "TCLASS", "TVOID", "TPUBLIC", "TSTATIC", "TMAIN", "TSTRING",
  "TEXTENDS", "TRETURN", "TFALSE", "TTRUE", "TBOOL", "TBANG", "TELSE",
  "TIF", "TLENGT", "TNEW", "TTHIS", "TWHILE", "$accept", "program",
  "mainclassdecl", "classdecl", "vardecl", "vararg", "mtddecl", "type",
  "stmt", "expr", "biopexpr", "stmtlist", "mtddecllist", "classdecllist",
  "exprlist", "vardecllist", "vararglist", "ident", YY_NULL
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
     295,   296,   297,   298,   299,   300,   301,   302
};
# endif

#define YYPACT_NINF -111

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-111)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -28,     8,    15,  -111,  -111,     4,  -111,    39,    -4,     8,
    -111,    38,   -13,    49,  -111,     8,    48,   108,    69,    72,
      60,  -111,     6,  -111,  -111,  -111,     8,     2,  -111,  -111,
      62,    64,     8,    71,  -111,  -111,   110,    76,  -111,    92,
    -111,  -111,    34,    79,     6,  -111,     8,    91,     8,    95,
     100,     6,  -111,   102,   104,  -111,  -111,  -111,     1,    56,
    -111,   117,    78,   118,   120,     8,  -111,     5,   122,    58,
      78,  -111,    78,   123,  -111,  -111,    78,     3,  -111,   177,
    -111,  -111,    78,    78,   121,    78,    78,  -111,  -111,   194,
     201,   128,   262,   124,   131,    78,    -2,   136,    78,    78,
      78,    78,    78,   218,   225,  -111,   238,   142,   134,  -111,
    -111,    78,   140,   262,  -111,   145,  -111,   119,   119,   179,
     262,   149,    86,    86,  -111,   143,  -111,   166,  -111,    78,
    -111,   137,  -111,    78,  -111,   262,    14,    86,   250,  -111,
      78,  -111,  -111,   262
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    45,    55,     0,     1,     2,     0,     0,
      46,     0,     0,     0,    50,     0,     0,     0,     0,     0,
      12,     7,     0,    13,    51,    44,     0,     0,    14,    50,
       0,     0,     0,     0,     6,    43,     0,     0,    11,     0,
       8,     5,     0,     0,    52,     4,     0,    53,     0,     0,
       0,    52,     9,     0,     0,    54,    41,    41,     0,     0,
      41,     0,     0,     0,     0,     0,    42,    14,     0,     0,
       0,    27,     0,     0,    29,    28,     0,     0,    31,     0,
      22,    30,     0,     0,     0,     0,     0,     3,    15,     0,
       0,     0,    34,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,     0,     0,     0,    35,
      23,     0,     0,    38,    25,     0,    10,    36,    37,    40,
      39,     0,     0,     0,    19,     0,    18,     0,    33,    47,
      24,     0,    17,     0,    32,    48,     0,     0,     0,    26,
       0,    16,    20,    49
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -111,  -111,  -111,  -111,  -111,  -111,    36,   113,  -110,   -46,
    -111,    10,   126,  -111,  -111,   151,   109,    -1
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    10,    24,    47,    25,    65,    66,    79,
      80,    58,    27,     7,   136,    17,    49,    81
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       5,     4,     1,    14,     4,    20,     4,    93,    12,     4,
      20,     4,   131,   132,    18,     6,    28,    60,    85,    34,
       8,    28,    61,    15,    89,    33,    90,   141,    11,   139,
      92,    39,   140,    86,    22,    28,   103,   104,    62,   106,
     107,    23,   114,    28,    63,    50,    23,    52,    64,   113,
      28,    45,   117,   118,   119,   120,   121,    67,    67,     4,
      20,     4,    20,    35,    84,   127,    22,    59,    67,     9,
      69,    13,    60,    68,    60,    88,    94,    61,    35,    61,
      16,     4,    19,   135,    71,    29,    30,   138,    31,     4,
      20,    40,    72,    38,   143,   115,    23,    37,    23,    63,
      73,    63,    60,    64,    43,    64,    44,    61,    46,    51,
      53,     4,    20,     4,    20,    54,    74,    75,    56,    76,
      57,    67,    67,    77,    78,    21,    23,    41,    95,    63,
      26,    70,    82,    64,    83,    32,    67,    91,    96,    87,
      22,   105,    22,   110,   100,   112,   101,   102,    23,    26,
      23,    95,   111,   116,   126,   128,   133,    48,    95,   129,
      55,    96,    42,     0,    48,    98,    99,   100,    96,   101,
     102,   125,    98,    99,   100,    95,   101,   102,   130,   137,
      36,     0,     0,     0,     0,    96,    95,     0,    95,    98,
      99,   100,     0,   101,   102,   134,    96,    97,    96,     0,
      98,    99,   100,    95,   101,   102,   101,   102,     0,   108,
      95,     0,     0,    96,     0,     0,   109,    98,    99,   100,
      96,   101,   102,     0,    98,    99,   100,    95,   101,   102,
       0,     0,     0,   122,    95,     0,     0,    96,     0,     0,
     123,    98,    99,   100,    96,   101,   102,    95,    98,    99,
     100,     0,   101,   102,     0,     0,     0,    96,   124,    95,
       0,    98,    99,   100,     0,   101,   102,     0,     0,    96,
     142,    95,     0,    98,    99,   100,     0,   101,   102,     0,
       0,    96,     0,     0,     0,    98,    99,   100,     0,   101,
     102
};

static const yytype_int16 yycheck[] =
{
       1,     3,    30,    16,     3,     4,     3,     4,     9,     3,
       4,     3,   122,   123,    15,     0,    17,    16,    13,    17,
      16,    22,    21,    36,    70,    26,    72,   137,    32,    15,
      76,    32,    18,    28,    32,    36,    82,    83,    37,    85,
      86,    40,    44,    44,    43,    46,    40,    48,    47,    95,
      51,    17,    98,    99,   100,   101,   102,    58,    59,     3,
       4,     3,     4,    27,    65,   111,    32,    57,    69,    30,
      60,    33,    16,    17,    16,    17,    77,    21,    42,    21,
      31,     3,    34,   129,     6,    16,    14,   133,    28,     3,
       4,    20,    14,    29,   140,    96,    40,    35,    40,    43,
      22,    43,    16,    47,    28,    47,    14,    21,    29,    18,
      15,     3,     4,     3,     4,    15,    38,    39,    16,    41,
      16,   122,   123,    45,    46,    17,    40,    17,     9,    43,
      17,    14,    14,    47,    14,    22,   137,    14,    19,    17,
      32,    20,    32,    15,    25,    14,    27,    28,    40,    36,
      40,     9,    28,    17,    20,    15,    13,    44,     9,    14,
      51,    19,    36,    -1,    51,    23,    24,    25,    19,    27,
      28,    29,    23,    24,    25,     9,    27,    28,    29,    42,
      29,    -1,    -1,    -1,    -1,    19,     9,    -1,     9,    23,
      24,    25,    -1,    27,    28,    29,    19,    20,    19,    -1,
      23,    24,    25,     9,    27,    28,    27,    28,    -1,    15,
       9,    -1,    -1,    19,    -1,    -1,    15,    23,    24,    25,
      19,    27,    28,    -1,    23,    24,    25,     9,    27,    28,
      -1,    -1,    -1,    15,     9,    -1,    -1,    19,    -1,    -1,
      15,    23,    24,    25,    19,    27,    28,     9,    23,    24,
      25,    -1,    27,    28,    -1,    -1,    -1,    19,    20,     9,
      -1,    23,    24,    25,    -1,    27,    28,    -1,    -1,    19,
      20,     9,    -1,    23,    24,    25,    -1,    27,    28,    -1,
      -1,    19,    -1,    -1,    -1,    23,    24,    25,    -1,    27,
      28
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,    49,    50,     3,    65,     0,    61,    16,    30,
      51,    32,    65,    33,    16,    36,    31,    63,    65,    34,
       4,    17,    32,    40,    52,    54,    55,    60,    65,    16,
      14,    28,    55,    65,    17,    54,    63,    35,    29,    65,
      20,    17,    60,    28,    14,    17,    29,    53,    55,    64,
      65,    18,    65,    15,    15,    64,    16,    16,    59,    59,
      16,    21,    37,    43,    47,    55,    56,    65,    17,    59,
      14,     6,    14,    22,    38,    39,    41,    45,    46,    57,
      58,    65,    14,    14,    65,    13,    28,    17,    17,    57,
      57,    14,    57,     4,    65,     9,    19,    20,    23,    24,
      25,    27,    28,    57,    57,    20,    57,    57,    15,    15,
      15,    28,    14,    57,    44,    65,    17,    57,    57,    57,
      57,    57,    15,    15,    20,    29,    20,    57,    15,    14,
      29,    56,    56,    13,    29,    57,    62,    42,    57,    15,
      18,    56,    20,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    51,    51,    51,    51,    52,    53,
      54,    55,    55,    55,    55,    56,    56,    56,    56,    56,
      56,    56,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    58,    58,    58,    58,
      58,    59,    59,    60,    60,    61,    61,    62,    62,    62,
      63,    63,    64,    64,    64,    65
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,    17,     8,     7,     6,     5,     3,     2,
      12,     3,     1,     1,     1,     3,     7,     5,     5,     4,
       7,     3,     1,     3,     4,     3,     6,     1,     1,     1,
       1,     1,     5,     4,     2,     3,     3,     3,     3,     3,
       3,     0,     2,     2,     1,     0,     2,     0,     1,     3,
       0,     2,     0,     1,     3,     1
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
#line 106 "parser.y" /* yacc.c:1646  */
    { programAst = new Program( (yyvsp[-1].mainclassdecl) , (yyvsp[0].classdecllist) ) ; }
#line 1406 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 110 "parser.y" /* yacc.c:1646  */
    { (yyval.mainclassdecl) = new MainClassDecl( (yyvsp[-15].ident) , (yyvsp[-5].ident) , (yyvsp[-2].stmtlist) ) ; }
#line 1412 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 114 "parser.y" /* yacc.c:1646  */
    { (yyval.classdecl) = new ClassDecl( (yyvsp[-6].ident) , (yyvsp[-4].ident) , (yyvsp[-2].vardecllist) , (yyvsp[-1].mtddecllist) ) ;  }
#line 1418 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 116 "parser.y" /* yacc.c:1646  */
    { (yyval.classdecl) = new ClassDecl( (yyvsp[-5].ident) , (yyvsp[-3].ident) , (yyvsp[-1].vardecllist) , new MtdDeclList() ) ;  }
#line 1424 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 118 "parser.y" /* yacc.c:1646  */
    { (yyval.classdecl) = new ClassDecl( (yyvsp[-4].ident) , NULL , (yyvsp[-2].vardecllist) , (yyvsp[-1].mtddecllist) ) ; }
#line 1430 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 120 "parser.y" /* yacc.c:1646  */
    { (yyval.classdecl) = new ClassDecl( (yyvsp[-3].ident) , NULL , (yyvsp[-1].vardecllist) , new MtdDeclList() ) ; }
#line 1436 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 124 "parser.y" /* yacc.c:1646  */
    { (yyval.vardecl) = new VarDecl( (yyvsp[-2].type) , (yyvsp[-1].ident) ) ; }
#line 1442 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 128 "parser.y" /* yacc.c:1646  */
    { (yyval.vararg) = new VarArg( (yyvsp[-1].type), (yyvsp[0].ident) ) ; }
#line 1448 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 132 "parser.y" /* yacc.c:1646  */
    { (yyval.mtddecl) = new MtdDecl( (yyvsp[-10].type) , (yyvsp[-9].ident) , (yyvsp[-7].vararglist) , (yyvsp[-4].stmtlist) , (yyvsp[-2].expr) ); }
#line 1454 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 135 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = new ArrType( new IntType() ) ; }
#line 1460 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 136 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = new IntType() ; }
#line 1466 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 137 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = new BoolType() ; }
#line 1472 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 138 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = new ClassIdentType( (yyvsp[0].ident) ) ; }
#line 1478 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 141 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new BlockStmt((yyvsp[-1].stmtlist)) ; }
#line 1484 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 143 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new IfThenElseStmt( (yyvsp[-4].expr) , (yyvsp[-2].stmt) , (yyvsp[0].stmt) ) ; }
#line 1490 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 145 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new WhileStmt( (yyvsp[-2].expr) , (yyvsp[0].stmt) ) ; }
#line 1496 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 147 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new SysOutPrtStmt( (yyvsp[-2].expr) ) ; }
#line 1502 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 149 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new AssignStmt( (yyvsp[-3].ident) , (yyvsp[-1].expr) ) ; }
#line 1508 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 151 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new ArrAssignStmt( (yyvsp[-6].ident) , (yyvsp[-4].expr) , (yyvsp[-1].expr) ) ; }
#line 1514 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 153 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new VarDeclStmt( (yyvsp[-2].type) , (yyvsp[-1].ident) ) ; }
#line 1520 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 156 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].biopexpr) ; }
#line 1526 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 157 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new SysInReadExpr( ) ; }
#line 1532 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 158 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ArrAcsExpr( (yyvsp[-3].expr) , (yyvsp[-1].expr) ) ; }
#line 1538 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 159 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new GetLenExpr( (yyvsp[-2].expr) ) ; }
#line 1544 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 161 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new GetMtdCallExpr( (yyvsp[-5].expr) , (yyvsp[-3].ident) , (yyvsp[-1].exprlist) ) ; }
#line 1550 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 162 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new IntLiterExpr( atol((yyvsp[0].string)->c_str()) ) ; }
#line 1556 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 163 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new TrueLiterExpr( ) ; }
#line 1562 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 164 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new FalseLiterExpr( ) ; }
#line 1568 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 165 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new IdentAccessExpr( (yyvsp[0].ident) ) ; }
#line 1574 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 166 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ThisExpr( ) ; }
#line 1580 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 168 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ArrNewExpr( (yyvsp[-1].expr) ) ; }
#line 1586 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 170 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ObjNewExpr( (yyvsp[-2].ident) ) ; }
#line 1592 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 172 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new NegExpr( (yyvsp[0].expr) ) ; }
#line 1598 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 174 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ParenExpr( (yyvsp[-1].expr) ) ; }
#line 1604 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 177 "parser.y" /* yacc.c:1646  */
    { (yyval.biopexpr) = new AddExpr( (yyvsp[-2].expr) , (yyvsp[0].expr) ) ; }
#line 1610 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 178 "parser.y" /* yacc.c:1646  */
    { (yyval.biopexpr) = new SubExpr( (yyvsp[-2].expr) , (yyvsp[0].expr) ) ; }
#line 1616 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 179 "parser.y" /* yacc.c:1646  */
    { (yyval.biopexpr) = new LessCmpExpr( (yyvsp[-2].expr) , (yyvsp[0].expr) ) ; }
#line 1622 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 180 "parser.y" /* yacc.c:1646  */
    { (yyval.biopexpr) = new AndExpr( (yyvsp[-2].expr) , (yyvsp[0].expr) ) ; }
#line 1628 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 181 "parser.y" /* yacc.c:1646  */
    { (yyval.biopexpr) = new MultExpr( (yyvsp[-2].expr) , (yyvsp[0].expr) ) ; }
#line 1634 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 183 "parser.y" /* yacc.c:1646  */
    { (yyval.stmtlist) = new StmtList() ; }
#line 1640 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 185 "parser.y" /* yacc.c:1646  */
    { (yyval.stmtlist) = new StmtList( (yyvsp[-1].stmtlist) , (yyvsp[0].stmt) ) ; }
#line 1646 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 188 "parser.y" /* yacc.c:1646  */
    { (yyval.mtddecllist) = new MtdDeclList( (yyvsp[-1].mtddecllist) , (yyvsp[0].mtddecl) ) ; }
#line 1652 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 189 "parser.y" /* yacc.c:1646  */
    { (yyval.mtddecllist) = new MtdDeclList ( new MtdDeclList() , (yyvsp[0].mtddecl) ) ; }
#line 1658 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 192 "parser.y" /* yacc.c:1646  */
    { (yyval.classdecllist) = new ClassDeclList() ; }
#line 1664 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 194 "parser.y" /* yacc.c:1646  */
    { (yyval.classdecllist) = new ClassDeclList( (yyvsp[-1].classdecllist) , (yyvsp[0].classdecl) ) ; }
#line 1670 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 197 "parser.y" /* yacc.c:1646  */
    { (yyval.exprlist) = new ExprList() ; }
#line 1676 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 199 "parser.y" /* yacc.c:1646  */
    { (yyval.exprlist) = new ExprList( new ExprList() , (yyvsp[0].expr) ) ; }
#line 1682 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 201 "parser.y" /* yacc.c:1646  */
    { (yyval.exprlist) = new ExprList( (yyvsp[-2].exprlist) , (yyvsp[0].expr) ) ;}
#line 1688 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 204 "parser.y" /* yacc.c:1646  */
    { (yyval.vardecllist) = new VarDeclList() ; }
#line 1694 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 205 "parser.y" /* yacc.c:1646  */
    { (yyval.vardecllist) = new VarDeclList( (yyvsp[-1].vardecllist) , (yyvsp[0].vardecl) ) ; }
#line 1700 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 208 "parser.y" /* yacc.c:1646  */
    { (yyval.vararglist) = new VarArgList() ; }
#line 1706 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 209 "parser.y" /* yacc.c:1646  */
    { (yyval.vararglist) = new VarArgList( new VarArgList() , (yyvsp[0].vararg) ) ; }
#line 1712 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 210 "parser.y" /* yacc.c:1646  */
    { (yyval.vararglist) = new VarArgList( (yyvsp[0].vararglist), (yyvsp[-2].vararg) ) ; }
#line 1718 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 213 "parser.y" /* yacc.c:1646  */
    { (yyval.ident) = new Ident( *(yyvsp[0].string)  ) ;  }
#line 1724 "parser.cpp" /* yacc.c:1646  */
    break;


#line 1728 "parser.cpp" /* yacc.c:1646  */
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
#line 215 "parser.y" /* yacc.c:1906  */

