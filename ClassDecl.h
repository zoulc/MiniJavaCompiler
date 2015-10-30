#include <iostream>
#include <vector>
#include <llvm/Value.h>
#include "MJParser.h"

class ClassDecl {
public:
    ClassIdent classIdent ;
    ClassIdent extClassIdent ;
    VarDeclList varDeclList ;
    MtdDeclList mtdDeclList ;
    ClassDecl( ClassIdent& _cI ,
               ClassIdent& _eCI ,
               VarDeclList& _vDL ,
               MtdDeclList& _mDL ):
    classIdent(_cI) , extClassIdent(_eCI) ,
    varDeclList(_vDL) , MthDeclList(_mDL) {};
}
