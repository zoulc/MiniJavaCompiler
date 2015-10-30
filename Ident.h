#include <iostream>
#include <vector>
#include <llvm/Value.h>
#include "MJParser.h"

class Ident {
public:
    std::string name ;
    Ident( string & _n ) : name(_n) {} ;  
};
