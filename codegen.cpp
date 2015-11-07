
/* LiterExpr.h */
Value* Ident :: codeGen() { return NULL ; } 

Type* TypeInfo::typeGen() { return NULL ; } 

Value*  Expr :: codeGen() { return NULL ; }

Value*  Stmt :: codeGen() { return NULL ; }


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
	return Builder.CreateSub(
		ConstantInt::get(Type::getInt64Ty(getGlobalContext()), 0, true),
							  tarExpr->codeGen(),
							  "");
}

Value* ParenExpr::codeGen()
{
	std::cout << "Creating single operation Paren " << endl;
	return tarExpr->codeGen();
}

/* Stmt.h */

Value* IfThenElseStmt::codeGen()
{
	Value *CondV = condExpr->codeGen();
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
	
	Value *ThenV = thenStmt->codeGen();
	if (!ThenV)
		return nullptr;
	
	Builder.CreateBr(MergeBB);
	// Codegen of 'Then' can change the current block, update ThenBB for the PHI.
	ThenBB = Builder.GetInsertBlock();
	
	// Emit else block.
	TheFunction->getBasicBlockList().push_back(ElseBB);
	Builder.SetInsertPoint(ElseBB);
	
	Value *ElseV = elseStmt->codeGen();
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

Value* AssignStmt::codeGen()
{
	if(NamedValues[assignIdent->name]==0)
	{
		std::cout<<"Undefined Value\n";
		return nullptr;
	}
	Value * rval=valueExpr->codeGen();
	Builder.CreateStore(rval,NamedValues[assignIdent->name]);
}

/* StmtList.h*/

Value * StmtList::codeGen()
{
	std::vector <class Stmt * >::iterator i;
	Value * res=NULL;
	for(i=stmtList.begin();i!=stmtList.end();i++)
		res=(*i)->codeGen();
	return res;
}


llvm::Value* BiOpExpr::codeGen()
{
    /* TODO : Some Default check , because Binary Operation should not have an instance.*/
    cout<<" BiOpExpr Error : An Instance occured!\n" ;
}

llvm::Value* AddExpr::codeGen()
{
    return Builder.CreateAdd( leftExpr->codeGen() , rightExpr->codeGen() , "addtmp" );
}

llvm::Value* LessCmpExpr::codeGen()
{
    /* TODO : should lookup the tutorial book to the definitions */
    return Builder.CreateICmpULT( leftExpr->codeGen() , rightExpr->codeGen() , "ultcmptmp");
}

llvm::Value* AndExpr::codeGen()
{
    return Builder.CreateAnd( leftExpr->codeGen() , rightExpr->codeGen() , "andtmp");
}

llvm::Value* SubExpr::codeGen()
{
    return Builder.CreateSub( leftExpr->codeGen() , rightExpr->codeGen() , "addtmp" );
}

llvm::Value* MultExpr::codeGen()
{
    return Builder.CreateMul( leftExpr->codeGen() , rightExpr->codeGen() , "multmp" );
}

llvm::Type* IntType::typeGen()
{
    return Type::getInt64Ty(getGlobalContext()) ;
}

llvm::Type* BoolType::typeGen()
{
    return Type::getInt64Ty(getGlobalContext());
}

llvm::Value* BlockStmt::codeGen()
{
    Function *TheFunction = Builder.GetInsertBlock()->getParent();

    BasicBlock *CurBB = Builder.GetInsertBlock();

    if ( CurBB == NULL ){
        cout << " BlockStmt : Current Basic Block pointer is NULL\n";
        return NULL ;
    }
    BasicBlock *BodyBB =
        BasicBlock::Create(getGlobalContext(), "blockbody", TheFunction);
    Value* rtn = stmtList.codeGen();

    Builder.SetInsertPoint( CurBB ) ;
    return rtn ;
}

llvm::Value* WhileStmt::codeGen() {
    Function *TheFunction = Builder.GetInsertBlock()->getParent();

    Value * firstCond = condExpr->codeGen();
    if ( firstCond == NULL)
      return NULL;

    firstCond = Builder.CreateICmpNE(
  		firstCond,
  		ConstantInt::get(Type::getInt1Ty(getGlobalContext()), 0, false),
  	   	"whilefirstcondexpr");

    BasicBlock *BodyBB =
        BasicBlock::Create(getGlobalContext(), "whilebody" );
    BasicBlock *AfterBB =
        BasicBlock::Create(getGlobalContext(), "afterloop" );

    Builder.CreateCondBr( firstCond , BodyBB , AfterBB );

    TheFunction->getBasicBlockList().push_back( BodyBB );
    Builder.SetInsertPoint( BodyBB );
    if ( bodyStmt->codeGen() == NULL )
        return NULL;

    Value * whileLoopCond = condExpr->codeGen() ;
    whileLoopCond = Builder.CreateICmpNE(
  		whileLoopCond,
  		ConstantInt::get(Type::getInt1Ty(getGlobalContext()), 0, false),
  	   	"whileloopcondexpr");

    Builder.CreateCondBr(whileLoopCond, BodyBB, AfterBB);

    TheFunction->getBasicBlockList().push_back( AfterBB );
    Builder.SetInsertPoint(AfterBB);

    return Constant::getNullValue(Type::getDoubleTy(getGlobalContext()));
}

llvm::Value* VarDeclStmt::codeGen()
{
    /* TODO : TypeInfo's virtual method typeGen need implementation.*/
    Type* tarType = type->typeGen() ;
    if ( ! ( NamedValues[varIdent->name] == 0 ) ) {
        cout<<"VarDeclStmt : Redefinition of the same name."<<endl;
        return NULL ;
    }
    Value * targetValue =
        Builder.CreateAlloca( tarType , 0 , varIdent->name ) ;
    NamedValues[varIdent->name] = targetValue ;
    return targetValue ;
}

llvm::Value* IdentAccessExpr::codeGen() {
    if ( NamedValues[tarIdent->name] == 0 ) {
        printf(" IdentAccessExpr : Value Not Defined.") ;
    }
    return Builder.CreateLoad( NamedValues[tarIdent->name] , "loadvar" );
}

