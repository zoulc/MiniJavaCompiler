#include <iostream>
#include <vector>
#include <llvm/Value.h>
#include "MJParser.h"

class ClassDeclList {
public:
    vector<class ClassDecl *> declList;
    ClassDeclList( ClassDeclList& _cDL ,
                   ClassDecl& _cD )
    : declList(_cDL->declList)
    {
        declList.push_back(_cD);
    }
} ;
