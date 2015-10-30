#include <iostream>
#include <vector>
#include <llvm/Value.h>
#include "MJParser.h"

class IdentAccessExpr : public Expr {
public:
    Ident * tarIdent ;
    IdentAccesExpr( Ident * _tI )
    : tarIdent(_tI) {} ; 
}
