#include <iostream>
#include <vector>
#include "AstStruct.h"
#include "Expr.h"

class ObjNewExpr : public Expr {
public:
    Ident * tarIdent ;
    ObjNewExpr( Ident * _tI )
    : tarIdent(_tI) {} ;
};
