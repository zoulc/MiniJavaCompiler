/* A Bison parser, made by GNU Bison 3.0.2.  */

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         parser.cppparse
#define yylex           parser.cpplex
#define yyerror         parser.cpperror
#define yydebug         parser.cppdebug
#define yynerrs         parser.cppnerrs

#define yylval          parser.cpplval
#define yychar          parser.cppchar

/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include "ArrNewExpr.h"
#include "BiOpExpr.h"
#include "ClassDecl.h"
#include "ClassDeclList.h"
#include "Expr.h"
#include "ExprList.h"
#include "GetLenExpr.h"
#include "GetMtdCallExpr.h"
#include "Ident.h"
#include "IdentAccessExpr.h"
#include "LiterExpr.h"
#include "MainClassDecl.h"
#include "MtdDecl.h"
#include "MtdDeclList.h"
#include "ObjNewExpr.h"
#include "Program.h"
#include "SiOpExpr.h"
#include "Stmt.h"
#include "StmtList.h"
#include "ThisExpr.h"
#include "Type.h"
#include "VarArg.h"
#include "VarArgList.h"
#include "VarDecl.h"
#include "VarDeclList.h"
    Program *programAst; /* the top level root node of our final AST */

    extern int yylex();
    void yyerror(const char *s) { printf("ERROR: %s\n", s); }

#line 106 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int parser.cppdebug;
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
    TPLUS = 277,
    TMINUS = 278,
    TMUL = 279,
    TDIV = 280,
    TAND = 281,
    TLF = 282,
    TRF = 283,
    TCLASS = 284,
    TVOID = 285,
    TPUBLIC = 286,
    TSTATIC = 287,
    TMAIN = 288,
    TSTRING = 289,
    TEXTENDS = 290,
    TRETURN = 291,
    TFALSE = 292,
    TTRUE = 293,
    TBOOL = 294,
    TBANG = 295,
    TELSE = 296,
    TIF = 297,
    TLENGT = 298,
    TNEW = 299,
    TTHIS = 300,
    TWHILE = 301
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 34 "parser.y" /* yacc.c:355  */

    Ident* ident;
    Type* type;
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

#line 212 "parser.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE parser.cpplval;

int parser.cppparse (void);



/* Copy the second part of user declarations.  */

#line 227 "parser.tab.c" /* yacc.c:358  */

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
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
#define YYLAST   299

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  55
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  141

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

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
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   102,   102,   106,   110,   112,   114,   118,   122,   126,
     130,   131,   132,   133,   136,   137,   139,   141,   143,   145,
     147,   151,   152,   153,   154,   156,   157,   158,   159,   160,
     161,   163,   165,   167,   171,   172,   173,   174,   175,   177,
     178,   182,   183,   186,   187,   191,   192,   196,   197,   199,
     203,   204,   207,   208,   209,   212
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
  "TSYSOUT", "TPLUS", "TMINUS", "TMUL", "TDIV", "TAND", "TLF", "TRF",
  "TCLASS", "TVOID", "TPUBLIC", "TSTATIC", "TMAIN", "TSTRING", "TEXTENDS",
  "TRETURN", "TFALSE", "TTRUE", "TBOOL", "TBANG", "TELSE", "TIF", "TLENGT",
  "TNEW", "TTHIS", "TWHILE", "$accept", "program", "mainclassdecl",
  "classdecl", "vardecl", "vararg", "mtddecl", "type", "stmt", "expr",
  "biopexpr", "stmtlist", "nonnullmtddecllist", "mtddecllist",
  "classdecllist", "exprlist", "vardecllist", "vararglist", "ident", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301
};
# endif

#define YYPACT_NINF -117

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-117)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -16,    14,    28,  -117,  -117,    16,  -117,     9,    13,    14,
    -117,    17,   -14,    26,  -117,    14,    34,     3,    55,    64,
      49,     7,  -117,  -117,  -117,    14,    53,    63,  -117,  -117,
      52,    68,    14,    70,  -117,  -117,   111,    72,  -117,    77,
    -117,  -117,    92,    83,     7,  -117,    14,    98,    14,   102,
     105,     7,  -117,   109,   110,  -117,  -117,  -117,    58,    56,
    -117,   115,   107,   118,   120,    14,  -117,     6,   106,    66,
     107,  -117,   107,  -117,  -117,   107,    62,  -117,   167,  -117,
    -117,   107,   107,   116,   107,   107,  -117,  -117,   183,   199,
     261,   108,   124,   107,    -2,   122,   107,   107,   107,   107,
     107,   215,   231,  -117,   240,   134,   121,  -117,   107,   125,
     261,  -117,   132,  -117,   272,   272,    -4,   261,   145,    85,
      85,  -117,   135,  -117,   156,  -117,   107,  -117,   114,  -117,
     107,  -117,   261,    -6,    85,   252,  -117,   107,  -117,  -117,
     261
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    45,    55,     0,     1,     2,     0,     0,
      46,     0,     0,     0,    50,     0,     0,    43,     0,     0,
      11,     0,    12,    51,    42,     0,    44,     0,    13,    50,
       0,     0,     0,     0,    41,     6,     0,     0,    10,     0,
       7,     5,     0,     0,    52,     4,     0,    53,     0,     0,
       0,    52,     8,     0,     0,    54,    39,    39,     0,     0,
      39,     0,     0,     0,     0,     0,    40,    13,     0,     0,
       0,    25,     0,    27,    26,     0,     0,    29,     0,    21,
      28,     0,     0,     0,     0,     0,     3,    14,     0,     0,
      32,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    20,     0,     0,     0,    33,     0,     0,
      36,    23,     0,     9,    34,    35,    38,    37,     0,     0,
       0,    18,     0,    17,     0,    31,    47,    22,     0,    16,
       0,    30,    48,     0,     0,     0,    24,     0,    15,    19,
      49
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -117,  -117,  -117,  -117,  -117,  -117,   123,    86,  -116,   -45,
    -117,   -31,  -117,   127,  -117,  -117,   130,   119,    -1
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    10,    23,    47,    24,    65,    66,    78,
      79,    58,    26,    27,     7,   133,    17,    49,    80
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       5,     4,    14,   128,   129,    93,     4,    20,    12,   136,
       4,    20,   137,     1,    18,    94,    28,     4,   138,    84,
      28,    15,    99,   100,    33,    88,    59,    89,     6,    69,
      90,    39,     8,    85,    21,    28,   101,   102,     9,   104,
     105,   111,    22,    28,    11,    50,    22,    52,   110,    13,
      28,   114,   115,   116,   117,   118,    16,    67,    67,     4,
      20,     4,    20,   124,    83,     4,    91,    19,    67,     4,
      20,    29,    60,    68,    60,    92,    31,    61,    30,    61,
      35,   132,    60,    87,    21,   135,    37,    61,     4,    20,
      40,    44,   140,   112,    62,    22,    38,    22,    63,    43,
      63,    60,    64,    25,    64,    22,    61,    32,    63,    45,
       4,    46,    64,    71,     4,    20,    51,    53,    67,    67,
      54,    72,    25,    86,    22,    56,    57,    63,    41,    70,
      48,    64,    81,    67,    82,   108,   103,    48,   109,   113,
     125,   123,    21,    93,    73,    74,   126,    75,   130,    34,
      22,    76,    77,    94,    93,   134,    96,    97,    98,    36,
      99,   100,   122,    42,    94,    93,     0,    96,    97,    98,
      55,    99,   100,   127,     0,    94,    93,     0,    96,    97,
      98,     0,    99,   100,   131,     0,    94,    95,     0,    96,
      97,    98,    93,    99,   100,     0,     0,     0,   106,     0,
       0,     0,    94,     0,     0,    96,    97,    98,    93,    99,
     100,     0,     0,     0,   107,     0,     0,     0,    94,     0,
       0,    96,    97,    98,    93,    99,   100,     0,     0,     0,
     119,     0,     0,     0,    94,     0,     0,    96,    97,    98,
      93,    99,   100,     0,     0,     0,   120,     0,     0,    93,
      94,     0,     0,    96,    97,    98,     0,    99,   100,    94,
     121,    93,    96,    97,    98,     0,    99,   100,     0,     0,
      93,    94,   139,     0,    96,    97,    98,     0,    99,   100,
      94,    93,     0,    96,    97,    98,     0,    99,   100,     0,
       0,    94,     0,     0,     0,     0,    98,     0,    99,   100
};

static const yytype_int16 yycheck[] =
{
       1,     3,    16,   119,   120,     9,     3,     4,     9,    15,
       3,     4,    18,    29,    15,    19,    17,     3,   134,    13,
      21,    35,    26,    27,    25,    70,    57,    72,     0,    60,
      75,    32,    16,    27,    31,    36,    81,    82,    29,    84,
      85,    43,    39,    44,    31,    46,    39,    48,    93,    32,
      51,    96,    97,    98,    99,   100,    30,    58,    59,     3,
       4,     3,     4,   108,    65,     3,     4,    33,    69,     3,
       4,    16,    16,    17,    16,    76,    27,    21,    14,    21,
      17,   126,    16,    17,    31,   130,    34,    21,     3,     4,
      20,    14,   137,    94,    36,    39,    28,    39,    42,    27,
      42,    16,    46,    17,    46,    39,    21,    21,    42,    17,
       3,    28,    46,     6,     3,     4,    18,    15,   119,   120,
      15,    14,    36,    17,    39,    16,    16,    42,    17,    14,
      44,    46,    14,   134,    14,    27,    20,    51,    14,    17,
      15,    20,    31,     9,    37,    38,    14,    40,    13,    26,
      39,    44,    45,    19,     9,    41,    22,    23,    24,    29,
      26,    27,    28,    36,    19,     9,    -1,    22,    23,    24,
      51,    26,    27,    28,    -1,    19,     9,    -1,    22,    23,
      24,    -1,    26,    27,    28,    -1,    19,    20,    -1,    22,
      23,    24,     9,    26,    27,    -1,    -1,    -1,    15,    -1,
      -1,    -1,    19,    -1,    -1,    22,    23,    24,     9,    26,
      27,    -1,    -1,    -1,    15,    -1,    -1,    -1,    19,    -1,
      -1,    22,    23,    24,     9,    26,    27,    -1,    -1,    -1,
      15,    -1,    -1,    -1,    19,    -1,    -1,    22,    23,    24,
       9,    26,    27,    -1,    -1,    -1,    15,    -1,    -1,     9,
      19,    -1,    -1,    22,    23,    24,    -1,    26,    27,    19,
      20,     9,    22,    23,    24,    -1,    26,    27,    -1,    -1,
       9,    19,    20,    -1,    22,    23,    24,    -1,    26,    27,
      19,     9,    -1,    22,    23,    24,    -1,    26,    27,    -1,
      -1,    19,    -1,    -1,    -1,    -1,    24,    -1,    26,    27
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    29,    48,    49,     3,    65,     0,    61,    16,    29,
      50,    31,    65,    32,    16,    35,    30,    63,    65,    33,
       4,    31,    39,    51,    53,    54,    59,    60,    65,    16,
      14,    27,    54,    65,    53,    17,    63,    34,    28,    65,
      20,    17,    60,    27,    14,    17,    28,    52,    54,    64,
      65,    18,    65,    15,    15,    64,    16,    16,    58,    58,
      16,    21,    36,    42,    46,    54,    55,    65,    17,    58,
      14,     6,    14,    37,    38,    40,    44,    45,    56,    57,
      65,    14,    14,    65,    13,    27,    17,    17,    56,    56,
      56,     4,    65,     9,    19,    20,    22,    23,    24,    26,
      27,    56,    56,    20,    56,    56,    15,    15,    27,    14,
      56,    43,    65,    17,    56,    56,    56,    56,    56,    15,
      15,    20,    28,    20,    56,    15,    14,    28,    55,    55,
      13,    28,    56,    62,    41,    56,    15,    18,    55,    20,
      56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    50,    50,    50,    51,    52,    53,
      54,    54,    54,    54,    55,    55,    55,    55,    55,    55,
      55,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    57,    57,    57,    57,    57,    58,
      58,    59,    59,    60,    60,    61,    61,    62,    62,    62,
      63,    63,    64,    64,    64,    65
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,    17,     8,     7,     6,     3,     2,    12,
       3,     1,     1,     1,     3,     7,     5,     5,     4,     7,
       3,     1,     4,     3,     6,     1,     1,     1,     1,     1,
       5,     4,     2,     3,     3,     3,     3,     3,     3,     0,
       2,     2,     1,     0,     1,     0,     2,     0,     1,     3,
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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
#line 103 "parser.y" /* yacc.c:1646  */
    { programAst = new Program( (yyvsp[-1].mainclassdecl) , (yyvsp[0].classdecllist) ) ; }
#line 1426 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 107 "parser.y" /* yacc.c:1646  */
    { (yyval.mainclassdecl) = new MainClassDecl( (yyvsp[-15].ident) , (yyvsp[-5].ident) , (yyvsp[-2].stmtlist) ) ; }
#line 1432 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 111 "parser.y" /* yacc.c:1646  */
    { (yyval.classdecl) = new ClassDecl( (yyvsp[-6].ident) , (yyvsp[-4].ident) , (yyvsp[-2].vardecllist) , (yyvsp[-1].mtddecllist) ) ;  }
#line 1438 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 113 "parser.y" /* yacc.c:1646  */
    { (yyval.classdecl) = new ClassDecl( (yyvsp[-5].ident) , (yyvsp[-3].ident) , (yyvsp[-1].vardecllist) , new MtdDeclList() ) ;  }
#line 1444 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 115 "parser.y" /* yacc.c:1646  */
    { (yyval.classdecl) = new ClassDecl( (yyvsp[-4].ident) , NULL , (yyvsp[-2].vardecllist) , (yyvsp[-1].mtddecllist) ) ; }
#line 1450 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 119 "parser.y" /* yacc.c:1646  */
    { (yyval.vardecl) = new VarDecl( (yyvsp[-2].type) , (yyvsp[-1].ident) ) ; }
#line 1456 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 123 "parser.y" /* yacc.c:1646  */
    { (yyval.vararg) = new VarArg( (yyvsp[-1].type), (yyvsp[0].ident) ) ; }
#line 1462 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 127 "parser.y" /* yacc.c:1646  */
    { (yyval.mtddecl) = new MtdDecl( (yyvsp[-10].type) , (yyvsp[-9].ident) , (yyvsp[-7].vararglist) , (yyvsp[-4].stmtlist) , (yyvsp[-2].expr) ); }
#line 1468 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 130 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = new ArrType( new IntType() ) ; }
#line 1474 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 131 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = new IntType() ; }
#line 1480 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 132 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = new BoolType() ; }
#line 1486 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 133 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = new ClassIdentType( (yyvsp[0].ident) ) ; }
#line 1492 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 136 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new BlockStmt((yyvsp[-1].stmtlist)) ; }
#line 1498 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 138 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new IfThenElseStmt( (yyvsp[-4].expr) , (yyvsp[-2].stmt) , (yyvsp[0].stmt) ) ; }
#line 1504 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 140 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new WhileStmt( (yyvsp[-2].expr) , (yyvsp[0].stmt) ) ; }
#line 1510 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 142 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new SysOutPrtStmt( (yyvsp[-2].expr) ) ; }
#line 1516 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 144 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new AssignStmt( (yyvsp[-3].ident) , (yyvsp[-1].expr) ) ; }
#line 1522 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 146 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new ArrAssignStmt( (yyvsp[-6].ident) , (yyvsp[-4].expr) , (yyvsp[-1].expr) ) ; }
#line 1528 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 148 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new VarDeclStmt( (yyvsp[-2].type) , (yyvsp[-1].ident) ) ; }
#line 1534 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 151 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].biopexpr) ; }
#line 1540 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 152 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ArrAcsExpr( (yyvsp[-3].expr) , (yyvsp[-1].expr) ) ; }
#line 1546 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 153 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new GetLenExpr( (yyvsp[-2].expr) ) ; }
#line 1552 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 155 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new GetMtdCallExpr( (yyvsp[-5].expr) , (yyvsp[-3].ident) , (yyvsp[-1].exprlist) ) ; }
#line 1558 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 156 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new IntLiterExpr( atol((yyvsp[0].string)->c_str()) ) ; }
#line 1564 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 157 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new TrueLiterExpr( ) ; }
#line 1570 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 158 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new FalseLiterExpr( ) ; }
#line 1576 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 159 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new IdentAccessExpr( (yyvsp[0].ident) ) ; }
#line 1582 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 160 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ThisExpr( ) ; }
#line 1588 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 162 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ArrNewExpr( (yyvsp[-1].expr) ) ; }
#line 1594 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 164 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ObjNewExpr( (yyvsp[-2].ident) ) ; }
#line 1600 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 166 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new NegExpr( (yyvsp[0].expr) ) ; }
#line 1606 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 168 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ParenExpr( (yyvsp[-1].expr) ) ; }
#line 1612 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 171 "parser.y" /* yacc.c:1646  */
    { (yyval.biopexpr) = new AddExpr( (yyvsp[-2].expr) , (yyvsp[0].expr) ) ; }
#line 1618 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 172 "parser.y" /* yacc.c:1646  */
    { (yyval.biopexpr) = new SubExpr( (yyvsp[-2].expr) , (yyvsp[0].expr) ) ; }
#line 1624 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 173 "parser.y" /* yacc.c:1646  */
    { (yyval.biopexpr) = new LessCmpExpr( (yyvsp[-2].expr) , (yyvsp[0].expr) ) ; }
#line 1630 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 174 "parser.y" /* yacc.c:1646  */
    { (yyval.biopexpr) = new AndExpr( (yyvsp[-2].expr) , (yyvsp[0].expr) ) ; }
#line 1636 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 175 "parser.y" /* yacc.c:1646  */
    { (yyval.biopexpr) = new MultExpr( (yyvsp[-2].expr) , (yyvsp[0].expr) ) ; }
#line 1642 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 177 "parser.y" /* yacc.c:1646  */
    { (yyval.stmtlist) = new StmtList() ; }
#line 1648 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 179 "parser.y" /* yacc.c:1646  */
    { (yyval.stmtlist) = new StmtList( (yyvsp[-1].stmtlist) , (yyvsp[0].stmt) ) ; }
#line 1654 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 182 "parser.y" /* yacc.c:1646  */
    { (yyval.mtddecllist) = new MtdDeclList( (yyvsp[-1].mtddecllist) , (yyvsp[0].mtddecl) ) ; }
#line 1660 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 183 "parser.y" /* yacc.c:1646  */
    { (yyval.mtddecllist) = new MtdDeclList ( new MtdDeclList() , (yyvsp[0].mtddecl) ) ; }
#line 1666 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 186 "parser.y" /* yacc.c:1646  */
    { (yyval.mtddecllist) = new MtdDeclList() ; }
#line 1672 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 188 "parser.y" /* yacc.c:1646  */
    { (yyval.mtddecllist) = new MtdDeclList( (yyvsp[0].mtddecllist) ) ; printf("haha\n");}
#line 1678 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 191 "parser.y" /* yacc.c:1646  */
    { (yyval.classdecllist) = new ClassDeclList() ; }
#line 1684 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 193 "parser.y" /* yacc.c:1646  */
    { (yyval.classdecllist) = new ClassDeclList( (yyvsp[-1].classdecllist) , (yyvsp[0].classdecl) ) ; }
#line 1690 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 196 "parser.y" /* yacc.c:1646  */
    { (yyval.exprlist) = new ExprList() ; }
#line 1696 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 198 "parser.y" /* yacc.c:1646  */
    { (yyval.exprlist) = new ExprList( new ExprList() , (yyvsp[0].expr) ) ; }
#line 1702 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 200 "parser.y" /* yacc.c:1646  */
    { (yyval.exprlist) = new ExprList( (yyvsp[-2].exprlist) , (yyvsp[0].expr) ) ;}
#line 1708 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 203 "parser.y" /* yacc.c:1646  */
    { (yyval.vardecllist) = new VarDeclList() ; }
#line 1714 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 204 "parser.y" /* yacc.c:1646  */
    { (yyval.vardecllist) = new VarDeclList( (yyvsp[-1].vardecllist) , (yyvsp[0].vardecl) ) ; }
#line 1720 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 207 "parser.y" /* yacc.c:1646  */
    { (yyval.vararglist) = new VarArgList() ; }
#line 1726 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 208 "parser.y" /* yacc.c:1646  */
    { (yyval.vararglist) = new VarArgList( new VarArgList() , (yyvsp[0].vararg) ) ; }
#line 1732 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 209 "parser.y" /* yacc.c:1646  */
    { (yyval.vararglist) = new VarArgList( (yyvsp[0].vararglist), (yyvsp[-2].vararg) ) ; }
#line 1738 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 212 "parser.y" /* yacc.c:1646  */
    { (yyval.ident) = new Ident( *(yyvsp[0].string)  ) ; std::cout<<(((yyval.ident))->name)<<std::endl; }
#line 1744 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 1748 "parser.tab.c" /* yacc.c:1646  */
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
#line 214 "parser.y" /* yacc.c:1906  */
