#include <iostream>
#include <vector>
#include "AstStruct.h"
#include "MainClassDecl.h"
#include "ClassDeclList.h"

class Program {
public:
    MainClassDecl * mainClassDecl ;
    ClassDeclList classDeclList ;
    Program( MainClassDecl* _mC , ClassDeclList *_cD )
    : mainClassDecl(_mC) , classDeclList(_cD) {};
};
