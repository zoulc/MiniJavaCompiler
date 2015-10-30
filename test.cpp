#include <iostream>
#include "AstStruct.h"
extern Program* programAst ; 
extern int yyparse();

int main()
{
    yyparse();
    std::cout << programAst << endl ; 
    return 0 ;
}
