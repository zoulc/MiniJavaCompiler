/*Basic Verifier*/




/* increasing */
bool UsrDefIdentType::isItfaceType()
{
	typeCheck();
	return tarIdent->isItfaceTypeIdent();
}

bool UsrDefIdentType::isClassType()
{
	typeCheck();
	return tarIdent->isClassTypeIdent();
}

ClassDecl* UsrDefIdentType::getClassDecl()
{
	typeCheck();
	return tarIdent->getCorClassDecl();
}

ItfaceDecl* UsrDefIdentType::getItfaceDecl()
{
	typeCheck();
	return tarIdent->getCorItfaceDecl();
}

TypeInfo * ItfaceDecl::getAbsMethodRtnType( std::string absMtdName )
{
	if ( absMtdName2Pos.count(absMtdName) == 0 ) return NULL ;
	int slot = absMtdName2Pos[absMtdName] ;
	AbsMtdDecl* thisDecl = absMtdDecl[slot] ;
	return thisDecl->rtnType;
}

VarArg* VarArg::deepCopy()
{
	VarArg* tmp = new VarArg( varType->deepCopy() , varIdent->deepCopy() ) ;
	return tmp ;
}

AbsMtdDecl* AbsMtdDecl::deepCopy()
{
	AbsMtdDecl * tmp = new AbsMtdDecl( rtnType->deepCopy() , absMtdIdent->deepCopy() , new VarArgList() ) ;
	std::vector< class VarArg* >::iterator vait ;
	for ( vait = varArgList.declList.begin() ; vait != varArgList.declList.end() ; vait ++ )
		tmp->varArgList.declList.push_back( (*vait)->deepCopy() ) ;
	return tmp ;
}

TypeInfo* TypeInfo::deepCopy()
{
	TypeInfo* tmp = new TypeInfo( typeName ) ;
	return tmp ;
}

TypeInfo* ClassType::deepCopy()
{
	TypeInfo* tmp = new ClassType( tarIdent->deepCopy() , tarClassDecl ) ;
	return tmp ;
}

TypeInfo* ItfaceType::deepCopy()
{
	TypeInfo * tmp = new ItfaceType( tarIdent->deepCopy() , tarItfaceDecl ) ;
	return tmp ;
}

TypeInfo* UsrDefIdentType::deepCopy()
{
	TypeInfo* tmp = new UsrDefIdentType( tarIdent->deepCopy() );
	return tmp ;
}

Ident* Ident::deepCopy()
{
	Ident * tmp = new Ident( name );
	return tmp ;
}

bool Ident::isItfaceTypeIdent() { return false ; }
bool Ident::isClassTypeIdent()  { return false ; }
bool Ident::isVarUseIdent()		{ return false ; }

ItfaceDecl* Ident::getCorItfaceDecl() { return NULL; }
ClassDecl*  Ident::getCorClassDecl() { return NULL; }
TypeInfo* Ident::getVarUseIdentType() 	{ return NULL ; }

TypeInfo* Ident::typeCheck()
{
	if ( identType ) return identType ;
	identType = new NullType() ;
	return identType ;
}

bool VarUseIdent::isVarUseIdent() { return true ; }

TypeInfo* VarUseIdent::getVarUseIdentType() {
	if (!identType) typeCheck();
	return corVarType;
}

TypeInfo* VarUseIdent::typeCheck()
{
	if ( identType ) return identType ;
	if ( TypeNamedValues.count(name) == 0 ) {
		std::cout << " [ Type Check ] < VarUseIdent > Identifier doesn't exist." << std::endl ;
		identType = new NullType();
		return NULL ;
	}
	corVarType = TypeNamedValues[name];
	identType = new NullType();
	return identType;
}

bool TypeUseIdent::isItfaceTypeIdent()
{
	if (!identType) typeCheck();
	return !(isClass) ;
}

bool TypeUseIdent::isClassTypeIdent()
{
	if (!identType) typeCheck();
	return (isClass) ;
}

ItfaceDecl* TypeUseIdent::getCorItfaceDecl()
{
	if (!identType) typeCheck();
	return corItfaceDecl ;
}

ClassDecl* TypeUseIdent::getCorClassDecl()
{
	if (!identType) typeCheck();
	return corClassDecl ;
}

TypeInfo* TypeUseIdent::typeCheck()
{
	if ( identType ) return identType ;
	if ( TypeNamedClassDecls.count(name) == 0 ) {
		if ( TypeNamedItfaceDecls.count(name) == 0 ) {
			std::cout << " [ Type Check ] < TypeUseIdent > Identifier doesn't exist." << std::endl ;
			return NULL ;
		}
		corItfaceDecl = TypeNamedItfaceDecls[name] ;
		/*
		if ( corItfaceDecl->genStatus == NoneStatus ) {
			std::cout << " [ Type Check ] < TypeUseIdent > Interface haven't been typed." << std::endl ;
			return NULL ;
		}
		*/
		corClassDecl = NULL ;
		isClass = false ;
	} else {
		corClassDecl = TypeNamedClassDecls[name];
		/*
		if ( corClassDecl->genStatus == NoneStatus ) {
			std::cout << " [ Type Check ] < TypeUseIdent > Interface haven't been typed." << std::endl ;
			return NULL ;
		}
		*/
		corItfaceDecl = NULL ;
		isClass = true ;
	}
	identType = new NullType();
	return identType;
}

TypeInfo* UsrDefIdentType::getConcreType()
{
	typeCheck();
	return concreType;
}

TypeInfo* TypeInfo::typeCheck()
{
	if ( isTypeChecked ) return this ;
	isTypeChecked = true ;
	return this ;
}

TypeInfo* UsrDefIdentType::typeCheck()
{
	if ( isTypeChecked ) return concreType  ;
	tarIdent->typeCheck();
	if ( tarIdent->isClassTypeIdent() ) {
		concreType = new ClassType( tarIdent , tarIdent->getCorClassDecl() ) ;
	} else {
		if ( tarIdent->isItfaceTypeIdent() ) {
			concreType = new ItfaceType( tarIdent , tarIdent->getCorItfaceDecl() ) ;
		} else {
			concreType = new NullType();
			std::cout << " [ Type Check ] < UsrDefIdent > Invalid Identfier." << std::endl ;
		}
	}
	isTypeChecked = true ;
	return  concreType ;
}

bool TypeInfo::isUsrDefIdentType() { return false ; }
bool UsrDefIdentType::isUsrDefIdentType() { return true ; }

Ident* ItfaceDeclIdent::deepCopy()
{
	Ident * tmp = new ItfaceDeclIdent( name ) ;
	return tmp ;
}

Ident* ClassDeclIdent::deepCopy()
{
	Ident * tmp = new ClassDeclIdent( name ) ;
	return tmp ;
}

Ident* VarDeclIdent::deepCopy()
{
	Ident * tmp = new VarDeclIdent( name ) ;
	return tmp ;
}

Ident* ArgDeclIdent::deepCopy()
{
	Ident * tmp = new ArgDeclIdent( name ) ;
	return tmp ;
}

Ident* MtdDeclIdent::deepCopy()
{
	Ident * tmp = new MtdDeclIdent( name ) ;
	return tmp ;
}

Ident* VarUseIdent::deepCopy()
{
	Ident * tmp = new VarUseIdent( name ) ;
	return tmp ;
}

Ident* MtdUseIdent::deepCopy()
{
	Ident * tmp = new MtdUseIdent( name ) ;
	return tmp ;
}

Ident* TypeUseIdent::deepCopy()
{
	Ident * tmp = new TypeUseIdent( name ) ;
	return tmp ;
}

void ItfaceDecl::AddImpClass( ClassDecl* clsDecl )
{
	if ( ! clsDecl ) return ;
	if ( impCls2Pos.count(clsDecl->classIdent->name) != 0 ) return ;
	impCls2Pos[clsDecl->classIdent->name] = impClasses.size();
	impClasses.push_back( clsDecl ) ;
	std::vector< ItfaceDecl * >::iterator eit ;
	for ( eit = extItfaces.begin() ; eit != extItfaces.end() ; eit ++ )
		(*eit)->AddImpClass( clsDecl ) ;
}

llvm::Type* AbsMtdDecl::llvmTypeGen()
{
	if ( llvmType) return llvmType ;
	std::cout << " [ IR ] Itface " << Owner->itfaceIdent->name << "'s method "<<absMtdIdent->name<<" now is processing on its LLVM type ."<< std::endl ;
	vector<Type*> typeVec ;
	typeVec.clear();
	typeVec.push_back( Type::getInt64PtrTy(getGlobalContext())) ;
	std::vector<class VarArg*>::iterator vait ;
	for ( vait = varArgList.declList.begin() ; vait != varArgList.declList.end() ; vait ++ )
		typeVec.push_back( (*vait)->getLLVMType() ) ;
	ArrayRef<Type*> argTypeVec( typeVec ) ;
	llvmType = FunctionType::get(rtnType->llvmTypeGen(),argTypeVec,false);
	absMtdDynFunc = Function::Create( cast<FunctionType>(llvmType) , Function::ExternalLinkage , Owner->itfaceIdent->name + std::string("_") +absMtdIdent->name , TheModule);
	llvmType = absMtdDynFunc->getType();
	return llvmType ;
}

llvm::Value* AbsMtdDecl::codeGen()
{
	if ( isCodeGened ) return absMtdDynFunc ;
	llvmTypeGen();
	BasicBlock * func_entry= BasicBlock::Create(getGlobalContext());
	absMtdDynFunc->getBasicBlockList().push_back(func_entry);
	Builder.SetInsertPoint( func_entry ) ;

	Function* thisFunc = absMtdDynFunc ;
	vector<Value*> tempArg ;

	NamedValues.clear();
	int j = 0 ;
	Value * clsIntPtr ;
	for( auto &Arg : thisFunc->args() ) {
		if ( j == 0 ) {
			clsIntPtr = &Arg ;
		} else {
			tempArg.push_back( &Arg  ) ;
		}
		j++;
	}
	Value* clsNo = Builder.CreateLoad( clsIntPtr ) ;

	std::vector<class ClassDecl*>::iterator cit ;

	for ( cit = Owner->impClasses.begin() ; cit != Owner->impClasses.end() ; cit ++ )
	{
		ClassDecl* thisCls = (*cit);
		Value* condFindClass = Builder.CreateICmpEQ( clsNo , ConstantInt::get(Type::getInt64Ty(getGlobalContext()), thisCls->classDeclNumber , true) );
		BasicBlock *ThenBB = BasicBlock::Create(getGlobalContext());
		
		thisFunc->getBasicBlockList().push_back(ThenBB);

		BasicBlock *MergeBB = BasicBlock::Create(getGlobalContext());
		Builder.CreateCondBr( condFindClass , ThenBB, MergeBB );
		Builder.SetInsertPoint(ThenBB);

		// Cast and Call
		int mtdSlot = thisCls->getMethodId(absMtdIdent->name) ;
		MtdDecl* thisMtd = thisCls->mtdDecl[mtdSlot];
		ClassDecl* formCls = thisMtd->formOwner;

		
		Value* clsPtr = Builder.CreatePointerCast( clsIntPtr , thisCls->getClassLLVMType()->getPointerTo() ) ;
		Value* formClsPtr = Builder.CreatePointerCast( clsIntPtr , formCls->getClassLLVMType()->getPointerTo() ) ;
		vector<Value*> args ;
		args.push_back( formClsPtr );
		std::vector<Value*>::iterator ait ;
		for ( ait = tempArg.begin() ; ait != tempArg.end() ; ait ++ )
			args.push_back( ( *ait) ) ;

		ArrayRef<Value*> argRef(args);
		//Value * corClsMtdId=ConstantInt::get(Type::getInt64Ty(getGlobalContext()),thisCls->getMethodId(absMtdIdent->name), true);
		Value * my_vtable=Builder.CreateLoad(Builder.CreateStructGEP(thisCls->getClassLLVMType(),clsPtr,1));
		Value * my_func_p=Builder.CreateStructGEP(thisCls->getVTableType(),my_vtable,mtdSlot);
		Value * my_func=Builder.CreateLoad(my_func_p);
		Value * retval = Builder.CreateCall(my_func,argRef);

		// Make a ret
		Builder.CreateRet(retval);

		//Builder.CreateBr(MergeBB);

		thisFunc->getBasicBlockList().push_back(MergeBB);
		Builder.SetInsertPoint(MergeBB);
	}
	Builder.CreateRet(  Constant::getNullValue(rtnType->llvmTypeGen() ) );
	verifyFunction( *thisFunc ) ;
	//TheFPM->run( *thisFunc ) ;
	isCodeGened = true ;
	return absMtdDynFunc ;
}


TypeInfo* AbsMtdDecl::typeCheck()
{
	if ( absMtdDeclType ) return absMtdDeclType ;
	/* may need chagnes */

	rtnType->typeCheck();
	
	absMtdDeclType = new VoidType();
	return absMtdDeclType ;
}

TypeInfo* ItfaceDecl::typeCheck()
{
	if ( itfaceDeclType ) return itfaceDeclType ;
	// TODO: Postpone the extend of the interfaces
	std::cout<<" [ Type Check ] Itface "<<itfaceIdent->name<<" is processing."<<std::endl ;

	std::vector< ExtItface * >::iterator eit ;
	for ( eit = extItfaceList.extList.begin() ; eit != extItfaceList.extList.end() ; eit ++ ) {
		if ( TypeNamedItfaceDecls.count((*eit)->extIdent->name) == 0 ) {
			std::cout<<" [ Type Check ] < ItfaceDecl > Invalid Interface Name."<<std::endl ;
			continue ;
		}
		ItfaceDecl* tarItface = TypeNamedItfaceDecls[ (*eit)->extIdent->name ] ;
		extItfaces.push_back( tarItface ) ;
	}

	// Load the 'Onwer' Abstract Methods .
	std::vector< class ItfaceDecl* >::iterator iit ;
	for ( iit = extItfaces.begin() ; iit != extItfaces.end() ; iit ++ )
	{
		(*iit) -> typeCheck();
		std::vector<class AbsMtdDecl*> & thisList = (*iit)->absMtdDecl ;
		std::vector< class AbsMtdDecl* >::iterator ait ;
		for ( ait = thisList.begin() ; ait != thisList.end() ; ait ++ )
		{
			if ( absMtdName2Pos.count( (*ait)->absMtdIdent->name )  != 0 ) {
				int slot = absMtdName2Pos[(*ait)->absMtdIdent->name] ;
				AbsMtdDecl* tmp = (*ait)->deepCopy();
				tmp->Owner = this ;
				tmp->typeCheck() ;
				absMtdDecl[slot] = tmp ;
			} else {
				int slot = absMtdDecl.size();
				absMtdName2Pos[(*ait)->absMtdIdent->name] = slot ;
				AbsMtdDecl* tmp = (*ait)->deepCopy();
				tmp->Owner = this ;
				tmp->typeCheck() ;
				absMtdDecl.push_back(tmp);
			}
		}
	}

	std::vector< class AbsMtdDecl* >::iterator ait ;
	for ( ait = absMtdDeclList.declList.begin() ; ait != absMtdDeclList.declList.end() ; ait ++ )
	{
		if ( absMtdName2Pos.count( (*ait)->absMtdIdent->name )  != 0 ) {
			int slot = absMtdName2Pos[(*ait)->absMtdIdent->name] ;
			absMtdDecl[slot] = (*ait);
			(*ait)->Owner = this ;
			(*ait)->typeCheck();
		} else {
			int slot = absMtdDecl.size();
			absMtdName2Pos[(*ait)->absMtdIdent->name] = slot ;
			absMtdDecl.push_back((*ait));
			(*ait)->Owner = this ;
			(*ait)->typeCheck() ;
		}
	}
	itfaceDeclType = new VoidType();
	return itfaceDeclType ;
}

llvm::Value* ItfaceDecl::codeGen()
{
	if ( isCodeGened ) return Constant::getNullValue(Type::getInt64Ty(getGlobalContext()));

	std::vector< class ClassDecl* >::iterator cit ;
	for ( cit = impClasses.begin() ; cit != impClasses.end() ; cit ++ )
		(*cit)->getClassLLVMType();

	std::vector< class AbsMtdDecl* >::iterator ait ;
	for ( ait = absMtdDecl.begin() ; ait != absMtdDecl.end() ;  ait ++ )
		(*ait)->codeGen();

	isCodeGened = true ;
	return Constant::getNullValue(Type::getInt64Ty(getGlobalContext()));
}

llvm::Value* ItfaceDecl::getConcreMethod(std::string mtdName )
{
	if ( absMtdName2Pos.count(mtdName) == 0  ) {
		std::cout <<"  [ Type Check ] < Interface > Invalid Abstract Method . " << std::endl ;
		return NULL ;
	}
	int slot = absMtdName2Pos[mtdName];
	AbsMtdDecl* tarAbsMtdDecl = absMtdDecl[slot];
	cout << 1 << endl ; 
	return tarAbsMtdDecl->codeGen();
}

/* Need TO DO */

Value* LamdaGenExpr::codeGen() {
	return NULL ;
}

Value* LamdaAppExpr::codeGen() {
	return NULL ;
}

TypeInfo* LamdaGenExpr::typeCheck()
{
	if ( exprType ) return exprType ;
	exprType = new InvokerType() ;
	return exprType ;
}

TypeInfo* LamdaAppExpr::typeCheck()
{
	if (exprType) return exprType ;
	exprType = new IntType();
	return exprType	;
}

/* Type Check */
TypeInfo* InsOfExpr::typeCheck()
{
	if (exprType) return exprType ;
	tarExpr->typeCheck();
	// Wait for implement if ( ! ( tarExpr->typeCheck() == std::string("Class")) )
	// "instanceof" should examine the type .
	if ( srcType->typeName != "Class" ) return NULL ;
	exprType = new IntType();
	return exprType ;
}

TypeInfo* ObjNewExpr::typeCheck()
{
	if ( exprType ) return exprType;
	if ( TypeNamedClassDecls.count( tarIdent->name ) == 0 ) {
		cout<<"Error , class not defined"<<endl;
		return NULL ;
	}
	exprType = new UsrDefIdentType( tarIdent );
	return exprType ;
}

TypeInfo* GetLenExpr::typeCheck()
{
	if(exprType) return exprType ;
	exprType = new IntType();
	return exprType ;
}

TypeInfo* IntLiterExpr::typeCheck()
{
	if (exprType) return exprType;
	exprType = new IntType();
	return exprType;
}

TypeInfo* TrueLiterExpr::typeCheck()
{
	if (exprType) return exprType;
	exprType = new IntType();
	return exprType;
}

TypeInfo* FalseLiterExpr::typeCheck()
{
	if (exprType) return exprType;
	exprType = new IntType();
	return exprType;
}

TypeInfo* MainClassDecl::typeCheck()
{
	if ( mainClassDeclType ) return mainClassDeclType ;
	std::vector< class Stmt * >::iterator sit ;
	for ( sit = stmtList.stmtList.begin() ;
		  sit != stmtList.stmtList.end() ; sit ++ ) {
		if ( ( (*sit)->typeCheck() ) == NULL ) return NULL ;
	}
	mainClassDeclType = new VoidType();
	return mainClassDeclType ;
}

TypeInfo* SiOpExpr::typeCheck()
{
	std::cout <<"  [ Type Check ] \"SiOpExpr\" should not be type checked. " << std::endl ;
	return NULL ;
}

TypeInfo* NegExpr::typeCheck()
{
	if (exprType) return exprType ;
	tarExpr->typeCheck();
	exprType = new IntType();
	return exprType ;
}

TypeInfo* ParenExpr::typeCheck()
{
	if(exprType) return exprType;
	exprType = tarExpr->typeCheck();
	return exprType;
}

TypeInfo* BlockStmt::typeCheck()
{
	if(stmtType) return stmtType;
	std::vector<class Stmt *>::iterator sit ;
	for ( sit = stmtList.stmtList.begin() ; sit != stmtList.stmtList.end() ; sit ++ )
		(*sit)->typeCheck();
	stmtType = new VoidType();
	return stmtType;
}

TypeInfo* IfThenElseStmt::typeCheck()
{
	if(stmtType) return stmtType;
	condExpr->typeCheck();
	thenStmt->typeCheck();
	elseStmt->typeCheck();
	stmtType = new VoidType();
	return stmtType;
}

TypeInfo* WhileStmt::typeCheck()
{
	if(stmtType) return stmtType ;
	condExpr->typeCheck();
	bodyStmt->typeCheck();
	stmtType = new VoidType();
	return stmtType ;
}

TypeInfo* SysOutPrtStmt::typeCheck()
{
	if (stmtType) return stmtType;
	prtExpr->typeCheck();
	stmtType = new VoidType();
	return stmtType ;
}

TypeInfo* AssignStmt::typeCheck()
{
	if ( stmtType ) return stmtType ;
	valueExpr->typeCheck();
	stmtType = new VoidType();
	return stmtType ;
}

TypeInfo* GetMtdCallExpr::typeCheck()
{
	if ( exprType ) return exprType;
	if ( tarExpr->typeCheck() == NULL ) return NULL;
	if ( tarExpr->typeCheck()->typeName == "Class" ) {
		tarClassDecl = (( class ClassType* )tarExpr->typeCheck())->tarClassDecl ;
		tarClassDecl->typeCheck();
		exprType = tarClassDecl->getMethodRtnType( mtdIdent->name ) ;
		isClass = true ;
		return exprType ;
	} else {
		if ( tarExpr->typeCheck()->typeName == "Itface") {
			tarItfaceDecl = (( class ItfaceType* )tarExpr->typeCheck())->tarItfaceDecl ;
			tarItfaceDecl->typeCheck();
			exprType = tarItfaceDecl->getAbsMethodRtnType( mtdIdent->name ) ;
			isClass = false ;
			return exprType ;
		} else {
			std::cout << " [ Type Check ] < GetMtdCallExpr > Invalid Caller Type ." << std::endl ;
			exprType = new NullType() ;
			return exprType;
		}
	}
	return exprType ;
}

TypeInfo* IdentAccessExpr::typeCheck()
{
	if ( exprType ) return exprType ;
	tarIdent->typeCheck();
	if ( TypeNamedValues.count( tarIdent->name ) == 0 ) {
		cout<<"Error"<<endl;
		return NULL;
	}
	exprType = TypeNamedValues[ tarIdent->name ] ;
	return exprType ;
}

TypeInfo* VarDecl::typeCheck()
{
	varType->typeCheck();
	varIdent->typeCheck();
	if ( varType ) {
		if ( varType->isUsrDefIdentType() )
			return ( ( ( UsrDefIdentType* )varType )->getConcreType()) ;
		else
			return varType ;
	}
	return  NULL ;
}

TypeInfo* VarDeclStmt::typeCheck()
{
	if ( stmtType ) return stmtType ;
	type->typeCheck();
	varIdent->typeCheck();
	if ( type->isUsrDefIdentType() )
		TypeNamedValues[varIdent->name] = ((UsrDefIdentType*)type)->getConcreType();
	else
		TypeNamedValues[varIdent->name] = type ;
	stmtType = new VoidType();
	return stmtType ;
}

TypeInfo* ClassDecl::typeCheck()
{
	if ( classDeclType ) return classDeclType ;
	cout << " [ Type Check ] " << classIdent->name << endl ;
	TypeNamedClassDecls[ classIdent->name ] = this ;
	NamedClassDecls[ classIdent->name ] = this ;
	classDeclType = new VoidType();

	//Fetch Base Class and load methods and fields from it .
	std::cout << " [ Type Check ] Class " << classIdent->name << " now is processing on its base class ."<< std::endl ;
	if ( extClassIdent != NULL ) {
		std::string extClassName = extClassIdent->name ;
		if ( NamedClassDecls[extClassName] == 0 ) {
			std::cout<<" [ Type Check ] ClassDecl "<<classIdent->name<<"'s base class hasn't been defined."<<std::endl;
			return NULL ;
		}
		baseClass = NamedClassDecls[extClassName] ;
		std::vector<class VarDecl*>::iterator vit;

		//first exam the base Class
		if ( ! ( baseClass->typeCheck() ) ) {
			return NULL ;
		}

		//Add all the fields of base class into this class
		for( vit = (baseClass->fieldDecl).begin() ; vit !=(baseClass->fieldDecl).end() ; vit++ ) {
			fieldDecl.push_back((*vit));
			TypeInfo * itType = (*vit)->typeCheck();
			if ( itType == NULL ) {
				std::cout<<" [ Type Check ] ClassDecl "<<classIdent->name<<"'s field which named "<< (*vit)->varIdent->name << std::endl;
				return NULL ;
			}
			fieldName2Pos[(*vit)->varIdent->name] = 1 + fieldDecl.size();
			//because of the class type number of the 1 offset .
			//and the class number of the 0 offset
		}

		//Add all the methods' declartions into this class
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

	std::vector< ImpItface * >::iterator iit ;
	for ( iit = impItfaceList.impList.begin() ; iit != impItfaceList.impList.end() ; iit ++ ) {
		if ( TypeNamedItfaceDecls.count((*iit)->impIdent->name) == 0 ) {
			std::cout<<"[ Type Check ] < ItfaceDecl > Invalid Interface Name."<<std::endl ;
			continue ;
		}
		ItfaceDecl* tarItface = TypeNamedItfaceDecls[ (*iit)->impIdent->name ] ;
		tarItface->typeCheck();
		impItfaces.push_back( tarItface ) ;
		tarItface->AddImpClass( this ) ;
	}

	//After that , prepare its own fields and methods .
	std::cout << " [ Type Check ] Class " << classIdent->name << " initialize the fields ."<< std::endl ;
	std::vector<class VarDecl*>::iterator vit;
	for( vit = (varDeclList.declList).begin() ; vit != (varDeclList.declList).end() ; vit++ ) {
		TypeInfo* itType = (*vit)->typeCheck();
		if ( itType == NULL ) {
			std::cout<<" [ Type Check ] ClassDecl "<<classIdent->name<<"'s field which named "<< (*vit)->varIdent->name << std::endl;
			return NULL ;
		}
		fieldDecl.push_back((*vit));
		fieldName2Pos[(*vit)->varIdent->name] = 1 + fieldDecl.size();
		//because of the class type number of the 1 offset .
		//and the class number of the 0 offset
	}

	std::cout << " [ Type Check ] Class " << classIdent->name << " initialize the methods ."<< std::endl ;
	std::vector<class MtdDecl*>::iterator mit;
	for( mit = (mtdDeclList.declList).begin() ; mit !=(mtdDeclList.declList).end() ; mit++ ) {
		std::cout << " [ Type Check ] Add the method "<<(*mit)->mtdIdent->name<<" to Class "<<classIdent->name<<std::endl;
		if ( mtdName2Pos.count((*mit)->mtdIdent->name) == 0 ) {
			mtdName2Pos[(*mit)->mtdIdent->name] = mtdDecl.size() ;
			(*mit)->Owner = this ;
			(*mit)->formOwner = this ;
			mtdDecl.push_back((*mit));
			continue ;
		}
		int mtd_id = mtdName2Pos[(*mit)->mtdIdent->name] ;
		(*mit)->formOwner = mtdDecl[mtd_id]->formOwner ;
		mtdDecl[mtd_id] = (*mit);
		(*mit)->Owner = this ;
	}

	// ABANDONED : getClassLLVMType();
	for ( mit = mtdDecl.begin() ; mit != mtdDecl.end() ; mit ++ ) {
		TypeNamedValues.clear();
		std::vector<class VarDecl*>::iterator vit;
		for( vit = fieldDecl.begin() ; vit != fieldDecl.end() ; vit++ ) {
		TypeNamedValues[ (*vit)->varIdent->name ]
			= (*vit)->typeCheck() ;
		}
		if ( ((*mit)->typeCheck()) == NULL ) return NULL ;
	}
	return classDeclType ;
}

TypeInfo* VarArg::typeCheck()
{
	varType->typeCheck();
	varIdent->typeCheck();
	if ( varType ) {
		if ( varType->isUsrDefIdentType() )
			return ( ( ( UsrDefIdentType* ) varType )->getConcreType()) ;
		else
			return varType ;
	}
	return NULL ;
}

TypeInfo* MtdDecl::typeCheck() {
	if ( mtdDeclType ) return mtdDeclType ;
	TypeNamedValues.clear();
	std::vector<class VarDecl*>::iterator dit ;
	for (dit = Owner->varDeclList.declList.begin() ;
		 dit != Owner->varDeclList.declList.end() ; dit ++)
	{
		TypeNamedValues[(*dit)->varIdent->name] = (*dit)->typeCheck();
	}
	std::vector<class VarArg *>::iterator vit ;
	for ( vit = varArgList.declList.begin() ;
	      vit != varArgList.declList.end() ; vit ++ ) {
		TypeNamedValues[(*vit)->varIdent->name] = (*vit)->typeCheck() ;
	}
	std::vector< class Stmt * >::iterator sit ;
	for ( sit = stmtList.stmtList.begin() ;
	      sit != stmtList.stmtList.end() ; sit ++ ) {
		if ( ( (*sit)->typeCheck() ) == NULL ) return NULL ;
	}
	if ( (rtnExpr->typeCheck()) == NULL ) return NULL ;
	mtdDeclType = new VoidType();
	return mtdDeclType ;
}

TypeInfo* ClassDecl::getMethodRtnType( std::string mtdName ) {
	typeCheck();
	std::vector<class MtdDecl*>::iterator mit ;
	for ( mit = mtdDecl.begin() ; mit != mtdDecl.end() ; mit ++ ) {
		if ( (*mit)->mtdIdent->name == mtdName )
			return (*mit)->rtnExpr->typeCheck() ;
	}
	cout<<"Error Method Not Found"<<endl;
	return NULL ;
}

TypeInfo* Stmt::typeCheck() {
	if ( stmtType ) return stmtType ;
	stmtType = new VoidType();
	return stmtType ;
}

TypeInfo * Expr::typeCheck() {
	if ( exprType ) return exprType ;
	exprType = new IntType();
	return exprType ;
}

TypeInfo* Program::typeCheck() {
	std::vector<class ClassDecl*>::iterator cit ;
	long long int cnt = 0 ;
	for ( cit = classDeclList.declList.begin() ; cit != classDeclList.declList.end() ; cit ++ ) {
		TypeNamedClassDecls[ (*cit)->classIdent->name ] = (*cit);
		NamedClassDecls[ (*cit)->classIdent->name ] = (*cit) ;
		cnt ++ ;
		(*cit)->classDeclNumber = cnt ;
	}
	std::vector<class ItfaceDecl*>::iterator iit ;
	for ( iit = itfaceDeclList.declList.begin() ; iit != itfaceDeclList.declList.end() ; iit ++ ) {
		TypeNamedItfaceDecls[(*iit)->itfaceIdent->name ] = (*iit) ;
		NamedItfaceDecls[ (*iit)->itfaceIdent->name ] = (*iit) ;
	}
	for ( cit = classDeclList.declList.begin() ; cit != classDeclList.declList.end() ; cit ++ ) {
		(*cit)->typeCheck();
 	}
	mainClassDecl->typeCheck();
	return NULL ;
}

/* Genearting the Code Part ! */
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
	if(NamedValues.count(assignIdent->name)==0)
	{
		std::cout<<"Undefined Value\n";
		return nullptr;
	}
	Value * rval=valueExpr->codeGen();
	std::cout << "Creating Assignment statement" << endl;
	if ( valueExpr->typeCheck() == NULL ) cout << "fuck" <<endl ; 
	cout << valueExpr->typeCheck()->typeName << endl ; 
	if ( NamedValues[assignIdent->name]->getType() != (valueExpr->typeCheck())->llvmTypeGen()->getPointerTo() ) 
		cout<<"haha"<<endl;
	cout<<"hehe"<<endl;
	//Value * ptrCast = Builder.CreatePointerCast( NamedValues[assignIdent->name] , (valueExpr->typeCheck())->llvmTypeGen()->getPointerTo() );

	Value* ptr = Builder.CreatePointerCast( NamedValues[assignIdent->name] , ( valueExpr->typeCheck())->llvmTypeGen()->getPointerTo());
	Value* result = Builder.CreateStore(rval, ptr);
	std::cout << "Store instruction created" << endl;
	return result ; 
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
    return Builder.CreateICmpULT( leftExpr->codeGen() , rightExpr->codeGen() , "ultcmptmp");
}

llvm::Value* InsOfExpr::codeGen()
{
	Value * intPtrCast = Builder.CreatePointerCast( tarExpr->codeGen() , Type::getInt64Ty(getGlobalContext()) ) ;
	Value * tarClsNo = Builder.CreateLoad( intPtrCast ) ;
	if ( ! srcType->isUsrDefIdentType() ) {
		std::cout<<" [ IR ] < InsOfExpr > Invalid class Type." <<std::endl;
		return NULL ;
	}
	TypeInfo * tarType = ( ( UsrDefIdentType * ) srcType )->getConcreType() ;
	if ( tarType->typeName != "Class" ) {
		std::cout<<" [ IR ] < InsOfExpr > Invalid class Type." <<std::endl;
		return NULL ;
	}
	ClassDecl* tarClassDecl = ( ( ClassType* ) tarType ) ->tarClassDecl ;
	Value * srcClsNo = ConstantInt::get(Type::getInt64Ty(getGlobalContext()), tarClassDecl->classDeclNumber, true);
	return Builder.CreateICmpEQ( tarClsNo , srcClsNo , "instanceof" );
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
	if ( tarType ) return tarType ;
	tarType = Type::getInt64Ty(getGlobalContext());
    return tarType ;
}

llvm::Type* ClassType::llvmTypeGen()
{
	if ( tarType ) return tarType ;
	tarType = tarClassDecl->getClassLLVMType();
    return tarType ;
}
llvm::Type* ItfaceType::llvmTypeGen()
{
	if ( tarType ) return tarType ;
	tarType = Type::getInt64PtrTy(getGlobalContext());
    return tarType ;
}

llvm::Type* BoolType::llvmTypeGen()
{
	if ( tarType ) return tarType ;
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
    if ( ! ( NamedValues.count(varIdent->name) == 0 ) ) {
        std::cout<<"VarDeclStmt : Redefinition of the same name."<<std::endl;
        return NULL ;
    }
    Value * targetValue =
        Builder.CreateAlloca( tarType , 0 , varIdent->name ) ;
    NamedValues[varIdent->name] = targetValue ;
    return targetValue ;
}

llvm::Value* IdentAccessExpr::codeGen() {
    if ( NamedValues.count(tarIdent->name) == 0 ) {
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
	std::vector<class ItfaceDecl*>::iterator iit ; 
	for ( iit = itfaceDeclList.declList.begin() ; iit != itfaceDeclList.declList.end() ; iit ++ ) {
		(*iit)->codeGen();
	}
	std::vector<class ClassDecl*>::iterator cit ;
	for ( cit = classDeclList.declList.begin() ; cit != classDeclList.declList.end() ; cit ++ ) {
		(*cit)->codeGen();
 	}
}

/*
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
*/

llvm::Type* ClassDecl::getClassLLVMType() {
	if ( classLLVMType ) return classLLVMType ;
	if ( ! ( classDeclType ) ) this->typeCheck();
	std::cout << " [ IR ] < getClassLLVMType > Class " << classIdent->name << " now is processing on its LLVM type ."<< std::endl ;
	// ABANDONED : getBaseClass();
	std::string className = classIdent->name ;
	/*
	if ( NamedClassDecls[className] != 0 ) {
		std::cout<<" [Check] Class "<<className<<" have multiple difintion."<<std::endl;
		return NULL ;
	}
	*/
	NamedClassDecls[className] = this ;

	//make an oblique identified class type , then fill some thing into it.
	std::cout << " [ IR ] < getClassLLVMType > Class " << classIdent->name << " create a oblique identifed type ."<< std::endl ;
	classLLVMType = StructType::create(Builder.getContext() , className );

	//Generate LLVM Type for every fields .
	std::cout << " [ IR ] < getClassLLVMType > Class " << classIdent->name << " generate the LLVM Type for the fields ."<< std::endl ;
	std::vector<class VarDecl*>::iterator it;
	for( it = fieldDecl.begin() ;
		 it != fieldDecl.end() ; it++ ) {
		llvm::Type* itType = (*it)->getLLVMType();
		if ( itType == NULL ) {
			std::cout<<" [Check] ClassDecl "<<classIdent->name<<
			"'s field which named "<< (*it)->varIdent->name << std::endl;
			return NULL ;
		}
	}

	std::vector<llvm::Type*> classTypeVec;
	classTypeVec.clear();

	//push the Class Identfier Number into the Struct Type
	classTypeVec.push_back( Type::getInt64Ty(getGlobalContext()) ) ;

	//push the VTable of Function into the classTypeVec
	std::cout << " [ IR ] < getClassLLVMType > Class " << classIdent->name << " initial the VTable's type ."<< std::endl ;
	classTypeVec.push_back( getVTableType()->getPointerTo() );

	//push the fields' types into the class TypeVec
	std::cout << " [ IR ] < getClassLLVMType > Class " << classIdent->name << " fill the whole type ."<< std::endl ;
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
	if ( ! ( classDeclType ) ) this->typeCheck();
	std::cout << " [ IR ] < getVTableType > Class " << classIdent->name << " now is processing on its VTable's LLVM type ."<< std::endl ;
	// ABANDONED : getBaseClass();
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
	if ( isClass ) {
		ClassDecl* tarClassDecl = ((ClassType*)(tarExpr->typeCheck()))->tarClassDecl;
		int mtdSlot = tarClassDecl->getMethodId(mtdIdent->name) ;
		MtdDecl*   tarMtdDecl   = tarClassDecl->mtdDecl[mtdSlot];
		ClassDecl* tarFormClassDecl = tarMtdDecl->formOwner ;

		vector <Value*> arg;
		Value* exprValue = tarExpr->codeGen(); 
		Value* thisPtr = Builder.CreatePointerCast( exprValue , tarClassDecl->getClassLLVMType()->getPointerTo() ) ; 
		Value* firPtr = Builder.CreatePointerCast( exprValue , tarFormClassDecl->getClassLLVMType()->getPointerTo() ) ;
		arg.push_back( firPtr );
		std::vector< class Expr* >::iterator fit ; 
		std::vector< class VarArg* >::iterator vit = tarMtdDecl->varArgList.declList.begin()  ; 	
		for( fit = fillList.fillList.begin() ; fit != fillList.fillList.end() ; fit ++ , vit ++  ) {
			Value* tmpArgValue = (*fit)->codeGen();
			if ( (*fit)->typeCheck()->typeName != (*vit)->typeCheck()->typeName ) {
				arg.push_back( Builder.CreatePointerCast( tmpArgValue , (*vit)->typeCheck()->llvmTypeGen() ) ) ;  
			} else {
				arg.push_back( tmpArgValue ) ; 
			}  	
		}
		
		ArrayRef<Value*> argRef(arg);

		Value * my_vtable=Builder.CreateLoad(Builder.CreateStructGEP(tarClassDecl->getClassLLVMType(),thisPtr,1));
		Value * my_func_p=Builder.CreateStructGEP(tarClassDecl->getVTableType(),my_vtable, mtdSlot );
		Value * my_func=Builder.CreateLoad(my_func_p);
		return Builder.CreateCall(my_func,argRef);

	} else {

		ItfaceDecl* tarItfaceDecl = ((ItfaceType*)tarExpr->typeCheck())->tarItfaceDecl ;
		int absMtdSlot = tarItfaceDecl->absMtdName2Pos[ mtdIdent->name ];
		AbsMtdDecl* tarAbsMtdDecl = tarItfaceDecl->absMtdDecl[absMtdSlot];
		
		vector <Value*> arg;
		cout<<tarExpr->typeCheck()->typeName<<endl;
		cout<<tarAbsMtdDecl->absMtdIdent->name<<endl;
		cout<<5<<endl;
		Value* firPtr = Builder.CreatePointerCast( tarExpr->codeGen() , tarExpr->typeCheck()->llvmTypeGen() ) ;
		arg.push_back( firPtr );
		std::vector< class Expr* >::iterator fit ; 
		std::vector< class VarArg* >::iterator vit = tarAbsMtdDecl->varArgList.declList.begin()  ; 	
		for( fit = fillList.fillList.begin() ; fit != fillList.fillList.end() ; fit ++ , vit ++  ) {
			Value* tmpArgValue = (*fit)->codeGen();
			if ( (*fit)->typeCheck()->typeName != (*vit)->typeCheck()->typeName ) {
				arg.push_back( Builder.CreatePointerCast( tmpArgValue , (*vit)->typeCheck()->llvmTypeGen() ) ) ;  
			} else {
				arg.push_back( tmpArgValue ) ; 
			}  	
		}
		
		ArrayRef<Value*> argRef(arg);
		cout<<3<<endl;	
		std::map<std::string,llvm::Value*> tempMap(NamedValues); 
		Value * my_func = tarItfaceDecl->getConcreMethod(mtdIdent->name);
		cout<<4<<endl;
		NamedValues.clear();	
		NamedValues = tempMap ; 
		Value * result = Builder.CreateCall(my_func,argRef);
		cout<<2<<endl;
		return result ; 
	}
	return NULL ;
}

Type * MtdDecl::getFunctionType()
{
	if( llvmType == NULL ) {
		std::cout << " [ IR ] Class " << Owner->classIdent->name << "'s method "<<mtdIdent->name<<" now is processing on its LLVM type ."<< std::endl ;
		vector<Type*> typeVec ;
		typeVec.clear();
		typeVec.push_back( formOwner->getClassLLVMType()->getPointerTo() ) ;
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

	Value * thisCls ; 

	int j = 0 ;
	for( auto &Arg : func->args() ) {
		if ( j == 0 ) {
			thisCls = Builder.CreatePointerCast( &Arg , Owner->getClassLLVMType()->getPointerTo() )  ;
			Value * tmpPtr = Builder.CreateAlloca( Owner->getClassLLVMType()->getPointerTo() , 0 );
			Builder.CreateStore( thisCls , tmpPtr ); 
			NamedValues[std::string("this")] = tmpPtr ;
		} else {
			// Add the Alloca Instruction for the Argments 
			Value* tmpPtr = Builder.CreateAlloca( varArgList.declList[j-1]->typeCheck()->llvmTypeGen() , 0 ) ; 
			Builder.CreateStore( &Arg , tmpPtr ) ; 
 			NamedValues[varArgList.declList[j-1]->varIdent->name] = tmpPtr ;
		}
		j++;
	}
	Owner->setNamedField(thisCls);

	stmtList.codeGen();
	Value * retval;
	retval=rtnExpr->codeGen();
	Builder.CreateRet(retval);
	verifyFunction( *func ) ;
	//TheFPM->run(*func);
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
	Value *var = var_malloc ;
	//Builder.CreateBitCast(var_malloc,NamedClassDecls[tarIdent->name]->getClassLLVMType()->getPointerTo());
	// new GlobalVariable(*TheModule,
	//NamedClassDecls[tarIdent->name]->getClassLLVMType()
	//,false,GlobalValue::ExternalLinkage,nullptr);
	Value * vtableField = Builder.CreateStructGEP( NamedClassDecls[tarIdent->name]->getClassLLVMType() , var , 1 ) ;
	Builder.CreateStore(NamedClassDecls[tarIdent->name]->getVTableLoc(),vtableField);
	Value * clsNoField = Builder.CreateStructGEP( NamedClassDecls[tarIdent->name]->getClassLLVMType() , var , 0 ) ;
	Value * srcClsNo = ConstantInt::get(Type::getInt64Ty(getGlobalContext()),  NamedClassDecls[tarIdent->name]->classDeclNumber, true);
	Builder.CreateStore( srcClsNo ,clsNoField );
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

llvm::Type* UsrDefIdentType::llvmTypeGen() {
	if (tarType) return tarType;
	if ( NamedClassDecls.count( tarIdent->name ) == 0 ) {
		if ( NamedItfaceDecls.count( tarIdent->name ) == 0 ) {
			std::cout<<" [ IR ] Itface "<<tarIdent->name<<" is not defined."<<std::endl;
			return NULL;
		}
		cout << "is an interface" << endl ; 
		return Type::getInt64PtrTy(getGlobalContext());
	}
	ClassDecl* tarClassDecl = NamedClassDecls[tarIdent->name] ;
	if ( tarClassDecl == NULL ) {
		std::cout<<" [ IR ] Class "<<tarIdent->name<<" is not defined."<<std::endl;
		return NULL;
	}
	cout << "is a class" <<endl;
	tarType = tarClassDecl->getClassLLVMType()->getPointerTo();
	return tarType;
}

llvm::Type* VarArg::getLLVMType(){
    	if ( llvmType ) return llvmType ;
	llvmType = varType->llvmTypeGen();
	return llvmType;
}

llvm::Value* SysOutPrtStmt::codeGen() {
	llvm::Value* number = prtExpr->codeGen();
	llvm::Value* format = Builder.CreateGlobalStringPtr("%lld\n");

	std::vector<llvm::Type *> printfArgs;
	printfArgs.push_back(Builder.getInt8Ty()->getPointerTo());
	printfArgs.push_back(Builder.getInt64Ty());
	llvm::ArrayRef<llvm::Type*>  argsRef(printfArgs);

	llvm::FunctionType *printfType =
		llvm::FunctionType::get(Builder.getInt64Ty(), argsRef, false);
	llvm::Constant *printfFunc = TheModule->getOrInsertFunction("printf", printfType);

  	std::vector<llvm::Value *> printfValues = { format, number };

  	return Builder.CreateCall(printfFunc, printfValues);
}

llvm::Value* SysInReadExpr::codeGen() {
	llvm::Value* number = Builder.CreateAlloca( Builder.getInt64Ty(), 0, "" );
	llvm::Value* format = Builder.CreateGlobalStringPtr("%lld");

	std::vector<llvm::Type *> scanfArgs;
	scanfArgs.push_back(Builder.getInt8Ty()->getPointerTo());
	scanfArgs.push_back(Builder.getInt64Ty()->getPointerTo());
	llvm::ArrayRef<llvm::Type*> argsRef(scanfArgs);

	llvm::FunctionType *scanfType =
		llvm::FunctionType::get(Builder.getInt64Ty(), argsRef, false);
	llvm::Constant *scanfFunc = TheModule->getOrInsertFunction("scanf", scanfType);

	std::vector<llvm::Value *> scanfValues = { format, number };

	Builder.CreateCall(scanfFunc, scanfValues);

	return Builder.CreateLoad(number, "");
}
