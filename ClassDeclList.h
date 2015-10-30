#ifndef CLASSDECLLIST_H
#define CLASSDECLLIST_H
#include <iostream>
#include <vector>
#include "AstStruct.h"

class ClassDeclList {
public:
    std::vector<class ClassDecl *> declList;
    ClassDeclList(){};
    ClassDeclList( ClassDeclList* _cDL ,
                   ClassDecl* _cD )
    : declList(_cDL->declList)
    {
        declList.push_back(_cD);
    }
    ClassDeclList( ClassDeclList& _cDL ) : declList(_cDL.declList) {} ; 
    ClassDeclList( ClassDeclList* _cDL ) : declList(_cDL->declList) {} ; 
} ;
#endif
