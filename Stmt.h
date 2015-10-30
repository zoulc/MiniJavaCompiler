#include <iostream>
#include <vector>
#include <llvm/Value.h>
#include "MJParser.h"

class Stmt {
public:
};

class BlockStmt : public Stmt{
public:
    StmtList stmtList ;
    BlockStmt( StmtList _sL )
    : stmtList(_sL) {} ;
};

class IfThenElseStmt : public Stmt {
public:
    Expr* condExpr ;
    Stmt* thenStmt , elseStmt ;
    IfThenElseStmt( Expr * _cE ,
                    Stmt * _tS ,
                    Stmt * _eS )
    : condExpr(_cE) , thenStmt(_tS) , elseStmt(_eS) {};
};

class WhileStmt : public Stmt {
public:
    Expr* condExpr ;
    Stmt* bodyStmt ;
    WhileStmt( Expr * _cE , Stmt * _bS )
    : condExpr(_cE) , bodyStmt(_bS) {} ;
};

class SysOutPrtStmt : public Stmt {
public :
    Expr * prtExpr ;
    SysOutPrtStmt( Expr * _pE )
    : prtExpr(_pE) {} ;
};

class AssignStmt : public Stmt {
public :
    VarIdent * assignIdent ;
    Expr *     valueExpr ;
    AssignStmt( VarIdent * _aI ,
                Expr * _vE )
    : assignIdent(_aI) , valueExpr(_vE) ;
};

class ArrAssignStmt : public Stmt {
public:
    ArrIdent * arrIdent ;
    Expr *     valueExpr ;
    Expr *     addressExpr ;
    ArrAssignStmt( ArrIdent * _aI ,
                   Expr * _aE ,
                   Expr * _vE )
    : arrIdent(_aI) , addressExpr(_aE) ,
    valueExpr(_vE) {} ;
};
