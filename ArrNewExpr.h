#include <iostream>
#include <vector>
#include "AstStruct.h"
#include "Expr.h"

class ArrNewExpr : public Expr {
public:
    Expr * sizeExpr ;
    ArrNewExpr( Expr * _sE )
    : sizeExpr(_sE) {} ;
};
