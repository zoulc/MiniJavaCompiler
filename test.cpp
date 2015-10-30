#include <iostream>
#include "AstStruct.h"
extern Program* programAst ; 
extern int yyparse();

int main()
{
    yyparse();
    std::cout << programAst << std::endl ; 
    return 0 ;
}
