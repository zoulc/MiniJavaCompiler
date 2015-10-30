#ifndef VARDECLLIST_H
#define VARDECLLIST_H
#include <iostream>
#include <vector>
#include "AstStruct.h"
#include "AstStruct.h"

class VarDeclList {
public:
    std::vector< class VarDecl * > declList ;
    VarDeclList(){};
    VarDeclList( VarDeclList* _vDL ,
                   VarDecl* _vD )
    : declList(_vDL->declList)
    {
        declList.push_back(_vD);
    }
    VarDeclList( VarDeclList& _vDL ) : declList(_vDL.declList) {} ; 
    VarDeclList( VarDeclList* _vDL ) : declList(_vDL->declList) {} ; 
};
#endif
