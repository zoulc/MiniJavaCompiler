#include <iostream>
#include <vector>
#include <llvm/Value.h>
#include "MJParser.h"

class Program {
public:
    MainClassDecl mainClassDecl ;
    ClassDeclList classDecList ;
    Program( MainClass& _mC , ClassDeclList _cD )
    : mainClass(_mC) , classDeclList(_cD) {};
};
