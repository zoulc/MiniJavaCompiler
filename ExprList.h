#include <iostream>
#include <vector>
#include "AstStruct.h"
#include "AstStruct.h"

class ExprList {
public:
    std::vector<class Expr *> fillList;
    ExprList(){};
    ExprList( ExprList* _eL ,
                   Expr* _e )
    : fillList(_eL->fillList)
    {
        fillList.push_back(_e);
    }
    ExprList( ExprList * _eL ) : fillList(_eL->fillList) {} ; 
    ExprList( ExprList & _eL ) : fillList(_eL.fillList) {} ; 
} ;
