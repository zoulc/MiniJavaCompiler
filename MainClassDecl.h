#include <iostream>
#include <vector>
#include <llvm/Value.h>
#include "MJParser.h"

class MainClassDecl {
public:
    ClassIdent mainClassName;
    VarIdent inputArgs;
    StmtList stmtList ;
    MainClassDecl( Ident & _mCN , Ident & _iA , StmtList & _sL )
    : mainClassName(_mCN) ,  inputArgs(_iA) , stmtList(_sL) {};
};
