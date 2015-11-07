#include <iostream>
#include <vector>
#include "AstStruct.h"
#include "StmtList.h"

class Stmt {
public:
};

class BlockStmt : public Stmt{
public:
    StmtList stmtList ;
    BlockStmt( StmtList *_sL )
    : stmtList(_sL) {} ;
};

class IfThenElseStmt : public Stmt {
public:
    Expr* condExpr ;
    Stmt* thenStmt ,*elseStmt ;
    IfThenElseStmt( Expr * _cE ,
                    Stmt * _tS ,
                    Stmt * _eS )
    : condExpr(_cE) , thenStmt(_tS) , elseStmt(_eS) {};
};

Value* IfThenElseStmt::codegen()
{
	Value *CondV = condExpr->codegen();
	if (!CondV)
		return nullptr;
	
	// Convert condition to a bool by comparing equal to 0.0.
	CondV = Builder.CreateICmpNE(
		CondV,
		ConstantInt::get(Type::getInt64Ty(getGlobalContext()), 0, false),
	   	"ifcond");
	
	Function *TheFunction = Builder.GetInsertBlock()->getParent();
	
	// Create blocks for the then and else cases.  Insert the 'then' block at the
	// end of the function.
	BasicBlock *ThenBB =
		BasicBlock::Create(getGlobalContext(), "then", TheFunction);
	BasicBlock *ElseBB = BasicBlock::Create(getGlobalContext(), "else");
	BasicBlock *MergeBB = BasicBlock::Create(getGlobalContext(), "ifcont");
	
	Builder.CreateCondBr(CondV, ThenBB, ElseBB);
	
	// Emit then value.
	Builder.SetInsertPoint(ThenBB);
	
	Value *ThenV = thenStmt->codegen();
	if (!ThenV)
		return nullptr;
	
	Builder.CreateBr(MergeBB);
	// Codegen of 'Then' can change the current block, update ThenBB for the PHI.
	ThenBB = Builder.GetInsertBlock();
	
	// Emit else block.
	TheFunction->getBasicBlockList().push_back(ElseBB);
	Builder.SetInsertPoint(ElseBB);
	
	Value *ElseV = elseStmt->codegen();
	if (!ElseV)
		return nullptr;
	
	Builder.CreateBr(MergeBB);
	// Codegen of 'Else' can change the current block, update ElseBB for the PHI.
	ElseBB = Builder.GetInsertBlock();
	
	// Emit merge block.
	TheFunction->getBasicBlockList().push_back(MergeBB);
	Builder.SetInsertPoint(MergeBB);
	PHINode *PN =
	Builder.CreatePHI(Type::getDoubleTy(getGlobalContext()), 2, "iftmp");
	
	PN->addIncoming(ThenV, ThenBB);
	PN->addIncoming(ElseV, ElseBB);
	return PN;
}

class WhileStmt : public Stmt {
public:
    Expr* condExpr ;
    Stmt* bodyStmt ;
    WhileStmt( Expr * _cE , Stmt * _bS )
    : condExpr(_cE) , bodyStmt(_bS) {} ;
};

class SysOutPrtStmt : public Stmt {
public :
    Expr * prtExpr ;
    SysOutPrtStmt( Expr * _pE )
    : prtExpr(_pE) {} ;
};

class AssignStmt : public Stmt {
public :
    Ident * assignIdent ;
    Expr *     valueExpr ;
    AssignStmt( Ident * _aI ,
                Expr * _vE )
    : assignIdent(_aI) , valueExpr(_vE) {};
};

Value* AssignStmt::codegen()
{
	if(NamedValues[assignIdent]==0)
	{
		std::cout<<"Undefined Value\n";
		return nullptr;
	}
	Value * rval=valueExpr.codegen();
	Builder.CreateStore(rval,NamedValues[assignIdent->name]);
}


class ArrAssignStmt : public Stmt {
public:
    Ident * arrIdent ;
    Expr *     valueExpr ;
    Expr *     addressExpr ;
    ArrAssignStmt( Ident * _aI ,
                   Expr * _aE ,
                   Expr * _vE )
    : arrIdent(_aI) , addressExpr(_aE) ,
    valueExpr(_vE) {} ;
};

class VarDeclStmt : public Stmt { 
public:
    Type * type ; 
    Ident * varIdent ; 
    VarDeclStmt( Type* _t , Ident* _i ) : type(_t) , varIdent(_i) {} ; 
};

