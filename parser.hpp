/* A Bison parser, made by GNU Bison 3.0.  */

/* Bison interface for Yacc-like parsers in C

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
    TWHILE = 302,
    TINVOKER = 303,
    TARROW = 304,
    TITFACE = 305,
    TIMPLEM = 306,
    TINSTANCEOF = 307,
    TOBJECT = 308
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 38 "parser.y" /* yacc.c:1909  */

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

#line 138 "parser.hpp" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
