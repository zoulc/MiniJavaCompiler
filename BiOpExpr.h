#include <iostream>
#include <vector>
#include <llvm/Value.h>
#include "MJParser.h"

class BiOpExpr : public Expr{
public:
    Expr * leftExpr ;
    Expr * rightExpr ;
    BiOpExpr( Epxr * _lE ,
              Expr * _rE ) ;
    : leftExpr(_lE), rightExpr(_rE) {};
};

class AddExpr : public BiOpExpr {
public:
    AddExpr ( Expr * lE ,
              Expr *  rE )
    {
        BiOpExpr( lE , rE ) ;
    }
};

class LessCmpExpr : public BiOpExpr {
public:
    LessCmpExpr ( Expr * lE ,
                  Expr *  rE )
    {
        BiOpExpr( lE , rE ) ;
    }
};

class AndExpr : public BiOpExpr {
public:
    AndExpr ( Expr * lE ,
                  Expr *  rE )
    {
        BiOpExpr( lE , rE ) ;
    }
};

class SubExpr : public BiOpExpr {
public:
    SubExpr ( Expr * lE ,
                  Expr *  rE )
    {
        BiOpExpr( lE , rE ) ;
    }
};

class MultExpr : public BiOpExpr {
public:
    MultExpr ( Expr * lE ,
                  Expr *  rE )
    {
        BiOpExpr( lE , rE ) ;
    }
};

class ArrAcsExpr : public BiOpExpr{
public:
    ArrAcsExpr ( Expr * lE ,
                  Expr *  rE )
    {
        BiOpExpr( lE , rE ) ;
    }
};
