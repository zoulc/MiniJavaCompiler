#include <iostream>
#include <vector>
#include <llvm/Value.h>
#include "MJParser.h"

class SiOpExpr : public Expr{
public:
    Expr * tarExpr ;
    BiOpExpr( Epxr * _tE ) ;
    : tarExpr ( _tE)  {};
};

class NegExpr : public SiOpExpr {
public:
    NegExpr ( Expr * _tE )
    {
        SiOpExpr( _teE) ;
    }
};

class ParenExpr : public SiOpExpr {
public:
    ParenExpr ( Expr * _tE)
    {
        SiOpExpr( _tE ) ; 
    }
}
