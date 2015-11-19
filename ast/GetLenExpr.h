#include <iostream>
#include <vector>
#include "AstStruct.h"
#include "AstStruct.h"

class GetLenExpr : public Expr{
public:
    Expr * tarExpr ;
    GetLenExpr( Expr * _tE )
    : tarExpr(_tE) {} ; 
};
