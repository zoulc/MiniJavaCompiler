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




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include "ArrNewExpr.cpp"
#include "BiOpExpr.cpp"
#include "ClassDecl.cpp"
#include "ClassDeclList.cpp"
#include "Expr.cpp"
#include "ExprList.cpp"
#include "GetLenExpr.cpp"
#include "GetMtdCallExpr.cpp"
#include "Ident.cpp"
#include "IdentAccessExpr.cpp"
#include "LiterExpr.cpp"
#include "MainClassDecl.cpp"
#include "MtdDecl.cpp"
#include "MtdDeclList.cpp"
#include "ObjNewExpr.cpp"
#include "Program.cpp"
#include "SiOpExpr.cpp"
#include "Stmt.cpp"
#include "StmtList.cpp"
#include "ThisExpr.cpp"
#include "Type.cpp"
#include "VarArg.cpp"
#include "VarArgList.cpp"
#include "VarDecl.cpp"
#include "VarDeclList.cpp"
    Program *programAst; /* the top level root node of our final AST */

    extern int yylex();
    void yyerror(const char *s) { printf("ERROR: %s\n", s); }

#line 98 "parser.cpp" /* yacc.c:339  */

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

    std::string *string;
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
    ClassDecl * classdecl ;
    VarDecl * vardecl ; 
    VarArg * vararg ; 
    std::string *string ;
    int token;

#line 209 "parser.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 224 "parser.cpp" /* yacc.c:358  */

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
#define YYLAST   275

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  52
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  137

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
       0,   104,   104,   108,   115,   118,   123,   127,   131,   137,
     138,   139,   140,   143,   144,   146,   148,   150,   152,   156,
     157,   158,   159,   161,   162,   163,   164,   165,   166,   168,
     170,   172,   176,   177,   178,   179,   180,   182,   183,   187,
     188,   192,   193,   197,   198,   200,   204,   205,   206,   209,
     210,   211,   214
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
  "biopexpr", "stmtlist", "mtddecllist", "classdecllist", "exprlist",
  "vardecllist", "vararglist", "ident", YY_NULLPTR
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

#define YYPACT_NINF -98

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-98)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -14,     7,    25,   -98,   -98,    20,   -98,    11,    14,     7,
     -98,    15,    -4,    19,     0,     7,    44,    47,   -98,   -98,
       7,     0,   -98,    67,    72,    53,    73,   -98,    41,     0,
      85,   -98,   -98,   -98,     0,   -98,     0,    93,     7,    51,
      94,   107,   -98,     7,     0,   108,   -98,     7,     3,   111,
     -98,   114,     0,   -98,     0,   126,     6,     0,   -98,   116,
     118,   132,   133,   -98,    65,     8,    54,   -98,    91,    91,
      91,    91,    91,    91,   -98,   -98,    91,   -98,   -98,    91,
     100,   -98,   147,   -98,   -98,   163,   179,   188,    90,   200,
     216,   237,   121,   135,    91,   125,    -2,    91,    91,    91,
      91,    91,    64,    64,   -98,   138,   143,   -98,    91,   137,
     237,   -98,   -98,   149,   246,   246,   248,   237,   115,   120,
     -98,    91,   -98,   131,   -98,    91,   -98,    64,   225,   -98,
     237,    58,   -98,   -98,   -98,    91,   237
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    41,    52,     0,     1,     2,     0,     0,
      42,     0,     0,     0,    46,     0,     0,    10,    11,    47,
       0,    39,    12,     0,     0,     0,     0,    48,     0,    46,
       0,     9,     6,     5,     0,    40,    39,     0,     0,     0,
       0,     0,     4,     0,    49,     0,    50,     0,     0,     0,
       7,     0,    49,    37,    46,    51,     0,    37,    37,     0,
       0,     0,     0,    38,     0,     0,     0,     3,     0,     0,
       0,     0,     0,     0,    13,    23,     0,    25,    24,     0,
       0,    27,     0,    19,    26,     0,     0,     0,     0,     0,
       0,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    17,     0,     0,    31,     0,     0,
      34,    16,    21,     0,    32,    33,    36,    35,     0,     0,
      15,     0,     8,     0,    29,    43,    20,     0,     0,    28,
      44,     0,    14,    18,    22,     0,    45
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -98,   -98,   -98,   -98,   -19,   -98,   -98,   -18,   -97,   -10,
     -98,    50,   128,   -98,   -98,   -22,   113,    -1
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    10,    19,    46,    35,    20,    63,    82,
      83,    56,    28,     7,   131,    21,    48,    84
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       5,     4,    27,     4,    17,   119,   120,    36,    12,     4,
       4,     4,    14,    22,    23,     1,    38,    27,    51,    26,
      22,    52,    58,    59,    58,     6,    47,    60,    22,    60,
     132,    15,    57,    22,    47,    22,     8,    41,    27,    18,
       9,   112,    45,    22,    73,    11,    50,    13,    61,    16,
      61,    22,    62,    22,    62,    64,    22,     4,    33,    85,
      86,    87,    88,    89,    64,    64,    90,     4,    42,    91,
      58,    74,    34,   134,    25,    60,   135,    24,    71,    93,
      58,    31,    34,    29,   110,    60,    30,   114,   115,   116,
     117,   118,    72,    32,     4,   113,    61,    75,   123,    94,
      62,    64,    64,     4,    92,    76,    61,    65,    66,    96,
      62,   128,    97,    98,    99,   130,   100,   101,   105,    37,
      40,    44,    43,    49,    94,   136,    64,    53,    77,    78,
      54,    79,    68,    67,    96,    80,    81,    97,    98,    99,
      94,   100,   101,   126,    52,   111,    69,    70,   108,   109,
      96,   121,   124,    97,    98,    99,    94,   100,   101,   129,
     122,   127,    95,   125,    39,    55,    96,     0,     0,    97,
      98,    99,    94,   100,   101,     0,     0,     0,   102,     0,
       0,     0,    96,     0,     0,    97,    98,    99,    94,   100,
     101,     0,     0,     0,   103,     0,     0,    94,    96,     0,
       0,    97,    98,    99,     0,   100,   101,    96,   104,    94,
      97,    98,    99,     0,   100,   101,     0,     0,     0,    96,
     106,     0,    97,    98,    99,    94,   100,   101,     0,     0,
       0,   107,     0,     0,    94,    96,     0,     0,    97,    98,
      99,     0,   100,   101,    96,   133,    94,    97,    98,    99,
       0,   100,   101,     0,     0,    94,    96,    94,     0,    97,
      98,    99,     0,   100,   101,    96,     0,    96,     0,     0,
      99,     0,   100,   101,   100,   101
};

static const yytype_int16 yycheck[] =
{
       1,     3,    21,     3,     4,   102,   103,    29,     9,     3,
       3,     3,    16,    14,    15,    29,    34,    36,    15,    20,
      21,    18,    16,    17,    16,     0,    44,    21,    29,    21,
     127,    35,    54,    34,    52,    36,    16,    38,    57,    39,
      29,    43,    43,    44,    36,    31,    47,    32,    42,    30,
      42,    52,    46,    54,    46,    56,    57,     3,    17,    69,
      70,    71,    72,    73,    65,    66,    76,     3,    17,    79,
      16,    17,    31,    15,    27,    21,    18,    33,    13,    80,
      16,    28,    31,    16,    94,    21,    14,    97,    98,    99,
     100,   101,    27,    20,     3,    96,    42,     6,   108,     9,
      46,   102,   103,     3,     4,    14,    42,    57,    58,    19,
      46,   121,    22,    23,    24,   125,    26,    27,    28,    34,
      27,    14,    28,    15,     9,   135,   127,    16,    37,    38,
      16,    40,    14,    17,    19,    44,    45,    22,    23,    24,
       9,    26,    27,    28,    18,    20,    14,    14,    27,    14,
      19,    13,    15,    22,    23,    24,     9,    26,    27,    28,
      17,    41,    15,    14,    36,    52,    19,    -1,    -1,    22,
      23,    24,     9,    26,    27,    -1,    -1,    -1,    15,    -1,
      -1,    -1,    19,    -1,    -1,    22,    23,    24,     9,    26,
      27,    -1,    -1,    -1,    15,    -1,    -1,     9,    19,    -1,
      -1,    22,    23,    24,    -1,    26,    27,    19,    20,     9,
      22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,    19,
      20,    -1,    22,    23,    24,     9,    26,    27,    -1,    -1,
      -1,    15,    -1,    -1,     9,    19,    -1,    -1,    22,    23,
      24,    -1,    26,    27,    19,    20,     9,    22,    23,    24,
      -1,    26,    27,    -1,    -1,     9,    19,     9,    -1,    22,
      23,    24,    -1,    26,    27,    19,    -1,    19,    -1,    -1,
      24,    -1,    26,    27,    26,    27
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    29,    48,    49,     3,    64,     0,    60,    16,    29,
      50,    31,    64,    32,    16,    35,    30,     4,    39,    51,
      54,    62,    64,    64,    33,    27,    64,    51,    59,    16,
      14,    28,    20,    17,    31,    53,    62,    34,    54,    59,
      27,    64,    17,    28,    14,    64,    52,    54,    63,    15,
      64,    15,    18,    16,    16,    63,    58,    62,    16,    17,
      21,    42,    46,    55,    64,    58,    58,    17,    14,    14,
      14,    13,    27,    36,    17,     6,    14,    37,    38,    40,
      44,    45,    56,    57,    64,    56,    56,    56,    56,    56,
      56,    56,     4,    64,     9,    15,    19,    22,    23,    24,
      26,    27,    15,    15,    20,    28,    20,    15,    27,    14,
      56,    20,    43,    64,    56,    56,    56,    56,    56,    55,
      55,    13,    17,    56,    15,    14,    28,    41,    56,    28,
      56,    61,    55,    20,    15,    18,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    50,    50,    51,    52,    53,    54,
      54,    54,    54,    55,    55,    55,    55,    55,    55,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    57,    57,    57,    57,    57,    58,    58,    59,
      59,    60,    60,    61,    61,    61,    62,    62,    62,    63,
      63,    63,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,    17,     8,     6,     3,     2,    13,     3,
       1,     1,     1,     3,     7,     5,     5,     4,     7,     1,
       4,     3,     6,     1,     1,     1,     1,     1,     5,     4,
       2,     3,     3,     3,     3,     3,     3,     0,     2,     0,
       2,     0,     2,     0,     1,     3,     0,     1,     2,     0,
       1,     3,     1
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
#line 105 "parser.y" /* yacc.c:1646  */
    { MJprogram = new Program( (yyvsp[-1].mainclassdecl) , (yyvsp[0].classdecllist) ) ; }
#line 1416 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 112 "parser.y" /* yacc.c:1646  */
    { (yyval.mainclassdecl) = new MainClassDecl( (yyvsp[-15].ident) , (yyvsp[-5].ident) , (yyvsp[-2].stmtlist) ) ; }
#line 1422 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 117 "parser.y" /* yacc.c:1646  */
    { (yyval.classecl) = new ClassDecl( (yyvsp[-6].ident) , (yyvsp[-4].ident) , (yyvsp[-2].vardecllist) , (yyvsp[-1].mtddecllist) ) ; }
#line 1428 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 120 "parser.y" /* yacc.c:1646  */
    { (yyval.classecl) = new ClassDecl( (yyvsp[-4].ident) , NULL , (yyvsp[-2].vardecllist) , (yyvsp[-1].mtddecllist) ) ; }
#line 1434 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 124 "parser.y" /* yacc.c:1646  */
    { (yyval.vardecl) = new VarDecl( (yyvsp[-2].type) , (yyvsp[-1].ident) ) ; }
#line 1440 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 128 "parser.y" /* yacc.c:1646  */
    { (yyval.vararg) = new VarArg( (yyvsp[-1].type), (yyvsp[0].ident) ) ; }
#line 1446 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 134 "parser.y" /* yacc.c:1646  */
    { (yyval.mtddecl) = new MtdDecl( (yyvsp[-11].type) , (yyvsp[-10].ident) , (yyvsp[-8].vararglist) , (yyvsp[-5].vardecllist) , (yyvsp[-4].stmtlist) , (yyvsp[-2].expr) );}
#line 1452 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 137 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = new ArrType( new IntType() ) ; }
#line 1458 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 138 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = new IntType() ; }
#line 1464 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 139 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = new BoolType() ; }
#line 1470 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 140 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = new ClassIdentType( (yyvsp[0].ident) ) ; }
#line 1476 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 143 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new BlockStmt((yyvsp[-1].stmtlist)) ; }
#line 1482 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 145 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new IfThenElseStmt( (yyvsp[-4].expr) , (yyvsp[-2].stmt) , (yyvsp[0].stmt) ) ; }
#line 1488 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 147 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new WhileStmt( (yyvsp[-2].expr) , (yyvsp[0].stmt) ) ; }
#line 1494 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 149 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new SysOutPrtStmt( (yyvsp[-2].expr) ) ; }
#line 1500 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 151 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new AssignStmt( (yyvsp[-3].ident) , (yyvsp[-1].expr) ) ; }
#line 1506 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 153 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new ArrAssignStmt( (yyvsp[-6].ident) , (yyvsp[-4].expr) , (yyvsp[-1].expr) ) ; }
#line 1512 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 156 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].biopexpr) ; }
#line 1518 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 157 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ArrAcsExpr( (yyvsp[-3].expr) , (yyvsp[-1].expr) ) ; }
#line 1524 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 158 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new GetLenExpr( (yyvsp[-2].expr) ) ; }
#line 1530 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 160 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new GetMtdCallExpr( (yyvsp[-5].expr) , (yyvsp[-3].ident) , (yyvsp[-1].exprlist) ) ; }
#line 1536 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 161 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new IntLiterExpr( atol((yyvsp[0].string)->c_str()) ) ; }
#line 1542 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 162 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new TrueLiterExpr( ) ; }
#line 1548 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 163 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new FalseLiterExpr( ) ; }
#line 1554 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 164 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new IdentAccesExpr( (yyvsp[0].ident) ) ; }
#line 1560 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 165 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ThisExpr( ) ; }
#line 1566 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 167 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ArrNewExpr( (yyvsp[-1].expr) ) ; }
#line 1572 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 169 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ObjNewExpr( (yyvsp[-2].ident) ) ; }
#line 1578 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 171 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new NegExpr( (yyvsp[0].expr) ) ; }
#line 1584 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 173 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ParenExpr( (yyvsp[-1].expr) ) ; }
#line 1590 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 176 "parser.y" /* yacc.c:1646  */
    { (yyval.biopexpr) = new AddExpr( (yyvsp[-2].expr) , (yyvsp[0].expr) ) ; }
#line 1596 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 177 "parser.y" /* yacc.c:1646  */
    { (yyval.biopexpr) = new SubExpr( (yyvsp[-2].expr) , (yyvsp[0].expr) ) ; }
#line 1602 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 178 "parser.y" /* yacc.c:1646  */
    { (yyval.biopexpr) = new LessCmpExpr( (yyvsp[-2].expr) , (yyvsp[0].expr) ) ; }
#line 1608 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 179 "parser.y" /* yacc.c:1646  */
    { (yyval.biopexpr) = new AndExpr( (yyvsp[-2].expr) , (yyvsp[0].expr) ) ; }
#line 1614 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 180 "parser.y" /* yacc.c:1646  */
    { (yyval.biopexpr) = new MultExpr( (yyvsp[-2].expr) , (yyvsp[0].expr) ) ; }
#line 1620 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 182 "parser.y" /* yacc.c:1646  */
    { (yyval.stmtlist) = new StmtList() ; }
#line 1626 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 184 "parser.y" /* yacc.c:1646  */
    { (yyval.stmtlist) = new StmtList( (yyvsp[-1].stmtlist) , (yyvsp[0].stmt) ) ; }
#line 1632 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 187 "parser.y" /* yacc.c:1646  */
    { (yyval.mtddecllist) = new MtdDeclList() ; }
#line 1638 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 189 "parser.y" /* yacc.c:1646  */
    { (yyval.mtddecllist) = new MtdDeclList( (yyvsp[-1].mtddecllist) , (yyvsp[0].mtddecl) ) ; }
#line 1644 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 192 "parser.y" /* yacc.c:1646  */
    { (yyval.classdecllist) = new ClassDeclList() ; }
#line 1650 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 194 "parser.y" /* yacc.c:1646  */
    { (yyval.classdecllist) = new ClassDeclList( (yyvsp[-1].classdecllist) , (yyvsp[0].classecl) ) ; }
#line 1656 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 197 "parser.y" /* yacc.c:1646  */
    { (yyval.exprlist) = new ExprList() ; }
#line 1662 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 199 "parser.y" /* yacc.c:1646  */
    { (yyval.exprlist) = new ExprList( new ExprList() , (yyvsp[0].expr) ) ; }
#line 1668 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 201 "parser.y" /* yacc.c:1646  */
    { (yyval.exprlist) = new ExprList( (yyvsp[-2].exprlist) , (yyvsp[0].expr) ) ;}
#line 1674 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 204 "parser.y" /* yacc.c:1646  */
    { (yyval.vardecllist) = new VarDeclList() ; }
#line 1680 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 205 "parser.y" /* yacc.c:1646  */
    { (yyval.vardecllist) = new VarDeclList( new VarDeclList() , (yyvsp[0].vardecl) ) ; }
#line 1686 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 206 "parser.y" /* yacc.c:1646  */
    { (yyval.vardecllist) = new VarDeclList( (yyvsp[-1].vardecllist) , (yyvsp[0].vardecl) ) ; }
#line 1692 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 209 "parser.y" /* yacc.c:1646  */
    { (yyval.vararglist) = new VarArgList() ; }
#line 1698 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 210 "parser.y" /* yacc.c:1646  */
    { (yyval.vararglist) = new VarArgList( new VarArgList() , (yyvsp[0].vararg) ) ; }
#line 1704 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 211 "parser.y" /* yacc.c:1646  */
    { (yyval.vararglist) = new VarArgList( (yyvsp[-2].vararglist), (yyvsp[0].vararglist) ) ; }
#line 1710 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 214 "parser.y" /* yacc.c:1646  */
    { (yyval.ident) = new Ident( (yyvsp[0].string) ) ; }
#line 1716 "parser.cpp" /* yacc.c:1646  */
    break;


#line 1720 "parser.cpp" /* yacc.c:1646  */
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
#line 216 "parser.y" /* yacc.c:1906  */

