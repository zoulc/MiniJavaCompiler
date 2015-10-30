#include <iostream>
#include <vector>
#include <llvm/Value.h>
#include "MJParser.h"

class VarDeclList {
public:
    vector< class VarDecl * > declList ;
    VarDeclList( VarDeclList& _vDL ,
                   VarDecl& _vD )
    : declList(_vDL->declList)
    {
        declList.push_back(_vD);
    }
};
