
/* LiterExpr.h */
Value* Ident :: codeGen() { return NULL ; }

Type* TypeInfo::typeGen() {
	tarType = NULL ;
	return NULL ;
}

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
		ConstantInt::get(Type::getInt1Ty(getGlobalContext()), 0, false),
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
	// codeGen of 'Then' can change the current block, update ThenBB for the PHI.
	ThenBB = Builder.GetInsertBlock();

	// Emit else block.
	TheFunction->getBasicBlockList().push_back(ElseBB);
	Builder.SetInsertPoint(ElseBB);

	Value *ElseV = elseStmt->codeGen();
	if (!ElseV)
		return nullptr;

	Builder.CreateBr(MergeBB);
	// codeGen of 'Else' can change the current block, update ElseBB for the PHI.
	ElseBB = Builder.GetInsertBlock();

	// Emit merge block.
	TheFunction->getBasicBlockList().push_back(MergeBB);
	Builder.SetInsertPoint(MergeBB);
	/*PHINode *PN =
	Builder.CreatePHI(Type::getInt64Ty(getGlobalContext()), 2, "iftmp");

	PN->addIncoming(ThenV, ThenBB);
	PN->addIncoming(ElseV, ElseBB);
	return PN;*/
	return Constant::getNullValue(Type::getInt64Ty(getGlobalContext()));
}

Value* AssignStmt::codeGen()
{
	if(NamedValues[assignIdent->name]==0)
	{
		std::cout<<"Undefined Value\n";
		return nullptr;
	}
	Value * rval=valueExpr->codeGen();
	std::cout << "Creating Assignment statement" << endl;
	return Builder.CreateStore(rval,NamedValues[assignIdent->name]);
	std::cout << "Store instruction created" << endl;
}

/* StmtList.h*/

Value * StmtList::codeGen()
{
	std::vector <class Stmt * >::iterator i;
	Value * res=Constant::getNullValue(Type::getInt64Ty(getGlobalContext()));
	for(i=stmtList.begin();i!=stmtList.end();i++)
		res=(*i)->codeGen();
	return res;
}


llvm::Value* BiOpExpr::codeGen()
{
    /* TODO : Some Default check , because Binary Operation should not have an instance.*/
    cout<<" BiOpExpr Error : An Instance occured!\n" ;
    return NULL;
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
	tarType = Type::getInt64Ty(getGlobalContext());
    return Type::getInt64Ty(getGlobalContext()) ;
}

llvm::Type* BoolType::typeGen()
{
	tarType = Type::getInt64Ty(getGlobalContext());
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

    return Constant::getNullValue(Type::getInt64Ty(getGlobalContext()));
}

llvm::Value* VarDeclStmt::codeGen()
{
    /* TODO : TypeInfo's virtual method typeGen need implementation.*/
    Type* tarType = type->typeGen() ;
    if ( ! ( NamedValues[varIdent->name] == 0 ) ) {
        std::cout<<"VarDeclStmt : Redefinition of the same name."<<std::endl;
        return NULL ;
    }
    Value * targetValue =
        Builder.CreateAlloca( tarType , 0 , varIdent->name ) ;
    NamedValues[varIdent->name] = targetValue ;
    return targetValue ;
}

llvm::Value* IdentAccessExpr::codeGen() {
    if ( NamedValues[tarIdent->name] == 0 ) {
        std::cout<<" [Generate] IdentAccessExpr : Value Not Defined."<<std::endl ;
    }
    return Builder.CreateLoad( NamedValues[tarIdent->name] , "loadvar" );
}

llvm::Type* VarDecl::getLLVMType()
{
	if (llvmType) return llvmType ;
	llvmType = varType->typeGen();
	return llvmType ;
}

void Program::ClassInitial() {
	std::vector<class ClassDecl*>::iterator cit ;
	for ( cit = classDeclList.declList.begin() ;
		  cit != classDeclList.declList.end() ; cit ++ ) {
		(*cit)->codeGen();
 	}
}


ClassDecl* ClassDecl::getBaseClass() {
	if ( extClassIdent == NULL ) return NULL ;
	if ( baseClass ) return baseClass ;
	if ( extClassIdent != NULL ) {
		std::string extClassName = extClassIdent->name ;
		if ( NamedClassDecls[extClassName] == 0 ) {
			std::cout<<" [Check] ClassDecl "<<classIdent->name<<"'s base class hasn't been defined."<<std::endl;
			return NULL ;
		}
		baseClass = NamedClassDecls[extClassName] ;
		std::vector<class VarDecl*>::iterator vit;
		for( vit = (baseClass->fieldDecl).begin() ;
			 vit !=(baseClass->fieldDecl).end() ; vit++ ) {
			fieldDecl.push_back((*vit));
			llvm::Type* itType = (*vit)->getLLVMType();
			if ( itType == NULL ) {
				std::cout<<" [Check] ClassDecl "<<classIdent->name<<
				"'s field which named "<< (*vit)->varIdent->name << std::endl;
				return NULL ;
			}
			fieldName2Pos[(*vit)->varIdent->name] = fieldDecl.size();
		}

		std::vector<class MtdDecl*>::iterator mit;
		for( mit = (baseClass->mtdDecl).begin() ;
			 mit !=(baseClass->mtdDecl).end() ; mit++ ) {
			if ( mtdName2Pos.count((*mit)->mtdIdent->name) == 0 ) {
				mtdName2Pos[(*mit)->mtdIdent->name] = mtdDecl.size() ;
				mtdDecl.push_back((*mit));
				continue ;
			}
			int mtd_id = mtdName2Pos[(*mit)->mtdIdent->name] ;
			mtdDecl[mtd_id] = ((*mit));
		}
	}
	return NULL ;
}

llvm::Type* ClassDecl::getClassLLVMType() {
	if ( classLLVMType ) return classLLVMType ;
	getBaseClass();
	std::string className = classIdent->name ;
	if ( NamedClassDecls[className] != 0 ) {
		std::cout<<" [Check] Class "<<className<<" have multiple difintion."<<std::endl;
		return NULL ;
	}
	NamedClassDecls[className] = this ;

	//make an oblique identified class type , then fill some thing into it.
	classLLVMType = StructType::create(Builder.getContext() , className );

	std::vector<class VarDecl*>::iterator vit;
	for( vit = (varDeclList.declList).begin() ;
	     vit != (varDeclList.declList).end() ; vit++ ) {
		llvm::Type* itType = (*vit)->getLLVMType();
		if ( itType == NULL ) {
			std::cout<<" [Check] ClassDecl "<<classIdent->name<<
			"'s field which named "<< (*vit)->varIdent->name << std::endl;
			return NULL ;
		}
		fieldDecl.push_back((*vit));
		fieldName2Pos[(*vit)->varIdent->name] = fieldDecl.size();
	}

	std::vector<class MtdDecl*>::iterator mit;
	for( mit = (mtdDeclList.declList).begin() ;
		 mit !=(mtdDeclList.declList).end() ; mit++ ) {
	    if ( mtdName2Pos.count((*mit)->mtdIdent->name) == 0 ) {
			mtdName2Pos[(*mit)->mtdIdent->name] = mtdDecl.size() ;
 			mtdDecl.push_back((*mit));
 			continue ;
 		}
 		int mtd_id = mtdName2Pos[(*mit)->mtdIdent->name] ;
 		mtdDecl[mtd_id] = ((*mit));
	}

	std::vector<llvm::Type*> classTypeVec;
	classTypeVec.clear();

	//push the VTable of Function into the classTypeVec
	classTypeVec.push_back( getVTableType()->getPointerTo() );

	//push the fields' types into the class TypeVec
	std::vector<class VarDecl*>::iterator it;
	for( it = fieldDecl.begin() ;
	     it != fieldDecl.end() ; it++ ) {
		llvm::Type* itType = (*it)->getLLVMType();
		classTypeVec.push_back( itType ) ;
	}

	((StructType*)classLLVMType)->setBody( classTypeVec ) ;
	return classLLVMType ;
}

llvm::Type* ClassDecl::getVTableType(){
	if ( vtableType ) return vtableType ;
	getBaseClass();
	//make an oblique identified class type , then fill some thing into it.
	vtableType = StructType::create(Builder.getContext() , (classIdent->name) + std::string("_vtable"));

	std::vector<llvm::Type*> vtableTypeVec;
	std::vector<class MtdDecl*>::iterator mit;
	for( mit = mtdDecl.begin() ;
		 mit != mtdDecl.end() ; mit++ ) {
		vtableTypeVec.push_back( (*mit)->getFunctionType() );
	}
	((StructType*)vtableType)->setBody( vtableTypeVec );
	return vtableType ;
}

void ClassDecl::setNamedField( llvm::Value* thisClass )
{
	Value * selClass = Builder.CreateLoad( thisClass ) ;
	std::vector<class VarDecl*>::iterator it;
	for( it = fieldDecl.begin() ;
	     it != fieldDecl.end() ; it++ ) {
		NamedValues[ (*it)->varIdent->name ]
			= Builder.CreateStructGEP( (*it)->getLLVMType() , selClass ,
									   fieldName2Pos[(*it)->varIdent->name] );
	}
}

int ClassDecl::getMethodId(std::string mtdName)
{
	if ( mtdName2Pos.count(mtdName) == 0 ) {
		std::cout<<" [ Check ] getMethodId : "<<mtdName<<" is not a valid method."<<std::endl;
		return -1 ;
	}
	return mtdName2Pos[mtdName];
}

llvm::Type* ClassDecl::getMethodType(std::string mtdName)
{
	if ( mtdName2Pos.count(mtdName) == 0 ) {
		std::cout<<" [ Check ] getMethodId : "<<mtdName<<" is not a valid method."<<std::endl;
		return NULL ;
	}
	int mtd_id = mtdName2Pos[mtdName];
	return mtdDecl[mtd_id]->getFunctionType();
}

llvm::Value* ClassDecl::getVTableLoc()
{
	if (vtableLoc) return vtableLoc ;
	getVTableType();

	std::vector< Constant* > vtableFuncVec ;

	std::vector<class MtdDecl*>::iterator mit;
	for( mit = mtdDecl.begin() ;
		 mit != mtdDecl.end() ; mit++ ) {
		vtableFuncVec.push_back( (*mit)->getFunction() );
	}

	llvm::ArrayRef< Constant* > vtableInitial(vtableFuncVec);

	vtableLoc = new GlobalVariable( *TheModule,
		getVTableType(), true, GlobalValue::ExternalLinkage ,
		ConstantStruct::get( (StructType*)getVTableType() , vtableInitial ) ,
		classIdent->name + std::string("_vatble_loc") );

	return vtableLoc;
}

llvm::Value* ClassDecl::codeGen()
{
	std::vector<class MtdDecl*>::iterator mit;
	for( mit = (mtdDeclList.declList).begin() ;
		 mit != (mtdDeclList.declList).end() ; mit++ ) {
		(*mit)->codeGen();
	}
    return Constant::getNullValue(Type::getInt64Ty(getGlobalContext()));
}




Value * GetMtdCallExpr::codeGen()
{
	vector <Value*> arg;
	arg.push_back(tarExpr->codeGen());
	int i;
	for(i=0;i<(fillList.fillList.size());i++)
		arg.push_back(fillList.fillList[i]->codeGen());
	ArrayRef<Value*> argRef(arg);
	Type * MtdType=NamedClassDecls[arg[0]->getType()->getStructName()]->getMethodType(mtdIdent->name);
	Value * MtdId=ConstantInt::get(Type::getInt64Ty(getGlobalContext()),NamedClassDecls[arg[0]->getType()->getStructName()]->getMethodId(mtdIdent->name), true);
	Value * my_vtable=Builder.CreateLoad(MtdType->getPointTo(),arg[0]);
	Value * my_func_p=Builder.CreateGEP(my_vtable,MtdId);
	Value * my_func=Builder.CreateLoad(my_func_p);
	return Builder.CreateCall(my_func,argRef);
}

Type * MtdDecl::getFunctionType()
{
	if(func==NULL)
		func=Function::Create(FunctionType::get(rtnType,varArgList.getTypeArray(Owner->getClassLLVMType()),false),Function::ExternalLinkage,mtdIdent->name,TheModule);
	return func->getFunctionType();	
}

Function * MtdDecl::codeGen()
{
	BasicBlock * OldBB=Builder.GetInsertBlock();
	BasicBlock * func_entry=
        BasicBlock::Create(getGlobalContext(),"", func);
	NamedValues.clear();
	Function::ArgumentListType & ArgL=func->getArgumentList();
	Function::ArgumentListType::iterator Argi=ArgL.begin();
	setNamedField(*(ArgL.begin()));
	int j=0;
	for(Argi=ArgL.begin(),Argi++;Argi!=ArgL.end();j++,Argi++)
		NamedValues[varArgList.declList[j]->varIdent->name]=Argi;
	StmtList.codeGen();
	Value * retval;
	retval=rtnExpr->codeGen();
	Builder.CreateRet(retval);
	Builder.SetInsertPoint(OldBB);
}

Function * MtdDecl::getFunction()
{
	getFunctionType();
	codeGen();
	return func;
}

Value* ObjNewExpr::codeGen()
{
	Value *var = new GlobalVariable(TheModule,NamedClassDecls[tarIden->name]->getClassLLVMType(),false,GlobalValue::ExternalLinkage);
	Build.CreateLoad(NamedClassDecls[tarIdent->name]->getVTableLoc(),var);
	return var;
}

void VarArgList::codeGen(Type* ClassType)
{
	if(!__codeGen)return;
	vector<Type*> t;
	t.clear();
	t.push_back(ClassType);
	int i,n=declList.size();
	for(;i<n;i++)
		t.push_back(declList[i]->varType);
	TypeArray.copy(t);
	__codeGen=1;
}

ArrayRef<Type*>* VarArgList::getTypeArray(Type * ClassType)
{
	codeGen(ClassType);
	return &TypeArray;
}




