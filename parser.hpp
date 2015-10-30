/* A Bison parser, made by GNU Bison 3.0.2.  */

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
#line 30 "myParser.y" /* yacc.c:1909  */

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
    std:string *string ;
    int token;

#line 125 "parser.hpp" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
