#include <iostream>
#include <vector>
#include <llvm/Value.h>
#include "MJParser.h"

class ExprList {
public:
    vector<class Expr *> fillList;
    ExprList( ExprList& _eL ,
                   Expr& _e )
    : fillList(_eL->fillList)
    {
        declList.push_back(_e);
    }
} ;
