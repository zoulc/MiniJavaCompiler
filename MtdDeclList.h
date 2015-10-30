#include <iostream>
#include <vector>
#include <llvm/Value.h>
#include "MJParser.h"

class MtdDeclList {
public:
    vector< class MtdDecl > declList ;
    MtdDeclList( MtdDeclList& _mDL ,
                   MtdDecl& _mD )
    : declList(_mDL->declList)
    {
        declList.push_back(_mD);
    }
};
