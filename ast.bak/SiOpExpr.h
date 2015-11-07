#include <iostream>
#include <vector>
#include "AstStruct.h"
#include "Expr.h"

class SiOpExpr : public Expr{
public:
    Expr * tarExpr ;
    SiOpExpr( Expr * _tE )
    : tarExpr ( _tE)  {};
};

class NegExpr : public SiOpExpr {
public:
    NegExpr ( Expr * _tE )
    : SiOpExpr( _tE) {} ; 
};

class ParenExpr : public SiOpExpr {
public:
    ParenExpr ( Expr * _tE)
    : SiOpExpr( _tE ) {} ; 
};
