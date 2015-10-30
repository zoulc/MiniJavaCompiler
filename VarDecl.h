#include <iostream>
#include <vector>
#include "AstStruct.h"
#include "AstStruct.h"

class VarDecl {
public:
    Type* varType ;
    Ident* varIdent ;
    VarDecl( Type* _vT , Ident* _vI )
    : varType(_vT) , varIdent(_vI) {} ; 
};
