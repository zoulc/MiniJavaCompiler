#include <iostream>
#include <vector>
#include "AstStruct.h"
#include "AstStruct.h"

class IntLiterExpr : public Expr {
public:
    long long int value;
    IntLiterExpr( long long int _v )
    : value(_v) {} ;
};

class TrueLiterExpr : public Expr {
public:
    bool value ;
    TrueLiterExpr()
    : value(true) {} ;
};

class FalseLiterExpr : public Expr {
public:
    bool value ;
    FalseLiterExpr()
    : value(false) {} ;
};

Value*  IntLiterExpr :: codeGen()
{
	std::cout << "Creating integer literature: " << value << endl;
	return ConstantInt::get(Type::getInt64Ty(getGlobalContext()), value, true);
}

Value*  TrueLiterExpr :: codeGen()
{
	std::cout << "Creating bool literature: " << value << endl;
	return ConstantInt::get(Type::getInt1Ty(getGlobalContext()), value, false);
}

Value*  FalseLiterExpr :: codeGen()
{
	std::cout << "Creating bool literature: " << value << endl;
	return ConstantInt::get(Type::getInt1Ty(getGlobalContext()), value, false);
}
