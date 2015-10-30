#include <iostream>
#include <vector>
#include <llvm/Value.h>
#include "MJParser.h"

class ObjNewExpr : public Expr {
public:
    Ident * tarIdent ;
    ObjNewExpr( Ident * _tI )
    : sizeExpr(_tI) {} ;
}
