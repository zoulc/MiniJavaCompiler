#ifndef MTDECL_H
#define MTDECL_H
#include <iostream>
#include <vector>
#include "AstStruct.h"
#include "StmtList.h"
#include "VarArgList.h"
#include "VarDeclList.h"

class MtdDecl {
public:
    Ident *mtdIdent ;
    Type  *rtnType ;
    VarArgList varArgList ;
    StmtList    stmtList ;
    Expr    *rtnExpr ;
    MtdDecl( Type* _rT ,
             Ident* _mI ,
             VarArgList* _vAL ,
             StmtList* _sL ,
             Expr* _rE) :
    mtdIdent(_mI) , rtnType(_rT) ,
    varArgList(_vAL) , 
    stmtList(*_sL) , rtnExpr(_rE) {} ; 
};
#endif
