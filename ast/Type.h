#include <iostream>
#include <vector>
#include "AstStruct.h"
#include "AstStruct.h"

class Type {
public:
    std::string typeName ;
    Type(){};
    Type( std::string _tN ) : typeName(_tN) {} ; 
    Type( Type * _t ) : typeName(_t->typeName) {} ; 
};

class IntType : public Type {
public:
    IntType() : Type("int") {} ;
};

class ArrType : public Type {
public:
    Type* elemType ;
    ArrType( Type* _e )
    : elemType(_e) , Type("Arr") {} ;
};

class BoolType : public Type {
public:
    BoolType() : Type("boolean") { } ;
};

class ClassIdentType : public Type {
public:
    Ident * classIdent ;
    ClassIdentType(Ident *_cI )
    : classIdent(_cI) , Type("Class") {} ;
};
