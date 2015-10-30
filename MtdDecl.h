#include <iostream>
#include <vector>
#include <llvm/Value.h>
#include "MJParser.h"

class MtdDecl {
public:
    MtdIdent mtdIdent ;
    Type     rtnType ;
    VarArgList varArgList ;
    VarDeclList varDeclList ;
    StmtList    stmtList ;
    Expr    rtnExpr ;
    MtdDecl( MtdIdent* _mI ,
             Type* _rT ,
             VarArgList* _vAL ,
             VarDeclList* _vDL ,
             StmtList* _sL ,
             Expr* _rE) :
    mtdIdent(_mI) , rtnType(_rT) ,
    varArgList(_vAL) , varDeclList(_vDL) ,
    stmtList(_sL) , rtnExpr(_rE) {} ; 
};
