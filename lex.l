%{
#include <string>
#include "AstStruct.h"
#include "parser.hpp"

#define SAVE_TOKEN	yylval.string = new std::string(yytext, yyleng)
#define TOKEN(t)	(yylval.token = t)
%}

%option noyywrap

delim		[ \t\n\r]
ws		{delim}+
letter		[A-Za-z]
digit		[0-9]
identifier	(_|{letter})(_|{digit}|{letter})*
number		{digit}+
comment		\/\/[^\n]*

%%
{comment}		{}
{ws}			{}
"Object"        return TOKEN(TOBJECT);
"instanceof"    return TOKEN(TINSTANCEOF);
"interface"     return TOKEN(TITFACE);
"implements"     return TOKEN(TIMPLEM);
"Invoker"       return TOKEN(TINVOKER);
"class"			return TOKEN(TCLASS);
"public"		return TOKEN(TPUBLIC);
"static"		return TOKEN(TSTATIC);
"void"			return TOKEN(TVOID);
"main"			return TOKEN(TMAIN);
"String"		return TOKEN(TSTRING);
"extends"		return TOKEN(TEXTENDS);
"return"		return TOKEN(TRETURN);
"this"			return TOKEN(TTHIS);
"int"			return TOKEN(TINT);
"boolean"		return TOKEN(TBOOL);
"if"			return TOKEN(TIF);
"else"			return TOKEN(TELSE);
"while"			return TOKEN(TWHILE);
"true"			return TOKEN(TTRUE);
"false"			return TOKEN(TFALSE);
"new"			return TOKEN(TNEW);
"length"		return TOKEN(TLENGT);
"System.out.println"	return TOKEN(TSYSOUT);
"System.out.putc"	return TOKEN(TSYSOUTCHAR);
"System.in.read"	return TOKEN(TSYSIN);
"System.in.getc"	return TOKEN(TSYSINCHAR);
{identifier}		SAVE_TOKEN; return TIDENT;
{number}		SAVE_TOKEN; return TNUMBER;
"("			return TOKEN(TLPAREN);
")"			return TOKEN(TRPAREN);
"["			return TOKEN(TLF);
"]"			return TOKEN(TRF);
"{"			return TOKEN(TLBRACE);
"}"			return TOKEN(TRBRACE);
"&&"			return TOKEN(TAND);
"<"			return TOKEN(TCLT);
">"			return TOKEN(TCGT);
"=="			return TOKEN(TCEQ);
"!="			return TOKEN(TCNE);
"+"			return TOKEN(TPLUS);
"-"			return TOKEN(TMINUS);
"*"			return TOKEN(TMUL);
"!"			return TOKEN(TBANG);
"="			return TOKEN(TEQUAL);
"."			return TOKEN(TDOT);
","			return TOKEN(TCOMMA);
";"			return TOKEN(TSEMICOLON);
"->"        return TOKEN(TARROW);
.			{ printf("unrecognized: %s\n", yytext); }
%%
