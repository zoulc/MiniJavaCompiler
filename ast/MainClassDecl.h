#ifndef MAINCLASSDECL_H
#define MAINCLASSDECL_H
#include <iostream>
#include <vector>
#include "AstStruct.h"
#include "StmtList.h"

class MainClassDecl {
public:
    Ident *mainClassName;
    Ident *inputArgs;
    StmtList stmtList ;
    MainClassDecl( Ident * _mCN , Ident * _iA , StmtList * _sL )
    : mainClassName(_mCN) ,  inputArgs(_iA) , stmtList(_sL) {};
};
#endif
