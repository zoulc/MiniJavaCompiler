
/* LiterExpr.h */

Value*  IntLiterExpr :: codeGen()
{
	std::cout << "Creating integer literature: " << value << endl;
	return ConstantInt::get(Type::getInt64Ty(getGlobalContext()), value, true);
}

Value*  TrueLiterExpr :: codeGen()
{
	std::cout << "Creating bool literature: " << value << endl;
	return ConstantInt::get(Type::getInt64Ty(getGlobalContext()), value, false);
}

Value*  FalseLiterExpr :: codeGen()
{
	std::cout << "Creating bool literature: " << value << endl;
	return ConstantInt::get(Type::getInt64Ty(getGlobalContext()), value, false);
}

/* SiOpExpr.h */

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

/* Stmt.h */

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

/* StmtList.h*/

Value * StmtList::codegen()
{
	std::vector <class Stmt * > i;
	Value * res=NULL;
	for(i=stmtList.begin();i!=stmtList.end();i++)
		res=i->codegen();
	return res;
}
