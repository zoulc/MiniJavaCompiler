%{
//    #include "miniJavaParser.h"
    Program *MJprogram; /* the top level root node of our final AST */

    extern int yylex();
    void yyerror(const char *s) { printf("ERROR: %s\n", s); }
%}

/* Represents the many different ways we can access our data */
%union {
    Node *node;
    NBlock *block;
    NExpression *expr;
    NStatement *stmt;
    NIdentifier *ident;
    NVariableDeclaration *var_decl;
    std::vector *varvec;
    std::vector *exprvec;
    std::string *string;
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
%token  TPLUS TMINUS TMUL TDIV 
%token  TLF TRF
%token  TEQUAL

/* Define the type of node our nonterminal symbols represent.
   The types refer to the %union declaration above. Ex: when
   we call an ident (defined by union type ident) we are really
   calling an (NIdentifier*). It makes the compiler happy.
 */

%type ident 
%type type
%type expr stmt
%type biopexpr
%type mainclassdecl classdecllist mtddecllist exprlist stmtlist
%type program
%type classdecl mtddecl

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

classDecl : TCLASS ident TEXTENDS ident TLBRACE
            vardecllist mtddeclist TRBRACE
            { $$ = new ClassDecl( $2 , $4 , $6 , $7 ) ; }
          | TCLASS ident TLBRACE
            vardecllist mtddeclist TRBRACE
            { $$ = new ClassDecl( $2 , NULL , $4 , $5 ) ; }
          ;

vardecl : type ident TSEMICOLON
          { $$ = new VarDecl( $1 , $2 ) ; }
          ;

mtddecl : TPUBLIC type ident LPAREN vararglist
          RPAREN LBRACE vardecllist stmtlist TRETUN
          expr TSEMICOLON TRBRACE
         { $$ = new MtdDecl( $2 , $3 , $5 , $8 , $9 , $11 );}
         ;

type : TINT TLF TRF { $$ = new ArrType( new IntType() ) ; }
     | TINT { $$ = new IntType() ; }
     | TBOOL  { $$ = new BoolType() ; }
     | ident  { $$ = new ClassIdentType( $1 ) ; }
     ;

stmt : LBRACE stmtlist RBRACE { $$ = new BlockStmt($2) ; }
     | TIF TLPAREN expr TRPAREN stmt TELSE stmt
       { $$ = new IfThenElseStmt( $3 , $5 , $7 ) ; }
     | TWHILE LPAREN expr RPAREN stmt
       { $$ = new WhileStmt( $3 , $5 ) ; }
     | TSYSOUT LPAREN expr RPAREN TSEMICOLON
       { $$ = new SysOutPrtStmt( $3 ) ; }
     | ident TEQUAL expr TSEMICOLON
       { $$ = new AssignStmt( $1 , $3 ) ; }
     | ident TLF expr TRF TEQUAL expr TSEMICOLON
       { $$ = new ArrAssignStmt( $1 , $3 , $6 ) ; }
     ;

expr : biopexpr { $$ = $1 ; }
     | expr LTF expr RTF { $$ = new ArrAcsExpr( $1 , $2 ) ; }
     | expr TDOT TLENGT { $$ = new GetLenExpr( $1 ) ; }
     | expr TDOT ident TLPAREN exprlist TRPAREN
      { $$ = new GetMtdCallExpr( $1 , $3 , $5 ) ; }
     | TNUMBER { $$ = new IntLiterExpr( atol($1->c_str()) ) ; }
     | TTRUE { $$ = new TrueLiterExpr( ) ; }
     | TFALSE { $$ = new FalseLiterExpr( ) ; }
     | ident { $$ = new IdentAccesExpr( $1 ) ; }
     | TTHIS { $$ = new ThisExpr( $1 ) ; }
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
         | expr TAND epxr { $$ = new AndExpr( $1 , $3 ) ; }
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

ident : TIDENT { $$ = new Ident(*$1) ; }

%%
