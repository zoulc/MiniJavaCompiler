#ifndef MTDDECLLIST_H
#define MTDDECLLIST_H
#include <iostream>
#include <vector>
#include "AstStruct.h"
#include "AstStruct.h"

class MtdDeclList {
public:
    std::vector< class MtdDecl *> declList ;
    MtdDeclList(){};
    MtdDeclList( MtdDeclList* _mDL ,
                   MtdDecl* _mD )
    : declList(_mDL->declList)
    {
        declList.push_back(_mD);
    }
    MtdDeclList( MtdDeclList * _mDL ) : declList(_mDL->declList) {} ; 
    MtdDeclList( MtdDeclList & _mDL ) : declList(_mDL.declList) {} ;
};
#endif
