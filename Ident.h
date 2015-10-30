#ifndef IDENT_H
#define IDENT_H
#include <iostream>
#include <vector>
#include "AstStruct.h"
#include "AstStruct.h"

class Ident {
public:
    std::string name ;
    Ident(){};
    Ident( std::string & _n ) : name(_n) {} ;  
};
#endif
