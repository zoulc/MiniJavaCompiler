%{
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
%}

/* Represents the many different ways we can access our data */
%union {
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
}
/* Define our terminal symbols (tokens). This should
   match our tokens.l lex file. We also define the node type
   they represent.
 */
%token  TIDENT TINT TDOUBLE TNUMBER
%token  TCEQ TCNE TCLT TCGT TCLE TCGE TEQUAL
%token  TLPAREN TRPAREN TLBRACE TRBRACE TCOMMA TDOT
%token  TSEMICOLON TSYSOUT TSYSIN
%token  TPLUS TMINUS TMUL TDIV TAND
%token  TLF TRF
%token  TCLASS TVOID TPUBLIC TSTATIC TMAIN TSTRING
%token  TEXTENDS TRETURN
%token  TFALSE TTRUE
%token  TBOOL TBANG TELSE TIF TLENGT TNEW TTHIS TWHILE
%token  TINVOKER TARROW
%token  TITFACE  TIMPLEM
%token  TINSTANCEOF
%token  TOBJECT

/* Define the type of node our nonterminal symbols represent.
   The types refer to the %union declaration above. Ex: when
   we call an ident (defined by union type ident) we are really
   calling an (NIdentifier*). It makes the compiler happy.
 */

%type <ident> typeuseident vardeclident mtduseident classdeclident mtddeclident itfacedeclident varuseident argdeclident
%type <type> type
%type <expr> expr
%type <stmt> stmt
%type <biopexpr> biopexpr
%type <mainclassdecl> mainclassdecl
%type <mtddecllist> mtddecllist
%type <exprlist> exprlist
%type <stmtlist> stmtlist
%type <program> program
%type <classdecl> classdecl
%type <mtddecl> mtddecl
%type <vararglist> vararglist
%type <vardecllist> vardecllist
%type <vardecl> vardecl
%type <vararg> vararg
%type <string> TNUMBER TIDENT
%type <itfacedecl> itfacedecl
%type <absmtddecllist> absmtddecllist
%type <absmtddecl> absmtddecl
%type <extitface> extitface
%type <impitface> impitface
%type <extitfacelist> extitfacelist
%type <impitfacelist> impitfacelist

%left TPLUS TMINUS
%left TMUL TDIV

%start program

%%

program : mainclassdecl
         { programAst = new Program( $1 ) ; }
         | program classdecl
         { programAst->AddClassDecl( $2 ) ; }
         | program itfacedecl
         { programAst->AddItfaceDecl( $2 ) ; }
	 | program templateclassdecl
	 { }
        ;

mainclassdecl : TCLASS classdeclident TLBRACE TPUBLIC TSTATIC TVOID TMAIN TLPAREN TSTRING TLF TRF argdeclident TRPAREN TLBRACE stmtlist TRBRACE TRBRACE
                { $$ = new MainClassDecl( $2 , $12 , $15 ) ; }
              ;

extitface : itfacedeclident { $$ = new ExtItface( $1 ) ; } ;

impitface : itfacedeclident { $$ = new ImpItface( $1 ) ; } ;

extitfacelist :  /*blank*/ { $$ = new ExtItfaceList() ; }
            |   extitface { $$ = ( new ExtItfaceList() )->AddExtItface( $1 ) ; }
            |   extitfacelist TCOMMA extitface { $$ = $1 -> AddExtItface( $3 ) ; }
            ;

impitfacelist :/*blank*/ { $$ = new ImpItfaceList() ; }
            |   impitface { $$ = ( new ImpItfaceList() )->AddImpItface( $1 ) ; }
            |   impitfacelist TCOMMA impitface { $$ = $1 -> AddImpItface( $3 ) ; }
            ;

templateclassdecl : TCLASS classdeclident TCLT TIDENT TCGT TLBRACE vardecllist mtddecllist TRBRACE
		    { NamedTemplateClassDecls.insert(std::pair<std::string, TemplateClassDecl*>
			($2->name, new TemplateClassDecl( $2, *$4, NULL, new ImpItfaceList(), $7, $8))); }
		  | TCLASS classdeclident TCLT TIDENT TCGT TEXTENDS classdeclident TLBRACE vardecllist mtddecllist TRBRACE
		    { NamedTemplateClassDecls.insert(std::pair<std::string, TemplateClassDecl*>
			($2->name, new TemplateClassDecl( $2, *$4, $7, new ImpItfaceList(), $9, $10))); }

classdecl : TCLASS classdeclident TEXTENDS classdeclident TIMPLEM impitfacelist TLBRACE vardecllist mtddecllist TRBRACE
            { $$ = new ClassDecl( $2 , $4 , $6 , $8 , $9 ) ;  }
          | TCLASS classdeclident TEXTENDS classdeclident TLBRACE vardecllist mtddecllist TRBRACE
            { $$ = new ClassDecl( $2 , $4 , new ImpItfaceList() , $6 , $7 ) ;  }
          | TCLASS classdeclident TIMPLEM impitfacelist TLBRACE vardecllist mtddecllist TRBRACE
            { $$ = new ClassDecl( $2 , NULL , $4 , $6 , $7 ) ;  }
          | TCLASS classdeclident TLBRACE vardecllist mtddecllist TRBRACE
            { $$ = new ClassDecl( $2 , NULL , new ImpItfaceList() , $4 , $5 ) ; }
          ;

itfacedecl :TITFACE itfacedeclident TEXTENDS extitfacelist TLBRACE absmtddecllist TRBRACE
            { $$ = new ItfaceDecl( $2 , $4 , $6 ) ; }
        |   TITFACE itfacedeclident TLBRACE absmtddecllist TRBRACE
            { $$ = new ItfaceDecl( $2 , new ExtItfaceList() , $4 ) ; }
        ;

vardecl : type vardeclident TSEMICOLON
          { $$ = new VarDecl( $1 , $2 ) ; }
        ;

vararg  : type vardeclident
          { $$ = new VarArg( $1, $2 ) ; }
        ;

mtddecl : TPUBLIC type mtddeclident TLPAREN vararglist TRPAREN TLBRACE stmtlist TRETURN expr TSEMICOLON TRBRACE
         { $$ = new MtdDecl( $2 , $3 , $5 , $8 , $10 ); }
         ;

absmtddecl : TPUBLIC type mtddeclident TLPAREN vararglist TRPAREN TSEMICOLON
            { $$ = new AbsMtdDecl( $2 , $3 , $5 ); }
        ;

type : TINT TLF TRF { $$ = new ArrType( new IntType() ) ; }
     | TINT { $$ = new IntType() ; }
     | TBOOL  { $$ = new BoolType() ; }
     | TINVOKER { $$ = new InvokerType() ; }
     | typeuseident TCLT TIDENT TCGT  { $$ = new TemplateUsrDefIdentType( $1, *$3); }
     | typeuseident TCLT TINT TCGT { $$ = new TemplateUsrDefIdentType( $1, string("int") ); }
     | typeuseident  { $$ = new UsrDefIdentType( $1 ) ; }
     ;

stmt : TLBRACE stmtlist TRBRACE { $$ = new BlockStmt($2) ; }
     | TIF TLPAREN expr TRPAREN stmt TELSE stmt
       { $$ = new IfThenElseStmt( $3 , $5 , $7 ) ; }
     | TWHILE TLPAREN expr TRPAREN stmt
       { $$ = new WhileStmt( $3 , $5 ) ; }
     | TSYSOUT TLPAREN expr TRPAREN TSEMICOLON
       { $$ = new SysOutPrtStmt( $3 ) ; }
     | varuseident TEQUAL expr TSEMICOLON
       { $$ = new AssignStmt( $1 , $3 ) ; }
     | varuseident TLF expr TRF TEQUAL expr TSEMICOLON
       { $$ = new ArrAssignStmt( $1 , $3 , $6 ) ; }
     | type vardeclident TSEMICOLON
       { $$ = new VarDeclStmt( $1 , $2 ) ; }
     ;

expr : biopexpr { $$ = $1 ; }
     | TSYSIN TLPAREN TRPAREN { $$ = new SysInReadExpr( ) ; }
     | expr TLF expr TRF { $$ = new ArrAcsExpr( $1 , $3 ) ; }
     | expr TDOT TLENGT { $$ = new GetLenExpr( $1 ) ; }
     | expr TDOT mtduseident TLPAREN exprlist TRPAREN
      { $$ = new GetMtdCallExpr( $1 , $3 , $5 ) ; }
     | TNUMBER { $$ = new IntLiterExpr( atol($1->c_str()) ) ; }
     | TTRUE { $$ = new TrueLiterExpr( ) ; }
     | TFALSE { $$ = new FalseLiterExpr( ) ; }
     | vardeclident { $$ = new IdentAccessExpr( $1 ) ; }
     | TTHIS { $$ = new ThisExpr( ) ; }
     | TNEW TINT TLF expr TRF
       { $$ = new ArrNewExpr( $4 ) ; }
     | TNEW typeuseident TCLT TIDENT TCGT TLPAREN TRPAREN
       { $$ = new TemplateObjNewExpr( $2, *$4 ); }
     | TNEW typeuseident TCLT TINT TCGT TLPAREN TRPAREN
       { $$ = new TemplateObjNewExpr( $2, string("int") ); }
     | TNEW typeuseident TLPAREN TRPAREN
       { $$ = new ObjNewExpr( $2 ) ; }
     | TBANG expr
       { $$ = new NegExpr( $2 ) ; }
     | TLPAREN expr TRPAREN
       { $$ = new ParenExpr( $2 ) ; }
     | TLPAREN vararglist TRPAREN TARROW TLBRACE stmtlist TRETURN expr TSEMICOLON TRBRACE
       { $$ = new LamdaGenExpr( $2 , $6 , $8 ) ; }
     | varuseident TLPAREN exprlist TRPAREN
       { $$ = new LamdaAppExpr( $1 , $3 ) ; }
     | expr TINSTANCEOF type
       { $$ = new InsOfExpr( $1 , $3 ) ; }
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
         | mtddecllist mtddecl { $$ = new MtdDeclList( $1 , $2 ) ; }
         | mtddecl { $$ = new MtdDeclList ( new MtdDeclList() , $1 ) ; }
         ;

absmtddecllist : absmtddecllist absmtddecl { $$ = new AbsMtdDeclList( $1 , $2 ) ; }
         | absmtddecl { $$ = new AbsMtdDeclList ( new AbsMtdDeclList() , $1 ) ; }
         ;


exprlist : /*blank*/ { $$ = new ExprList() ; }
         | expr
           { $$ = new ExprList( new ExprList() , $1 ) ; }
         | exprlist TCOMMA expr
           { $$ = new ExprList( $1 , $3 ) ;}
         ;

vardecllist : /*blank*/ { $$ = new VarDeclList() ; }
         | vardecllist vardecl { $$ = new VarDeclList( $1 , $2 ) ; }
	 ;

vararglist : /*blank*/ { $$ = new VarArgList() ; }
   	 | vararg { $$ = new VarArgList( new VarArgList() , $1 ) ; }
	 | vararg TCOMMA vararglist { $$ = new VarArgList( $3, $1 ) ; }
	 ;

itfacedeclident : TIDENT { $$ = new ItfaceDeclIdent( *$1  ) ;  }

classdeclident : TIDENT { $$ = new ClassDeclIdent( *$1  ) ;  }

vardeclident : TIDENT { $$ = new VarDeclIdent( *$1  ) ;  }

argdeclident : TIDENT { $$ = new ArgDeclIdent( *$1  ) ;  }

mtddeclident : TIDENT { $$ = new MtdDeclIdent( *$1  ) ;  }

varuseident : TIDENT { $$ = new VarUseIdent( *$1  ) ;  }

typeuseident : TIDENT { $$ = new TypeUseIdent( *$1  ) ;  }

mtduseident : TIDENT { $$ = new MtdUseIdent( *$1  ) ;  }

%%
