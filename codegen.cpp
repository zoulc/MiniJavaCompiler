/* Type Checking*/









/* LiterExpr.h */
Value* Ident :: codeGen() { return NULL ; }

Type* TypeInfo::llvmTypeGen() {
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

llvm::Type* IntType::llvmTypeGen()
{
	tarType = Type::getInt64Ty(getGlobalContext());
    return Type::getInt64Ty(getGlobalContext()) ;
}

llvm::Type* BoolType::llvmTypeGen()
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
    //BasicBlock::Create(getGlobalContext(), "", TheFunction);
    Value* rtn = stmtList.codeGen();

    //Builder.SetInsertPoint( CurBB ) ;
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
    /* TODO : TypeInfo's virtual method llvmTypeGen need implementation.*/
    Type* tarType = type->llvmTypeGen() ;
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
	llvmType = varType->llvmTypeGen();
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
	std::cout << " [ IR ] < getBaseClass > Class " << classIdent->name << " now is processing on its base class ."<< std::endl ;
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
	std::cout << " [ IR ] < getClassLLVMType > Class " << classIdent->name << " now is processing on its LLVM type ."<< std::endl ;
	getBaseClass();
	std::string className = classIdent->name ;
	if ( NamedClassDecls[className] != 0 ) {
		std::cout<<" [Check] Class "<<className<<" have multiple difintion."<<std::endl;
		return NULL ;
	}
	NamedClassDecls[className] = this ;

	//make an oblique identified class type , then fill some thing into it.
	std::cout << " [ IR ] < getClassLLVMType > Class " << classIdent->name << " create a oblique identifed type ."<< std::endl ;
	classLLVMType = StructType::create(Builder.getContext() , className );

	std::cout << " [ IR ] < getClassLLVMType > Class " << classIdent->name << " initialize the fields ."<< std::endl ;
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

	std::cout << " [ IR ] < getClassLLVMType > Class " << classIdent->name << " initialize the methods ."<< std::endl ;
	std::vector<class MtdDecl*>::iterator mit;
	for( mit = (mtdDeclList.declList).begin() ;
		 mit !=(mtdDeclList.declList).end() ; mit++ ) {
	    std::cout << " [ IR ] < getClassLLVMType > Add the method "<<(*mit)->mtdIdent->name<<" to Class "<<classIdent->name<<std::endl;
	    if ( mtdName2Pos.count((*mit)->mtdIdent->name) == 0 ) {
			mtdName2Pos[(*mit)->mtdIdent->name] = mtdDecl.size() ;
 			(*mit)->Owner = this ; 
			mtdDecl.push_back((*mit));
 			continue ;
 		}
 		int mtd_id = mtdName2Pos[(*mit)->mtdIdent->name] ;
 		mtdDecl[mtd_id] = (*mit);
                (*mit)->Owner = this ; 
	}

	std::vector<llvm::Type*> classTypeVec;
	classTypeVec.clear();

	//push the VTable of Function into the classTypeVec
	std::cout << " [ IR ] < getClassLLVMType > Class " << classIdent->name << " initial the VTable's type ."<< std::endl ;
	classTypeVec.push_back( getVTableType()->getPointerTo() );

	//push the fields' types into the class TypeVec
	std::cout << " [ IR ] < getClassLLVMType > Class " << classIdent->name << " fill the whole type ."<< std::endl ;
	std::vector<class VarDecl*>::iterator it;
	for( it = fieldDecl.begin() ;
	     it != fieldDecl.end() ; it++ ) {
		llvm::Type* itType = (*it)->getLLVMType();
		classTypeVec.push_back( itType ) ;
	}
	cast<StructType>(classLLVMType)->setBody( classTypeVec ) ;
	return classLLVMType ;
}

llvm::Type* ClassDecl::getVTableType()
{
	if ( vtableType ) return vtableType ;
	std::cout << " [ IR ] < getVTableType > Class " << classIdent->name << " now is processing on its VTable's LLVM type ."<< std::endl ;
	getBaseClass();
	//make an oblique identified class type , then fill some thing into it.
	std::cout << " [ IR ] < getVTableType > Class " << classIdent->name << " create an oblique type ."<< std::endl ;
	vtableType = StructType::create(Builder.getContext() , (classIdent->name) + std::string("_vtable"));

	std::cout << " [ IR ] < getVTableType > Class " << classIdent->name << " get the methods' types and fill the whole VTable type ."<< std::endl ;
	std::vector<llvm::Type*> vtableTypeVec;
	vtableTypeVec.clear();
	std::vector<class MtdDecl*>::iterator mit;
	for( mit = mtdDecl.begin() ; mit != mtdDecl.end() ; mit++ ) {
		std::cout << " [ IR ] < getVTableType > Add method " << (*mit)->mtdIdent->name << " to vtable ."<<std::endl;
		vtableTypeVec.push_back( (*mit)->getFunctionType());
	}
	
	cast<StructType>(vtableType)->setBody( vtableTypeVec );
	std::cout << " [ IR ] < getVTableType > Class " << classIdent->name << " 's VTable's type has been processed successfully ."<< std::endl ;
	return vtableType ;
}

void ClassDecl::setNamedField( llvm::Value* thisClass )
{
	if ( ! ( isa<PointerType>( thisClass->getType() ) ) ) {
		std::cout<<" [ IR ] < setNamedField > Error : type is not compatible."<<std::endl;
	}
	Value * selClass = Builder.CreateLoad( thisClass ) ; 
	if ( ! ( selClass->getType() == getClassLLVMType() ) ) {
		std::cout<<" [ IR ] < setNamedField > Error : the pointer's type is not correct."<<std::endl;
	}
	Value * test = Builder.CreateAlloca( getClassLLVMType() ) ; 
	if ( ! ( test->getType()  == getClassLLVMType()->getPointerTo() ) ) {
		std::cout<<" Testing ! Error occurs ! " <<std::endl;
	}
	std::vector<class VarDecl*>::iterator it;
	for( it = fieldDecl.begin() ;
	     it != fieldDecl.end() ; it++ ) {
		std::cout<<" [ IR ] < setNamedField > Add the field "<<(*it)->varIdent->name<<" at Pos :"<< fieldName2Pos[(*it)->varIdent->name]<<" into NamedValues ."<<std::endl;
		NamedValues[ (*it)->varIdent->name ]
			= Builder.CreateStructGEP( getClassLLVMType() , thisClass , fieldName2Pos[(*it)->varIdent->name] );
	}
	cout<<"Reached here."<<endl;
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
	std::cout << " [ IR ] < getVTableLoc > Class " << classIdent->name << " now is processing on its VTable's Global Location ."<< std::endl ;
	if (vtableLoc) return vtableLoc ;
	getVTableType();

	std::vector< Constant* > vtableFuncVec ;

	std::cout << " [ IR ] < getVTableLoc > Class " << classIdent->name << " fill's the initial data with the Virtual Functions."<< std::endl ;
	std::vector<class MtdDecl*>::iterator mit;
	for( mit = mtdDecl.begin() ;
		 mit != mtdDecl.end() ; mit++ ) {
		vtableFuncVec.push_back( cast<Function>((*mit)->getFunction()) );
		//
		//if ( (cast<Function>((*mit)->getFunction()))->getType() != (cast<FunctionType>((*mit)->getFunctionType()))) {
		//	std::cout<<" Fucking ! " <<endl;
		//}
	}

	std::cout << " [ IR ] < getVTableLoc > Class " << classIdent->name << " generate the initial constants ."<< std::endl ;
	llvm::ArrayRef< Constant* > vtableInitial(vtableFuncVec);

	std::cout << " [ IR ] < getVTableLoc > Class " << classIdent->name << " generate the global table with constants ."<< std::endl ;
	vtableLoc = new GlobalVariable( *TheModule,
		cast<StructType>(getVTableType()), true, GlobalValue::ExternalLinkage ,
		ConstantStruct::get( cast<StructType>(getVTableType()) , vtableInitial ) ,
		classIdent->name + std::string("_vatble_loc") );

	return vtableLoc;
}

llvm::Value* ClassDecl::codeGen()
{
    std::cout << " [ IR ] < ClassDecl::codeGen > Class " << classIdent->name << " now is processing ."<< std::endl ;
    getClassLLVMType();
    std::vector<class MtdDecl*>::iterator mit;
    for( mit = mtdDecl.begin() ;
	mit != mtdDecl.end() ; mit++ ) {
	cout<< (*mit)->mtdIdent->name << endl;
	(*mit)->getFunction();
    }
    std::cout << " [ IR ] < ClassDecl::codeGen > Class " << classIdent->name << " has been generated successfuly ."<< std::endl ;
    return Constant::getNullValue(Type::getInt64Ty(getGlobalContext()));
}

Value * GetMtdCallExpr::codeGen()
{
    std::cout << " [ IR ] < CetMtdCallExpr::codeGen > now is processing."<< std::endl ;
	vector <Value*> arg;
	arg.push_back(tarExpr->codeGen());
	int i;
	for(i=0;i<(fillList.fillList.size());i++)
		arg.push_back(fillList.fillList[i]->codeGen());
	ArrayRef<Value*> argRef(arg);
	//cout<<"Check point 4"<<endl;
	//cout<<(arg[0]->getType())->isPointerTy()<<endl;
	//cout<<(arg[0]->getType())->isStructTy()<<endl;
	string ClassName="Tester";
	Type * MtdType=NamedClassDecls[ClassName]->getMethodType(mtdIdent->name);
	Value * MtdId=ConstantInt::get(Type::getInt64Ty(getGlobalContext()),NamedClassDecls[ClassName]->getMethodId(mtdIdent->name), true);
	if ( MtdId == NULL ) {
    		std::cout << " [ IR ] < CetMtdCallExpr::codeGen > Error : Method not found."<< std::endl ;
	}
	Value * my_vtable=Builder.CreateLoad(Builder.CreateStructGEP(NamedClassDecls[ClassName]->getClassLLVMType(),arg[0],0));
	Value * my_func_p=Builder.CreateStructGEP(NamedClassDecls[ClassName]->getVTableType(),my_vtable,NamedClassDecls[ClassName]->getMethodId(mtdIdent->name));
	Value * my_func=Builder.CreateLoad(my_func_p);
	return Builder.CreateCall(my_func,argRef);
}

Type * MtdDecl::getFunctionType()
{
	if( llvmType == NULL ) {
		std::cout << " [ IR ] Class " << Owner->classIdent->name << "'s method "<<mtdIdent->name<<" now is processing on its LLVM type ."<< std::endl ;
		vector<Type*> typeVec ; 
		typeVec.clear();
		typeVec.push_back( Owner->getClassLLVMType()->getPointerTo() ) ; 
		std::vector<class VarArg*>::iterator vait ; 
		for ( vait = varArgList.declList.begin() ; vait != varArgList.declList.end() ; vait ++ ) 
			typeVec.push_back( (*vait)->getLLVMType() ) ; 
		ArrayRef<Type*> argTypeVec( typeVec ) ; 
		llvmType = FunctionType::get(rtnType->llvmTypeGen(),argTypeVec,false); 
		func = Function::Create( cast<FunctionType>(llvmType) , Function::ExternalLinkage , Owner->classIdent->name + std::string("_") + mtdIdent->name , TheModule); 
		llvmType = func->getType();
	}
	return llvmType;	
}

Function * MtdDecl::codeGen()
{
	std::cout << " [ IR ] Class " << Owner->classIdent->name << "'s method "<<mtdIdent->name<<" now is processing on its IR code ."<< std::endl ;
	BasicBlock * func_entry= BasicBlock::Create(getGlobalContext() , mtdIdent->name + std::string("_entry") , func);
	Builder.SetInsertPoint( func_entry ) ;
	
	NamedValues.clear();

	int j = 0 ; 
	for( auto &Arg : func->args() ) {
		if ( j == 0 ) {
			NamedValues[std::string("this")] = &Arg ; 
		} else {
			NamedValues[varArgList.declList[j-1]->varIdent->name] = &Arg ;
		}
		j++;
	}
	Owner->setNamedField(NamedValues[std::string("this")]);

	stmtList.codeGen();
	Value * retval;
	retval=rtnExpr->codeGen();
	Builder.CreateRet(retval);
	verifyFunction( *func ) ;
	TheFPM->run(*func);
	std::cout << " [ IR ] Class " << Owner->classIdent->name << "'s method "<<mtdIdent->name<<" have been generated successfully  ."<< std::endl ;
	return NULL;
}

Function * MtdDecl::getFunction()
{
	if ( isCreated ) return func ; 
	std::cout << " [ IR ] Class " << Owner->classIdent->name << "'s method "<<mtdIdent->name<<" now is processing."<< std::endl ;
	getFunctionType();
	codeGen();
	isCreated = true ; 
	std::cout << " [ IR ] Class " << Owner->classIdent->name << "'s method "<<mtdIdent->name<<" has been processed successfully ."<< std::endl ;
	return func;
}

Value* ObjNewExpr::codeGen()
{
	
	std::cout << " [ IR ] < ObjNewExpr::codeGen > Now allocating an object ."<< std::endl ;
	Value * mallocSize = ConstantExpr::getSizeOf(
					NamedClassDecls[tarIdent->name]->getClassLLVMType());
	mallocSize = ConstantExpr::getTruncOrBitCast( cast<Constant>(mallocSize) , Type::getInt64Ty(getGlobalContext()));
	Instruction * var_malloc=CallInst::CreateMalloc(	Builder.GetInsertBlock(),
					Type::getInt64Ty(getGlobalContext()),
					NamedClassDecls[tarIdent->name]->getClassLLVMType(),
					mallocSize, nullptr , nullptr , "_malloc");
	Builder.Insert(var_malloc);
	Value *var = var_malloc ; //Builder.CreateBitCast(var_malloc,NamedClassDecls[tarIdent->name]->getClassLLVMType()->getPointerTo());
	// new GlobalVariable(*TheModule,
//NamedClassDecls[tarIdent->name]->getClassLLVMType()
//,false,GlobalValue::ExternalLinkage,nullptr);
	
	Value * vtableField = Builder.CreateStructGEP( NamedClassDecls[tarIdent->name]->getClassLLVMType() , var , 0 ) ;	
	Builder.CreateStore(NamedClassDecls[tarIdent->name]->getVTableLoc(),vtableField);
	return var;
}

/*
void VarArgList::codeGen(Type* ClassType)
{
	if(!__codeGen)return;
	vector<Type*> t;
	t.clear();
	t.push_back(ClassType);
	int i,n=declList.size();
	for(;i<n;i++)
		t.push_back(declList[i]->getLLVMType());
	TypeArray = t ; 
	__codeGen=1;
}

ArrayRef<Type*>* VarArgList::getTypeArray(Type * ClassType)
{
	codeGen(ClassType);
	return &TypeArray;
}
*/

llvm::Type* ClassIdentType::llvmTypeGen() {
	if (tarType) return tarType;
	if ( NamedClassDecls.count( classIdent->name ) == 0 ) {
		std::cout<<" [ Check ] Class "<<classIdent->name<<" is not defined."<<std::endl;
		return NULL;	
	}	
	ClassDecl* tarClassDecl = NamedClassDecls[classIdent->name] ; 
	if ( tarClassDecl == NULL ) {
		std::cout<<" [ Check ] Class "<<classIdent->name<<" is not defined."<<std::endl;
		return NULL;		
	}
	tarType = tarClassDecl->getClassLLVMType()->getPointerTo();
	
	return tarType;		
}

llvm::Type* VarArg::getLLVMType(){
    	if ( llvmType ) return llvmType ; 
	llvmType = varType->llvmTypeGen();
	return llvmType;
}
