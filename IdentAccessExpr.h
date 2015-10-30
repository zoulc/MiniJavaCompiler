#include <iostream>
#include <vector>
#include "AstStruct.h"
#include "Expr.h"
#include "Ident.h"

class IdentAccessExpr : public Expr {
public:
    Ident * tarIdent ;
    IdentAccessExpr( Ident * _tI )
    : tarIdent(_tI) {} ; 
};
