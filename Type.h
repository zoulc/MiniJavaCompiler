#include <iostream>
#include <vector>
#include <llvm/Value.h>
#include "MJParser.h"

class Type {
public:
    std::string typeName ;
};

class IntType : public Type {
public:
    IntType() : typeName("int") {} ;
};

class ArrType : public Type {
public:
    Type* elemType ;
    ArrType( Type* _e )
    : elemType(_e) {} ;
};

class BoolType : public Type {
public:
    BoolType() : typeName("boolean") {} ;
};

class ClassIdentType : public Type {
public:
    Ident * classIdent ;
    ClassIdentType( ClassIdent _cI )
    : classIdent(_CI) {} ;
};
