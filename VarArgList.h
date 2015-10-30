#include <iostream>
#include <vector>
#include <llvm/Value.h>
#include "MJParser.h"

class VarArgList {
public:
    vector< class VarArg * > declList ;
    VarArglList( VarArgList* _vAL ,
                   VarArg* _vA )
    : declList(_vAL->declList)
    {
        declList.push_back(_vA);
    }
};
