#include <iostream>
#include <vector>
#include "AstStruct.h"

class VarArg {
public:
    Type * varType ;
    Ident * varIdent ;
    VarArg( Type* _vT , Ident* _vI )
    : varType(_vT) , varIdent(_vI) {} ;
};
