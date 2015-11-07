#include <iostream>
#include <vector>
#include "AstStruct.h"
#include "Expr.h"

class SiOpExpr : public Expr{
public:
    Expr * tarExpr ;
    SiOpExpr( Expr * _tE )
    : tarExpr ( _tE)  {};
};

class NegExpr : public SiOpExpr {
public:
    NegExpr ( Expr * _tE )
    : SiOpExpr( _tE) {} ; 
};

class ParenExpr : public SiOpExpr {
public:
    ParenExpr ( Expr * _tE)
    : SiOpExpr( _tE ) {} ; 
};

Value* NegExpr::codeGen()
{
	std::cout << "Creating single operation Neg " << endl;
	return Builder.CreateISub(
				ConstantInt::get(Type::getInt64Ty(getGlobalContext()), 0, true),
				tarExpr->codeGen(context),
				"");
}

Value* ParenExpr::codeGen()
{
	std::cout << "Creating single operation Paren " << endl;
	return tarExpr->codeGen(context);
}

