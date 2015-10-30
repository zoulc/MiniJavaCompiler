%{
    #include "AstStruct.h"
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
    Program *programAst; /* the top level root node of our final AST */

    extern int yylex();
    void yyerror(const char *s) { printf("ERROR: %s\n", s); }
%}

/* Represents the many different ways we can access our data */
%union {
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
}
/* Define our terminal symbols (tokens). This should
   match our tokens.l lex file. We also define the node type
   they represent.
 */
%token  TIDENT TINT TDOUBLE TNUMBER
%token  TCEQ TCNE TCLT TCLE TCGT TCGE TEQUAL
%token  TLPAREN TRPAREN TLBRACE TRBRACE TCOMMA TDOT
%token  TSEMICOLON TSYSOUT
%token  TPLUS TMINUS TMUL TDIV TAND 
%token  TLF TRF
%token  TCLASS TVOID TPUBLIC TSTATIC TMAIN TSTRING
%token  TEXTENDS TRETURN 
%token  TFALSE TTRUE 
%token  TBOOL TBANG TELSE TIF TLENGT TNEW TTHIS TWHILE  

/* Define the type of node our nonterminal symbols represent.
   The types refer to the %union declaration above. Ex: when
   we call an ident (defined by union type ident) we are really
   calling an (NIdentifier*). It makes the compiler happy.
 */

%type <ident> ident 
%type <type> type
%type <expr> expr 
%type <stmt> stmt
%type <biopexpr> biopexpr
%type <mainclassdecl> mainclassdecl 
%type <classdecllist> classdecllist 
%type <mtddecllist> mtddecllist 
%type <exprlist> exprlist 
%type <stmtlist> stmtlist
%type <program> program
%type <classecl> classdecl 
%type <mtddecl> mtddecl
%type <vararglist> vararglist
%type <vardecllist> vardecllist
%type <vardecl> vardecl
%type <vararg> vararg
%type <string> TNUMBER TIDENT 

%left TPLUS TMINUS
%left TMUL TDIV

%start program

%%

program : mainclassdecl classdecllist
         { MJprogram = new Program( $1 , $2 ) ; }
        ;

mainclassdecl : TCLASS ident TLBRACE TPUBLIC TSTATIC
                TVOID TMAIN TLPAREN TSTRING TLF
                TRF ident TRPAREN TLBRACE stmtlist
                TRBRACE TRBRACE
                { $$ = new MainClassDecl( $2 , $12 , $15 ) ; }
              ;

classdecl : TCLASS ident TEXTENDS ident TLBRACE
            vardecllist mtddecllist TRBRACE
            { $$ = new ClassDecl( $2 , $4 , $6 , $7 ) ; }
          | TCLASS ident TLBRACE
            vardecllist mtddecllist TRBRACE
            { $$ = new ClassDecl( $2 , NULL , $4 , $5 ) ; }
          ;

vardecl : type ident TSEMICOLON
          { $$ = new VarDecl( $1 , $2 ) ; }
        ;

vararg  : type ident 
          { $$ = new VarArg( $1, $2 ) ; } 
        ;

mtddecl : TPUBLIC type ident TLPAREN vararglist
          TRPAREN TLBRACE vardecllist stmtlist TRETURN
          expr TSEMICOLON TRBRACE
         { $$ = new MtdDecl( $2 , $3 , $5 , $8 , $9 , $11 );}
         ;

type : TINT TLF TRF { $$ = new ArrType( new IntType() ) ; }
     | TINT { $$ = new IntType() ; }
     | TBOOL  { $$ = new BoolType() ; }
     | ident  { $$ = new ClassIdentType( $1 ) ; }
     ;

stmt : TLBRACE stmtlist TRBRACE { $$ = new BlockStmt($2) ; }
     | TIF TLPAREN expr TRPAREN stmt TELSE stmt
       { $$ = new IfThenElseStmt( $3 , $5 , $7 ) ; }
     | TWHILE TLPAREN expr TRPAREN stmt
       { $$ = new WhileStmt( $3 , $5 ) ; }
     | TSYSOUT TLPAREN expr TRPAREN TSEMICOLON
       { $$ = new SysOutPrtStmt( $3 ) ; }
     | ident TEQUAL expr TSEMICOLON
       { $$ = new AssignStmt( $1 , $3 ) ; }
     | ident TLF expr TRF TEQUAL expr TSEMICOLON
       { $$ = new ArrAssignStmt( $1 , $3 , $6 ) ; }
     ;

expr : biopexpr { $$ = $1 ; }
     | expr TLF expr TRF { $$ = new ArrAcsExpr( $1 , $3 ) ; }
     | expr TDOT TLENGT { $$ = new GetLenExpr( $1 ) ; }
     | expr TDOT ident TLPAREN exprlist TRPAREN
      { $$ = new GetMtdCallExpr( $1 , $3 , $5 ) ; }
     | TNUMBER { $$ = new IntLiterExpr( atol($1->c_str()) ) ; }
     | TTRUE { $$ = new TrueLiterExpr( ) ; }
     | TFALSE { $$ = new FalseLiterExpr( ) ; }
     | ident { $$ = new IdentAccesExpr( $1 ) ; }
     | TTHIS { $$ = new ThisExpr( ) ; }
     | TNEW TINT TLF expr TRF
       { $$ = new ArrNewExpr( $4 ) ; }
     | TNEW ident TLPAREN TRPAREN
       { $$ = new ObjNewExpr( $2 ) ; }
     | TBANG expr
       { $$ = new NegExpr( $2 ) ; }
     | TLPAREN expr TRPAREN
       { $$ = new ParenExpr( $2 ) ; }
     ;

biopexpr : expr TPLUS expr { $$ = new AddExpr( $1 , $3 ) ; }
         | expr TMINUS expr { $$ = new SubExpr( $1 , $3 ) ; }
         | expr TCLT expr { $$ = new LessCmpExpr( $1 , $3 ) ; }
         | expr TAND expr { $$ = new AndExpr( $1 , $3 ) ; }
         | expr TMUL expr { $$ = new MultExpr( $1 , $3 ) ; }

stmtlist : /*blank*/ { $$ = new StmtList() ; }
         | stmtlist stmt
          { $$ = new StmtList( $1 , $2 ) ; }
         ;

mtddecllist : /*blank*/ { $$ = new MtdDeclList() ; }
         | mtddecllist mtddecl
           { $$ = new MtdDeclList( $1 , $2 ) ; }
         ;

classdecllist : /*blank*/ { $$ = new ClassDeclList() ; }
         | classdecllist classdecl
           { $$ = new ClassDeclList( $1 , $2 ) ; }
         ;

exprlist : /*blank*/ { $$ = new ExprList() ; }
         | expr
           { $$ = new ExprList( new ExprList() , $1 ) ; }
         | exprlist TCOMMA expr
           { $$ = new ExprList( $1 , $3 ) ;}
         ;

vardecllist : /*blank*/ { $$ = new VarDeclList() ; }
         | vardecl { $$ = new VarDeclList( new VarDeclList() , $1 ) ; } 
         | vardecllist vardecl { $$ = new VarDeclList( $1 , $2 ) ; }
	 ;

vararglist : /*blank*/ { $$ = new VarArgList() ; } 
   	 | vararg { $$ = new VarArgList( new VarArgList() , $1 ) ; }
    	 | vararglist TCOMMA vararglist { $$ = new VarArgList( $1, $3 ) ; } 
	 ; 

ident : TIDENT { $$ = new Ident( $1 ) ; }

%%
