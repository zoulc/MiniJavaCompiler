#include <iostream>
#include <vector>
#include <llvm/Value.h>
#include "MJParser.h"

class GetMtdCallExpr : public Expr{
public:
    Expr * tarExpr ;
    MtdIdent mtdIdent ;
    ExprList fillList ;
    GetMtdCallExpr( Expr * _tE ,
                    MtdIdent & _mI ,
                    ExprList _fL )
    : tarExpr(_tE) , mtdIdent(_mI) , fillList(_fL) {}  ; 
};
