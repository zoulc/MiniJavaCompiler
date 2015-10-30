#include <iostream>
#include <vector>
#include <llvm/Value.h>
#include "MJParser.h"

class ArrNewExpr : public Expr {
public:
    Expr * sizeExpr ;
    ArrNewExpr( Expr * _sE )
    : sizeExpr(_sE) {} ;
}
