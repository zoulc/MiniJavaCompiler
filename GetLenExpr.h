#include <iostream>
#include <vector>
#include <llvm/Value.h>
#include "MJParser.h"

class GetLenExpr : public Expr{
public:
    Expr * tarExpr ;
    GetLenExpr( Expr * _tE )
    : tarExpr(_tE) {} ; 
};
