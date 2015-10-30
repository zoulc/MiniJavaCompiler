#include <iostream>
#include <vector>
#include "AstStruct.h"
#include "VarDeclList.h"
#include "MtdDeclList.h"

class ClassDecl {
public:
    Ident * classIdent ;
    Ident * extClassIdent ;
    VarDeclList varDeclList ;
    MtdDeclList mtdDeclList ;
    ClassDecl( Ident* _cI ,
               Ident* _eCI ,
               VarDeclList* _vDL ,
               MtdDeclList* _mDL ):
    classIdent(_cI) , extClassIdent(_eCI) ,
    varDeclList(_vDL) , mtdDeclList(_mDL) {};
};
