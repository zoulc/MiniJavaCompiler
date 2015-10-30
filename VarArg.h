#include <iostream>
#include <vector>
#include <llvm/Value.h>
#include "MJParser.h"

class VarArg {
public:
    Type varType ;
    VarIdent varIdent ;
    VarArg( Type& _vT , VarIdent& _vI )
    : varType(_vT) , varIdent(_vI) {} ;
};
