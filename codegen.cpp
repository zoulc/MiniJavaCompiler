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
		std::cout << " [ Error ] < VarUseIdent > Identifier \'"<<name<<"\' doesn't exist." << std::endl ;
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
			std::cout << " [ Error ] < TypeUseIdent > Identifier \'"<<name<<"\' doesn't exist." << std::endl ;
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
			std::cout << " [ Error ] < UsrDefIdent > Invalid Identfier \'"<<tarIdent->name<<"\' ." << std::endl ;
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
	typeVec.push_back( Builder.getInt64Ty()->getPointerTo() ) ;
	std::vector<class VarArg*>::iterator vait ;
	for ( vait = varArgList.declList.begin() ; vait != varArgList.declList.end() ; vait ++ )
		typeVec.push_back( (*vait)->typeCheck()->llvmTypeGen() ) ;
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
	BasicBlock * func_entry= BasicBlock::Create(getGlobalContext() , absMtdIdent->name + std::string("_entry") , absMtdDynFunc );
	Builder.SetInsertPoint( func_entry ) ;

	Function* thisFunc = absMtdDynFunc ;
	vector<Value*> tempArg ;

	//ClearNamedValues();
	NamedValues.clear();
	cout<<" [ IR ] < AbsMtdDecl > Generate the concrete method fron the interfaces."<<endl;
	int j = 0 ;
	Value * clsIntPtr ;
	for( auto &Arg : thisFunc->args() ) {
		if ( j == 0 ) {
			clsIntPtr = &Arg ;
		} else {
			tempArg.push_back( &Arg ) ;
		}
		j++;
	}
	Value* clsNo = Builder.CreateLoad( clsIntPtr ) ;

	std::vector<class ClassDecl*>::iterator cit ;

	for ( cit = Owner->impClasses.begin() ; cit != Owner->impClasses.end() ; cit ++ )
	{
		ClassDecl* thisCls = (*cit);
		Value* condFindClass = Builder.CreateICmpEQ( clsNo , ConstantInt::get(Type::getInt64Ty(getGlobalContext()), thisCls->classDeclNumber , true)  );
		BasicBlock *ThenBB = BasicBlock::Create(getGlobalContext() );

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

	if ( type_check_level >= 1 ) std::cout<<" [ Type Check ] Abstract Method "<<absMtdIdent->name<<" is processing."<<std::endl ;
	rtnType->typeCheck();

	absMtdDeclType = new VoidType();
	return absMtdDeclType ;
}

TypeInfo* ItfaceDecl::typeCheck()
{
	if ( itfaceDeclType ) return itfaceDeclType ;
	// TODO: Postpone the extend of the interfaces
	if ( type_check_level >= 1 ) std::cout<<" [ Type Check ] Itface "<<itfaceIdent->name<<" is processing."<<std::endl ;

	std::vector< ExtItface * >::iterator eit ;
	for ( eit = extItfaceList.extList.begin() ; eit != extItfaceList.extList.end() ; eit ++ ) {
		if ( TypeNamedItfaceDecls.count((*eit)->extIdent->name) == 0 ) {
			std::cout<<" [ Error ] < ItfaceDecl "<<itfaceIdent->name<<" > Invalid extended Interface Name."<<std::endl ;
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
		(*cit)->codeGen();

	std::vector< class AbsMtdDecl* >::iterator ait ;
	for ( ait = absMtdDecl.begin() ; ait != absMtdDecl.end() ;  ait ++ )
		(*ait)->codeGen();

	isCodeGened = true ;
	return Constant::getNullValue(Type::getInt64Ty(getGlobalContext()));
}

llvm::Value* ItfaceDecl::getConcreMethod(std::string mtdName )
{
	if ( absMtdName2Pos.count(mtdName) == 0  ) {
		std::cout <<"  [ Error ] < Interface > Invalid Abstract Method . " << std::endl ;
		return NULL ;
	}
	int slot = absMtdName2Pos[mtdName];
	AbsMtdDecl* tarAbsMtdDecl = absMtdDecl[slot];
	return tarAbsMtdDecl->codeGen();
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
		cout<<" [ Error ] < ObjNewExpr > Class \'"<<tarIdent->name<<"\' is not defined"<<endl;
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
	std::cout <<"  [ Error ] < SiOpExpr > \"SiOpExpr\" should not be type checked. " << std::endl ;
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

TypeInfo* SysOutPrtCharStmt::typeCheck()
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


//New : Added for BiOpExpr's typecheck ;
TypeInfo* BiOpExpr::typeCheck()
{
	if ( exprType ) return exprType ;
	leftExpr->typeCheck();
	rightExpr->typeCheck();
	exprType = new IntType();
	return exprType ;
}

TypeInfo* GetMtdCallExpr::typeCheck()
{
	if ( exprType ) return exprType;
	if ( type_check_level >= 2 ) cout<<" [ Type Check ] < GetMtdCallExpr > Method "<<mtdIdent->name<<" is processing. "<<endl;
	if ( tarExpr->typeCheck() == NULL ) return NULL;
	if ( tarExpr->typeCheck()->typeName == "Class" ) {
		tarClassDecl = (( class ClassType* )tarExpr->typeCheck())->tarClassDecl ;

		if ( type_check_level >= 2 ) cout<<" [ Type Check ] < GetMtdCallExpr > Corresponding Class is "<<(( class ClassType* )tarExpr->typeCheck())->tarIdent->name <<'\n';
		tarClassDecl->typeCheck();

		//New : Added for fill List's type Check ;
		std::vector<Expr*>::iterator fit ;
		for ( fit = fillList.fillList.begin() ; fit != fillList.fillList.end() ; fit ++ )
			(*fit)->typeCheck();

		exprType = tarClassDecl->getMethodRtnType( mtdIdent->name ) ;
		isClass = true ;
		return exprType ;
	} else {
		if ( tarExpr->typeCheck()->typeName == "Itface") {
			tarItfaceDecl = (( class ItfaceType* )tarExpr->typeCheck())->tarItfaceDecl ;
			tarItfaceDecl->typeCheck();

			//New : Added for fill List's type Check ;
			std::vector<Expr*>::iterator fit ;
			for ( fit = fillList.fillList.begin() ; fit != fillList.fillList.end() ; fit ++ )
				(*fit)->typeCheck();

			exprType = tarItfaceDecl->getAbsMethodRtnType( mtdIdent->name ) ;
			isClass = false ;
			return exprType ;
		} else {
			std::cout << " [ Error ] < GetMtdCallExpr > Invalid Caller\'s Type ." << std::endl ;
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
	if ( type_check_level >= 1 ) cout<<" [ Type Check ] < IdentAccessExpr > Access @"<<tarIdent->name<<" is processing . "<<endl;
	if ( TypeNamedValues.count( tarIdent->name ) == 0 ) {
		cout<<" [ Error ] < IdentAccessExpr > Invalid Identifier \'"<<tarIdent->name<<"\' . "<<endl;
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
	if ( type_check_level >= 1 ) cout << " [ Type Check ] < ClassDecl > " << classIdent->name << " is processing ." << endl ;
	TypeNamedClassDecls[ classIdent->name ] = this ;
	NamedClassDecls[ classIdent->name ] = this ;
	classDeclType = new VoidType();

	//Fetch Base Class and load methods and fields from it .
	if ( type_check_level >= 2 ) std::cout << " [ Type Check ] < ClassDecl > " << classIdent->name << " now is processing on its base class ."<< std::endl ;
	if ( extClassIdent != NULL ) {
		std::string extClassName = extClassIdent->name ;
		if ( NamedClassDecls[extClassName] == 0 ) {
			std::cout<<" [ Error ] < ClassDecl > "<<classIdent->name<<"'s base class hasn't been defined."<<std::endl;
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
				std::cout<<" [ Error ] < ClassDecl > "<<classIdent->name<<"'s field which named "<< (*vit)->varIdent->name <<" haven't defined. "<< std::endl;
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
			std::cout<<" [ Error ] < ClassDecl > Invalid Implemented Interface \'"<<(*iit)->impIdent->name<<"\'."<<std::endl ;
			continue ;
		}
		ItfaceDecl* tarItface = TypeNamedItfaceDecls[ (*iit)->impIdent->name ] ;
		tarItface->typeCheck();
		impItfaces.push_back( tarItface ) ;
		tarItface->AddImpClass( this ) ;
	}

	//After that , prepare its own fields and methods .
	if ( type_check_level >= 2 ) std::cout << " [ Type Check ] < ClassDecl > " << classIdent->name << " initialize the fields . "<< std::endl ;
	std::vector<class VarDecl*>::iterator vit;
	for( vit = (varDeclList.declList).begin() ; vit != (varDeclList.declList).end() ; vit++ ) {
		TypeInfo* itType = (*vit)->typeCheck();
		if ( itType == NULL ) {
			std::cout<<" [ Error ] < ClassDecl > "<<classIdent->name<<"'s field which named "<< (*vit)->varIdent->name << " haven't defined ." <<std::endl;
			return NULL ;
		}
		fieldDecl.push_back((*vit));
		fieldName2Pos[(*vit)->varIdent->name] = 1 + fieldDecl.size();
		//because of the class type number of the 1 offset .
		//and the class number of the 0 offset
	}

	if ( type_check_level >= 2 ) std::cout << " [ Type Check ] < ClassDecl > Class " << classIdent->name << " initialize the methods ."<< std::endl ;
	std::vector<class MtdDecl*>::iterator mit;
	for( mit = (mtdDeclList.declList).begin() ; mit !=(mtdDeclList.declList).end() ; mit++ ) {
		if ( type_check_level >= 2 ) std::cout << " [ Type Check ] < ClassDecl > Add the method "<<(*mit)->mtdIdent->name<<" to Class "<<classIdent->name<<std::endl;
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
		if ( varType->isUsrDefIdentType() ) {
			return ( ( ( UsrDefIdentType* ) varType )->getConcreType()) ;
		} else
			return varType ;
	}
	return NULL ;
}

TypeInfo* MtdDecl::typeCheck() {
	if ( type_check_level >= 1 ) std::cout << " [ Type Check ] < MtdDecl > Method " << mtdIdent->name << " is processing ."<< std::endl ;
	if ( mtdDeclType ) return mtdDeclType ;
	mtdDeclType = new VoidType();
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
	return mtdDeclType ;
}

TypeInfo* ClassDecl::getMethodRtnType( std::string mtdName ) {
	typeCheck();
	std::vector<class MtdDecl*>::iterator mit ;
	for ( mit = mtdDecl.begin() ; mit != mtdDecl.end() ; mit ++ ) {
		if ( (*mit)->mtdIdent->name == mtdName )
			return (*mit)->rtnExpr->typeCheck() ;
	}
	cout<<" [ Error ] Method \'"<<mtdName<<"\' Not Found"<<endl;
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
	if ( code_gen_level >= 1 ) std::cout << " [ IR ] Creating integer literature: " << value << endl;
	return ConstantInt::get(Type::getInt64Ty(getGlobalContext()), value, true);
}

Value*  TrueLiterExpr :: codeGen()
{
	if ( code_gen_level >= 1 ) std::cout << " [ IR ] Creating bool literature: " << value << endl;
	return ConstantInt::get(Type::getInt64Ty(getGlobalContext()), value, false);
}

Value*  FalseLiterExpr :: codeGen()
{
	if ( code_gen_level >= 1 ) std::cout << " [ IR ] Creating bool literature: " << value << endl;
	return ConstantInt::get(Type::getInt64Ty(getGlobalContext()), value, false);
}

/* SiOpExpr.h */

Value* NegExpr::codeGen()
{
	if ( code_gen_level >= 1 ) std::cout << "Creating single operation Neg " << endl;
	return Builder.CreateSub(
		ConstantInt::get(Type::getInt64Ty(getGlobalContext()), 0, true),
							  tarExpr->codeGen(),
							  "");
}

Value* ParenExpr::codeGen()
{
	if ( code_gen_level >= 1 ) std::cout << "Creating single operation Paren " << endl;
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
	/*  Used for lambda  */
	NamedValuesAccess(assignIdent->name);

	if(NamedValues[assignIdent->name]==0)
	{
		std::cout<<" [ Error ] < AssignStmt > Undefined Value\n";
		return nullptr;
	}
	Value * rval=valueExpr->codeGen();
	//std::cout << "Creating Assignment statement for variable " << assignIdent->name << endl;
	//Value * ptrCast = Builder.CreatePointerCast( NamedValues[assignIdent->name] , (valueExpr->typeCheck())->llvmTypeGen() );
	Value * ptrCast = CreatePtrAdd( NamedValues[assignIdent->name] ,0, rval->getType()->getPointerTo() );
	Builder.CreateStore(rval,ptrCast);
	//std::cout << "Store instruction created" << endl;
	return NamedValues[assignIdent->name];
}

/* StmtList.h*/

Value * StmtList::codeGen()
{
	std::vector <class Stmt * >::iterator i;
	Value * res=Constant::getNullValue(Type::getInt64Ty(getGlobalContext()));
	for(i=stmtList.begin();i!=stmtList.end();i++){
//		std::cout<<" The "<<(i-stmtList.begin())<< " Stmt is pointing to "<<(long long)(*i)<<endl ;
	}
	for(i=stmtList.begin();i!=stmtList.end();i++){
//		std::cout<< " Now is processing on the Stmt Points to "<<(long long )( *i)<<" "<<(i-stmtList.begin())<<std::endl;
		res=(*i)->codeGen();
	}
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

llvm::Value* GreaterCmpExpr::codeGen()
{
    return Builder.CreateICmpSGT( leftExpr->codeGen() , rightExpr->codeGen() , "ultcmptmp");
}

llvm::Value* EqualCmpExpr::codeGen()
{
    return Builder.CreateICmpEQ( leftExpr->codeGen() , rightExpr->codeGen() , "ultcmptmp");
}

llvm::Value* NotEqualCmpExpr::codeGen()
{
    return Builder.CreateICmpNE( leftExpr->codeGen() , rightExpr->codeGen() , "ultcmptmp");
}

llvm::Value* InsOfExpr::codeGen()
{
	Value * intPtrCast = Builder.CreatePointerCast( tarExpr->codeGen() , Type::getInt64Ty(getGlobalContext()) ) ;
	Value * tarClsNo = Builder.CreateLoad( intPtrCast ) ;
	if ( ! srcType->isUsrDefIdentType() ) {
		std::cout<<" [ Error ] < InsOfExpr > Invalid class Type." <<std::endl;
		return NULL ;
	}
	TypeInfo * tarType = ( ( UsrDefIdentType * ) srcType )->getConcreType() ;
	if ( tarType->typeName != "Class" ) {
		std::cout<<" [ Error ] < InsOfExpr > Invalid class Type." <<std::endl;
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
	tarType = Type::getInt64Ty(getGlobalContext())->getPointerTo();
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
    /*  Used for lambda  */
	//std::cout<<"VarDeclStmt Points to "<<(long long)(this)<<std::endl;
	//td::cout<<"VarDeclStmt Name is "<<varIdent->name<<std::endl;
	//NamedValuesAccess(varIdent->name);
	if ( ! ( NamedValues[varIdent->name] == 0) ) {
            std::cout<<" [ Error ] < VarDeclStmt > Redefinition of the same name "<<varIdent->name<<" .\n";
        return NULL ;
    }
    Value * targetValue =
        Builder.CreateAlloca( tarType , 0 , varIdent->name ) ;
    NamedValues[varIdent->name] = targetValue ;
	/*  Used for lambda  */
	NamedValuesLevel[varIdent->name]=LambdaLevel;

    return targetValue ;
}

llvm::Value* IdentAccessExpr::codeGen() {
	/*  Used for lambda  */

	NamedValuesAccess(tarIdent->name);

	if ( NamedValues[tarIdent->name] == 0 ) {
        std::cout<<" [ Error ] < IdentAccessExpr > Value Not Defined ."<<std::endl ;
    }
    return Builder.CreateLoad( NamedValues[tarIdent->name] , "loadvar" );
}

llvm::Type* VarDecl::getLLVMType()
{
	if (llvmType) return llvmType ;
	llvmType = varType->typeCheck()->llvmTypeGen();
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
	if ( code_gen_level >= 1 ) std::cout << " [ IR ] < getClassLLVMType > Class " << classIdent->name << " now is processing on its LLVM type ."<< std::endl ;
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
	if ( code_gen_level >= 2 ) std::cout << " [ IR ] < getClassLLVMType > Class " << classIdent->name << " create a oblique identifed type ."<< std::endl ;
	classLLVMType = StructType::create(Builder.getContext() , className );

	//Generate LLVM Type for every fields .
	if ( code_gen_level >= 2 ) std::cout << " [ IR ] < getClassLLVMType > Class " << classIdent->name << " generate the LLVM Type for the fields ."<< std::endl ;
	std::vector<class VarDecl*>::iterator it;
	for( it = fieldDecl.begin() ;
		 it != fieldDecl.end() ; it++ ) {
		llvm::Type* itType = (*it)->getLLVMType();
		if ( itType == NULL ) {
			std::cout<<" [ Error ] < ClassDecl > "<<classIdent->name<<
			"'s field which named "<< (*it)->varIdent->name<<" has an invalid type . " << std::endl;
			return NULL ;
		}
	}

	std::vector<llvm::Type*> classTypeVec;
	classTypeVec.clear();

	//push the Class Identfier Number into the Struct Type
	classTypeVec.push_back( Type::getInt64Ty(getGlobalContext()) ) ;

	//push the VTable of Function into the classTypeVec
	if ( code_gen_level >= 2 ) std::cout << " [ IR ] < getClassLLVMType > Class " << classIdent->name << " initial the VTable's type ."<< std::endl ;
	classTypeVec.push_back( getVTableType()->getPointerTo() );

	//push the fields' types into the class TypeVec
	if ( code_gen_level >= 2 ) std::cout << " [ IR ] < getClassLLVMType > Class " << classIdent->name << " fill the whole type ."<< std::endl ;
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
	if ( code_gen_level >= 1 ) std::cout << " [ IR ] < getVTableType > Class " << classIdent->name << " now is processing on its VTable's LLVM type ."<< std::endl ;
	// ABANDONED : getBaseClass();
	//make an oblique identified class type , then fill some thing into it.
	if ( code_gen_level >= 2 ) std::cout << " [ IR ] < getVTableType > Class " << classIdent->name << " create an oblique type ."<< std::endl ;
	vtableType = StructType::create(Builder.getContext() , (classIdent->name) + std::string("_vtable"));

	if ( code_gen_level >= 2 ) std::cout << " [ IR ] < getVTableType > Class " << classIdent->name << " get the methods' types and fill the whole VTable type ."<< std::endl ;
	std::vector<llvm::Type*> vtableTypeVec;
	vtableTypeVec.clear();
	std::vector<class MtdDecl*>::iterator mit;
	for( mit = mtdDecl.begin() ; mit != mtdDecl.end() ; mit++ ) {
		if ( code_gen_level >= 2 ) std::cout << " [ IR ] < getVTableType > Add method " << (*mit)->mtdIdent->name << " to vtable ."<<std::endl;
		vtableTypeVec.push_back( (*mit)->getFunctionType());
	}

	cast<StructType>(vtableType)->setBody( vtableTypeVec );
	if ( code_gen_level >= 1 ) std::cout << " [ IR ] < getVTableType > Class " << classIdent->name << " 's VTable's type has been processed successfully ."<< std::endl ;
	return vtableType ;
}

void ClassDecl::setNamedField( llvm::Value* thisClass )
{
	if ( code_gen_level >= 1 )
		std::cout<<" [ IR ] < setNamedField > Adding the class's fields into Variable Table. "<<std::endl; 
	if ( ! ( isa<PointerType>( thisClass->getType() ) ) ) {
		std::cout<<" [ Error ] < setNamedField > Class-Pointer has an invalid type. "<<std::endl;
	}
	Value * selClass = Builder.CreateLoad( thisClass ) ;
	if ( ! ( selClass->getType() == getClassLLVMType() ) ) {
		std::cout<<" [ Error ] < setNamedField > Class-Pointer has an invalid type. "<<std::endl;
	}
	Value * test = Builder.CreateAlloca( getClassLLVMType() ) ;
	if ( ! ( test->getType()  == getClassLLVMType()->getPointerTo() ) ) {
	//	std::cout<<" Testing ! Error occurs ! " <<std::endl;
	}
	std::vector<class VarDecl*>::iterator it;
	for( it = fieldDecl.begin() ;
	     it != fieldDecl.end() ; it++ ) {
		if ( code_gen_level >= 2 ) std::cout<<" [ IR ] < setNamedField > Add the field "<<(*it)->varIdent->name<<" at Pos :"<< fieldName2Pos[(*it)->varIdent->name]<<" into NamedValues ."<<std::endl;
		NamedValues[ (*it)->varIdent->name ]
			= Builder.CreateStructGEP( getClassLLVMType() , thisClass , fieldName2Pos[(*it)->varIdent->name] );

		/*  Used for lambda  */
		NamedValuesLevel[ (*it)->varIdent->name ]=LambdaLevel;
		IsField[ (*it)->varIdent->name ]=1;
	}
	/*  Used for lambda  */
	ClassDecl* LambdaOnwer=this;
	if ( code_gen_level >= 1 )
		std::cout<<" [ IR ] < setNamedField > Finished successfully. "<<std::endl; 
}

int ClassDecl::getMethodId(std::string mtdName)
{
	if ( mtdName2Pos.count(mtdName) == 0 ) {
		std::cout<<" [ Error ] < getMethodId > "<<mtdName<<" is not a valid method."<<std::endl;
		return -1 ;
	}
	return mtdName2Pos[mtdName];
}

llvm::Type* ClassDecl::getMethodType(std::string mtdName)
{
	if ( mtdName2Pos.count(mtdName) == 0 ) {
		std::cout<<" [ Error ] < getMethodType > "<<mtdName<<" is not a valid method."<<std::endl;
		return NULL ;
	}
	int mtd_id = mtdName2Pos[mtdName];
	return mtdDecl[mtd_id]->getFunctionType();
}

llvm::Value* ClassDecl::getVTableLoc()
{
	if ( code_gen_level >= 1 ) 
		std::cout << " [ IR ] < getVTableLoc > Class " << classIdent->name << " now is processing on its VTable's Global Location ."<< std::endl ;
	if (vtableLoc) return vtableLoc ;
	getVTableType();

	std::vector< Constant* > vtableFuncVec ;

	if ( code_gen_level >= 2 ) 
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

	if ( code_gen_level >= 2 ) 
		std::cout << " [ IR ] < getVTableLoc > Class " << classIdent->name << " generate the initial constants ."<< std::endl ;
	llvm::ArrayRef< Constant* > vtableInitial(vtableFuncVec);

	if ( code_gen_level >= 2 ) 
		std::cout << " [ IR ] < getVTableLoc > Class " << classIdent->name << " generate the global table with constants ."<< std::endl ;
	vtableLoc = new GlobalVariable( *TheModule,
		cast<StructType>(getVTableType()), true, GlobalValue::ExternalLinkage ,
		ConstantStruct::get( cast<StructType>(getVTableType()) , vtableInitial ) ,
		classIdent->name + std::string("_vatble_loc") );

	if ( code_gen_level >= 1 ) 
		std::cout << " [ IR ] < getVTableLoc > Class " << classIdent->name << " has prepared its VTable's Global Location successfully ."<< std::endl ;
	return vtableLoc;
}

llvm::Value* ClassDecl::codeGen()
{
    if ( code_gen_level >= 1 ) 
	std::cout << " [ IR ] < ClassDecl::codeGen > Class " << classIdent->name << " now is processing ."<< std::endl ;
    getClassLLVMType();
    std::vector<class MtdDecl*>::iterator mit;
    for( mit = mtdDecl.begin() ;
	mit != mtdDecl.end() ; mit++ ) {
	//cout<< (*mit)->mtdIdent->name << endl;
	(*mit)->getFunction();
    }
    for( mit = mtdDecl.begin() ;
	mit != mtdDecl.end() ; mit++ )
		(*mit)->codeGen();

    if ( code_gen_level >= 1 ) 
	std::cout << " [ IR ] < ClassDecl::codeGen > Class " << classIdent->name << " has been generated successfuly ."<< std::endl ;
    return Constant::getNullValue(Type::getInt64Ty(getGlobalContext()));
}

Value * GetMtdCallExpr::codeGen()
{
    if ( code_gen_level >= 1 ) std::cout << " [ IR ] < CetMtdCallExpr::codeGen > now is processing."<< std::endl ;
	if ( isClass ) {
    if ( code_gen_level >= 2 ) std::cout << " [ IR ] < CetMtdCallExpr::codeGen > CH0"<< std::endl ;
    if ( code_gen_level >= 2 ) std::cout << " [ IR ] < CetMtdCallExpr::codeGen > tarExpr: "<<(((ClassType*)(tarExpr->typeCheck()))->tarIdent)<< std::endl ;
		ClassDecl* tarClassDecl = ((ClassType*)(tarExpr->typeCheck()))->tarClassDecl;
    if ( code_gen_level >= 2 ) std::cout << " [ IR ] < CetMtdCallExpr::codeGen > CH0.5"<< std::endl ;
		int mtdSlot = tarClassDecl->getMethodId(mtdIdent->name) ;
    if ( code_gen_level >= 2 ) std::cout << " [ IR ] < CetMtdCallExpr::codeGen > "<<mtdSlot<< std::endl ;
		MtdDecl*   tarMtdDecl   = tarClassDecl->mtdDecl[mtdSlot];
		//ClassDecl* tarFormClassDecl = tarMtdDecl->formOwner ;

    if ( code_gen_level >= 2 ) std::cout << " [ IR ] < CetMtdCallExpr::codeGen > CH1"<< std::endl ;
		vector <Value*> arg;
		//cout<<tarFormClassDecl->classIdent->name<<endl;
		FunctionType* funcType=tarMtdDecl->func_type;

    if ( code_gen_level >= 2 ) std::cout << " [ IR ] < CetMtdCallExpr::codeGen > CH2"<< std::endl ;
		Value* Ptr = Builder.CreateAlloca( funcType->params()[0]) ;
		Value* PtrV=tarExpr->codeGen();
    if ( code_gen_level >= 2 ) std::cout << " [ IR ] < CetMtdCallExpr::codeGen > CH3"<< std::endl ;
		Value* _Ptr=CreatePtrAdd(Ptr,0,PtrV->getType()->getPointerTo());
    if ( code_gen_level >= 2 ) std::cout << " [ IR ] < CetMtdCallExpr::codeGen > CH4"<< std::endl ;
		Builder.CreateStore(PtrV,_Ptr);
    if ( code_gen_level >= 2 ) std::cout << " [ IR ] < CetMtdCallExpr::codeGen > CH5"<< std::endl ;
		arg.push_back( Builder.CreateLoad(Ptr) );
		int i;
    if ( code_gen_level >= 2 ) std::cout << " [ IR ] < CetMtdCallExpr::codeGen > CH6"<< std::endl ;
		for(i=0;i<(fillList.fillList.size());i++)
		{
			Ptr = Builder.CreateAlloca( funcType->params()[i+1]) ;
			PtrV=fillList.fillList[i]->codeGen();
			Builder.CreateStore(PtrV,CreatePtrAdd(Ptr,0,PtrV->getType()->getPointerTo()));
			arg.push_back( Builder.CreateLoad( Ptr ) );
		}
    if ( code_gen_level >= 2 ) std::cout << " [ IR ] < CetMtdCallExpr::codeGen > CH7"<< std::endl ;
		Value * arg0=CreatePtrAdd(arg[0],0,tarClassDecl->getClassLLVMType()->getPointerTo());
		Value * my_vtable=Builder.CreateLoad(Builder.CreateStructGEP(tarClassDecl->getClassLLVMType(),arg0,1));
    if ( code_gen_level >= 2 ) std::cout << " [ IR ] < CetMtdCallExpr::codeGen > CH8"<< std::endl ;
		Value * my_func_p=Builder.CreateStructGEP(tarClassDecl->getVTableType(),my_vtable, mtdSlot );
    if ( code_gen_level >= 2 ) std::cout << " [ IR ] < CetMtdCallExpr::codeGen > CH9"<< std::endl ;
		Value * my_func=Builder.CreateLoad(my_func_p);
    if ( code_gen_level >= 2 ) std::cout << " [ IR ] < CetMtdCallExpr::codeGen > CH10"<< std::endl ;

		ArrayRef<Value*> argRef(arg);
		return Builder.CreateCall(my_func,argRef);

	} else {

		ItfaceDecl* tarItfaceDecl = ((ItfaceType*)tarExpr->typeCheck())->tarItfaceDecl ;
		int absMtdSlot = tarItfaceDecl->absMtdName2Pos[ mtdIdent->name ];
		AbsMtdDecl* tarAbsMtdDecl = tarItfaceDecl->absMtdDecl[absMtdSlot];

		vector <Value*> arg;
		//cout<<tarExpr->typeCheck()->typeName<<endl;
		//cout<<tarAbsMtdDecl->absMtdIdent->name<<endl;
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
		std::map<std::string,llvm::Value*> tempMap(NamedValues);
		Value * my_func = tarItfaceDecl->getConcreMethod(mtdIdent->name);
		NamedValues.clear();
		NamedValues = tempMap ;
		Value * result = Builder.CreateCall(my_func,argRef);
		return result ;

/*
		vector<Value*> arg;
		Value* tmpV = tarExpr->codeGen() ;
		Value* firPtr = Builder.CreatePointerCast( tmpV ,  ) ;
		arg.push_back(firPtr);
		int i;
		for(i=0;i<(fillList.fillList.size());i++)
			arg.push_back(fillList.fillList[i]->codeGen());
		ArrayRef<Value*> argRef(arg);

		if(tarExpr->typeCheck()->typeName!="Itface")
			std::cout<<" [ Type Check ] Error tarExp Type in GetMtdCallExpr --"<<tarExpr->typeCheck()->typeName<<endl;
		string ItfaceName=((ItfaceType*)tarExpr->typeCheck())->tarIdent->name;
		cout<<"Debug :"<<ItfaceName<<endl;
		ItfaceDecl* tarItfaceDecl = ((ItfaceType*)tarExpr->typeCheck())->tarItfaceDecl ;

		cout<<"Debug : After getting the interface's decl."<<endl;

		Value * my_func = tarItfaceDecl->getConcreMethod(mtdIdent->name);

		cout<<"Debug : After get concrete method from the interface."<<endl;
		return Builder.CreateCall(my_func,argRef);
*/
	}
	return NULL ;
}

Type * MtdDecl::getFunctionType()
{
	if( llvmType == NULL ) {
		if ( code_gen_level >= 1 ) std::cout << " [ IR ] Class " << Owner->classIdent->name << "'s method "<<mtdIdent->name<<" now is processing on its LLVM type ."<< std::endl ;
		vector<Type*> typeVec ;
		typeVec.clear();
		typeVec.push_back( formOwner->getClassLLVMType()->getPointerTo() ) ;
		std::vector<class VarArg*>::iterator vait ;
		for ( vait = varArgList.declList.begin() ; vait != varArgList.declList.end() ; vait ++ )
			typeVec.push_back( (*vait)->typeCheck()->llvmTypeGen() ) ;
		ArrayRef<Type*> argTypeVec( typeVec ) ;
		llvmType =func_type= FunctionType::get(rtnType->llvmTypeGen(),argTypeVec,false);
		func = Function::Create( cast<FunctionType>(llvmType) , Function::ExternalLinkage , Owner->classIdent->name + std::string("_") + mtdIdent->name , TheModule);
		llvmType = func->getType();
	}
	return llvmType;
}

Function * MtdDecl::codeGen()
{
	if ( code_gen_level >= 1 ) std::cout << " [ IR ] Class " << Owner->classIdent->name << "'s method "<<mtdIdent->name<<" now is processing on its IR code ."<< std::endl ;
	BasicBlock * func_entry= BasicBlock::Create(getGlobalContext() , mtdIdent->name + std::string("_entry") , func);
	Builder.SetInsertPoint( func_entry ) ;

	ClearNamedValues();

	Value * thisCls ;
	int j = 0 ;
	for( auto &Arg : func->args() ) {
		if ( j == 0 ) {
			thisCls = Builder.CreatePointerCast( &Arg , Owner->getClassLLVMType()->getPointerTo() )  ;
			Value * tmpPtr = Builder.CreateAlloca( Owner->getClassLLVMType()->getPointerTo() , 0 );
			Builder.CreateStore( thisCls , tmpPtr );
			NamedValues[std::string("this")] = tmpPtr ;

			/*  Used for lambda  */
			NamedValuesLevel[std::string("this")]=LambdaLevel;
		} else {
			// Add the Alloca Instruction for the Argments
			//cout<<varArgList.declList[j-1]->varIdent->name<<endl;

			Value* tmpPtr = Builder.CreateAlloca( varArgList.declList[j-1]->typeCheck()->llvmTypeGen() , 0 ) ;
			Builder.CreateStore( &Arg , tmpPtr ) ;
 			tmpPtr = Builder.CreatePointerCast( tmpPtr , varArgList.declList[j-1]->typeCheck()->llvmTypeGen()->getPointerTo() );
			NamedValues[varArgList.declList[j-1]->varIdent->name] = tmpPtr ;

			/*  Used for lambda  */
			NamedValuesLevel[varArgList.declList[j-1]->varIdent->name]=LambdaLevel;
		}
		j++;
	}
	Owner->setNamedField(thisCls);

	if ( code_gen_level >= 2 ) std::cout << " [ IR ] Ch1 Class " << Owner->classIdent->name << "'s method "<<mtdIdent->name<<" have been generated successfully  ."<< std::endl ;
	stmtList.codeGen();
	if ( code_gen_level >= 2 ) std::cout << " [ IR ] Ch2 Class " << Owner->classIdent->name << "'s method "<<mtdIdent->name<<" have been generated successfully  ."<< std::endl ;
	Value * retval;
	retval=rtnExpr->codeGen();
	if ( code_gen_level >= 2 ) std::cout << " [ IR ] Ch3 Class " << Owner->classIdent->name << "'s method "<<mtdIdent->name<<" have been generated successfully  ."<< std::endl ;
	Builder.CreateRet(retval);
	if ( code_gen_level >= 2 ) std::cout << " [ IR ] Ch4 Class " << Owner->classIdent->name << "'s method "<<mtdIdent->name<<" have been generated successfully  ."<< std::endl ;
	verifyFunction( *func ) ;
	//TheFPM->run(*func);
	if ( code_gen_level >= 2 ) std::cout << " [ IR ] Class " << Owner->classIdent->name << "'s method "<<mtdIdent->name<<" have been generated successfully  ."<< std::endl ;
	return NULL;
}

Function * MtdDecl::getFunction()
{
	if ( isCreated ) return func ;
	if ( code_gen_level >= 2 ) std::cout << " [ IR ] Class " << Owner->classIdent->name << "'s method "<<mtdIdent->name<<" now is processing."<< std::endl ;
	getFunctionType();
	//codeGen();
	isCreated = true ;
	if ( code_gen_level >= 2 ) std::cout << " [ IR ] Class " << Owner->classIdent->name << "'s method "<<mtdIdent->name<<" has been processed successfully ."<< std::endl ;
	return func;
}

Value* ObjNewExpr::codeGen()
{

	if ( code_gen_level >= 1 ) std::cout << " [ IR ] < ObjNewExpr::codeGen > Now allocating an object ."<< std::endl ;
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
			std::cout<<" [ Error ] Itface \'"<<tarIdent->name<<"\' is not defined."<<std::endl;
			return NULL;
		}
		return Builder.getInt64Ty()->getPointerTo();
	}
	ClassDecl* tarClassDecl = NamedClassDecls[tarIdent->name] ;
	if ( tarClassDecl == NULL ) {
		std::cout<<" [ Error ] Class \'"<<tarIdent->name<<"\' is not defined."<<std::endl;
		return NULL;
	}
	//cout<<tarClassDecl->classIdent->name<<endl;
	tarType = tarClassDecl->getClassLLVMType()->getPointerTo();
	return tarType;
}

llvm::Type* VarArg::getLLVMType(){
    	if ( llvmType ) return llvmType ;
	llvmType = varType->typeCheck()->llvmTypeGen();
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

llvm::Value* SysOutPrtCharStmt::codeGen() {
	llvm::Value* number = prtExpr->codeGen();
	llvm::Value* format = Builder.CreateGlobalStringPtr("%c");

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

llvm::Value* SysInReadCharExpr::codeGen() {
	llvm::Value* number = Builder.CreateAlloca( Builder.getInt64Ty(), 0, "" );
	llvm::Value* zero = ConstantInt::get(Type::getInt64Ty(getGlobalContext()), 0, true);
	Builder.CreateStore(zero, number);
	llvm::Value* format = Builder.CreateGlobalStringPtr("%c");

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
/*  Used for lambda  */

void MtdDecl::ClearNamedValues()
{
	NamedValues.clear();
	LambdaLevel=1;
	LambdaArgCount.resize(LambdaLevel+1);
	LambdaArgStart.resize(LambdaLevel+1);
	LambdaBB.resize(LambdaLevel+1);
	FunctionArgStart.resize(LambdaLevel+1);
	FunctionBB.resize(LambdaLevel+1);
	LambdaArgCount[LambdaLevel]=0;
	LambdaArgStart[LambdaLevel]=0;
	LambdaBB[LambdaLevel]=0;
	IsField.clear();
	LambdaOwner=Owner;
}

void NamedValuesAccess(string name)
{
	if(IsField[name])
	{
		if(NamedValuesLevel[name]&&NamedValuesLevel[name]<LambdaLevel)
		{
			if ( code_gen_level >= 1 ) std::cout<<" [ Lambda ] Field Access\n";
			NamedValuesAccess("this");
			Value * thisClass=Builder.CreateLoad(NamedValues["this"]);
			if ( code_gen_level >= 1 ) std::cout<<" [ Lambda ] this Access finish\n";
			std::vector<class VarDecl*>::iterator it;
			for( it = LambdaOwner->fieldDecl.begin() ;
				it != LambdaOwner->fieldDecl.end() ; it++ ) {
					NamedValues[ (*it)->varIdent->name ]
						= Builder.CreateStructGEP( LambdaOwner->getClassLLVMType() , thisClass , LambdaOwner->fieldName2Pos[(*it)->varIdent->name] );
					NamedValuesLevel[ (*it)->varIdent->name ]=LambdaLevel;
				}
		}
		return;
	}
	BasicBlock * OldBB=Builder.GetInsertBlock();
	for(;NamedValuesLevel[name]&&NamedValuesLevel[name]<LambdaLevel;)
	{
		if ( code_gen_level >= 1 ) std::cout << " [ Lambda ]  Access Value "<<name<<" At Level "<<NamedValuesLevel[name]<<'\n';
		ArgValuesAccess(name,NULL,NamedValuesLevel[name]+1);
	}
	Builder.SetInsertPoint( OldBB ) ;
}

Value* CreatePtrAdd(Value * Ptr, int offset,Type* AfterPtr)
{
	Value *tmp;
	tmp=Builder.CreatePtrToInt(Ptr,Type::getInt64Ty(getGlobalContext()));
	tmp=Builder.CreateAdd(tmp,ConstantInt::get(Type::getInt64Ty(getGlobalContext()),offset, true));
	tmp=Builder.CreateIntToPtr(tmp,AfterPtr);
	return tmp;
}

void ArgValuesAccess(string name,Type* ArgPtrType,int Level)
{
	if(ArgPtrType==NULL)
	{
		if(NamedValues[name]==NULL)
		{
			if ( code_gen_level >= 1 ) cout<<" [ Lambda ] ArgValuesAccess Error\n";
			return;
		}
		ArgPtrType=NamedValues[name]->getType();
	}
	if ( code_gen_level >= 1 ) cout<<" [ Lambda ] ArgValuesAccess CH1\n";
	Builder.SetInsertPoint( LambdaBB[Level] ) ;
	int offset=8*(++LambdaArgCount[Level]);
	if ( code_gen_level >= 1 ) cout<<" [ Lambda ] ArgValuesAccess CH2\n";
	Value* addr;
	if(NamedValues[name]!=NULL)
	{
		addr = LambdaArgStart[Level];
		addr=CreatePtrAdd(addr,offset,ArgPtrType);
		Builder.CreateStore(Builder.CreateLoad(NamedValues[name]),addr);
	}
	if ( code_gen_level >= 1 ) cout<<" [ Lambda ] ArgValuesAccess CH3\n";

	Builder.SetInsertPoint( FunctionBB[Level] ) ;
	addr = FunctionArgStart[Level];
	addr=CreatePtrAdd(addr,offset,ArgPtrType);
	if ( code_gen_level >= 1 ) cout<<" [ Lambda ] ArgValuesAccess CH4\n";
	if ( code_gen_level >= 1 ) cout<<" [ Lambda ] "<<name<<" at offset "<<offset<<" Level "<<Level<<"\n";
	NamedValues[name] = addr;

	NamedValuesLevel[name] = Level;
}

FunctionType* GetLambdaType()
{
	static FunctionType* LT=NULL;
	if(LT==NULL)
	{
		vector<Type*> _type_list_1;
		_type_list_1.clear();
		_type_list_1.push_back(Type::getInt64Ty(getGlobalContext())->getPointerTo());
		ArrayRef<Type*> _type_list_2 ( _type_list_1 ) ;
		LT=FunctionType::get(Type::getInt64Ty(getGlobalContext()),_type_list_2,false);
	}
	return LT;
}

Type* GetIntType()
{
	return Type::getInt64Ty(getGlobalContext());
}

Value* LamdaGenExpr::codeGen() {

	map<string, int> __NamedValuesLevel(NamedValuesLevel);
	map<string, Value*> __NamedValues(NamedValues);
	BasicBlock * OldBB=Builder.GetInsertBlock();
	Value * SizeAddr = Builder.CreateAlloca( Builder.getInt64Ty(),0, "" );
	BasicBlock * Entry= BasicBlock::Create(getGlobalContext() , "lambdapre" , Builder.GetInsertBlock()->getParent());

	if ( code_gen_level >= 1 ) std::cout << " [ Lambda ]  Malloc Data\n";
	/* Lambda Data */
	LambdaLevel++;
	LambdaArgCount.resize(LambdaLevel+1);
	LambdaArgStart.resize(LambdaLevel+1);
	LambdaBB.resize(LambdaLevel+1);
	FunctionArgStart.resize(LambdaLevel+1);
	FunctionBB.resize(LambdaLevel+1);
	LambdaArgCount[LambdaLevel]=0;
	LambdaBB[LambdaLevel]=Entry;

	if ( code_gen_level >= 1 ) std::cout << " [ Lambda ]  Create Function\n";
	/* Function Create */
	Function * func=Function::Create(  GetLambdaType(), Function::ExternalLinkage , "" , TheModule);
	FunctionBB[LambdaLevel]= BasicBlock::Create(getGlobalContext() , "loaddata" , func);
	Builder.SetInsertPoint(FunctionBB[LambdaLevel]);
	for( auto &Arg : func->args() )
	{
		if ( code_gen_level >= 1 ) std::cout << " [ Lambda ]  in arg\n";
		Value *tmp = Builder.CreatePointerCast( &Arg , (Type::getInt64Ty(getGlobalContext()))->getPointerTo())  ;
		if ( code_gen_level >= 1 ) std::cout << " [ Lambda ]  in arg 2\n";
		Value * tmpPtr = Builder.CreateAlloca( Type::getInt64Ty(getGlobalContext())->getPointerTo() , 0 );
		if ( code_gen_level >= 1 ) std::cout << " [ Lambda ]  in arg 3\n";
		Builder.CreateStore( tmp , tmpPtr );
		if ( code_gen_level >= 1 ) std::cout << " [ Lambda ]  in arg 4\n";
		FunctionArgStart[LambdaLevel]=Builder.CreateLoad(tmpPtr);
	}

	/* Lambda Malloc */
	Builder.SetInsertPoint(Entry);
	Value * mallocSize = Builder.CreateLoad( SizeAddr );
	Instruction * var_malloc=CallInst::CreateMalloc(	Builder.GetInsertBlock(),
					Type::getInt64Ty(getGlobalContext()),
					Builder.getInt64Ty(),
					mallocSize, nullptr , nullptr , "_malloc");
	Builder.Insert(var_malloc);
	LambdaArgStart[LambdaLevel] = var_malloc ;

	assert(LambdaArgStart[LambdaLevel]->getType()==GetIntType()->getPointerTo()&&"nsknojj");

	if ( code_gen_level >= 1 ) std::cout << " [ Lambda ]  Insert Argument\n";
	/* Argument */
	Builder.SetInsertPoint(FunctionBB[LambdaLevel]);
	for(int i=0;i<varArgList.declList.size();i++)
		ArgValuesAccess(varArgList.declList[i]->varIdent->name,varArgList.declList[i]->typeCheck()->llvmTypeGen()->getPointerTo(),LambdaLevel);

	if ( code_gen_level >= 1 ) std::cout << " [ Lambda ]  Function CodeGen\n";
	/* Function */
	BasicBlock * myStmt= BasicBlock::Create(getGlobalContext() , "funcstmt" , func);
	if ( code_gen_level >= 1 ) std::cout << " [ Lambda ]  Function CodeGen CH0\n";
	Builder.SetInsertPoint( myStmt ) ;
	if ( code_gen_level >= 1 ) std::cout << " [ Lambda ]  Function CodeGen "<<stmtList.stmtList.size()<<endl;
	stmtList.codeGen();
	if ( code_gen_level >= 1 ) std::cout << " [ Lambda ]  Function CodeGen CH1\n";
	Value * retval = rtnExpr->codeGen();
	if ( code_gen_level >= 1 ) std::cout << " [ Lambda ]  Function CodeGen CH2\n";
	Value * retaddr = Builder.CreateAlloca(retval->getType());
	Builder.CreateStore(retval,retaddr);
	retaddr=Builder.CreatePtrToInt(retaddr,Type::getInt64Ty(getGlobalContext()));
	retaddr=Builder.CreateIntToPtr(retaddr,
					Type::getInt64Ty(getGlobalContext())
					->getPointerTo());
	if ( code_gen_level >= 1 ) std::cout << " [ Lambda ]  Function CodeGen CH3\n";
	retval = Builder.CreateLoad	(retaddr);
	Builder.CreateRet(retval);

	if ( code_gen_level >= 1 ) std::cout << " [ Lambda ]  Verify Function\n";

	Builder.SetInsertPoint( FunctionBB[LambdaLevel] ) ;
	Builder.CreateBr(myStmt);
	Builder.SetInsertPoint( OldBB ) ;
	Builder.CreateStore(ConstantInt::get(Type::getInt64Ty(getGlobalContext()),8*(LambdaArgCount[LambdaLevel]+1), true),SizeAddr);
	Builder.CreateBr(Entry);
	Builder.SetInsertPoint( Entry ) ;
	if ( code_gen_level >= 1 ) std::cout << " [ Lambda ]  Function Store CH1\n";
	Value * func_addr=CreatePtrAdd(LambdaArgStart[LambdaLevel],0,GetLambdaType()->getPointerTo()->getPointerTo());
	if ( code_gen_level >= 1 ) std::cout << " [ Lambda ]  Function Store CH2\n";

	Builder.CreateStore(func,func_addr);

	if ( code_gen_level >= 1 ) std::cout << " [ Lambda ]  Function Store CH3\n";

//	assert(NamedValues["x"]!=NULL);
	NamedValuesLevel=__NamedValuesLevel;
	NamedValues=__NamedValues;
	Builder.SetInsertPoint( Entry ) ;
//	assert(NamedValues["x"]==NULL);

	verifyFunction( *func ) ;
	//TheFPM->run(*func);
	if ( code_gen_level >= 1 ) std::cout << " [ Lambda ]  Finish\n";
	return LambdaArgStart[LambdaLevel--];
}

Value* LamdaAppExpr::codeGen() {
	if ( code_gen_level >= 1 ) std::cout << " [ Lambda ]  Create Call "<<tarIdent->name<<endl;

	NamedValuesAccess(tarIdent->name);
	if (   NamedValues[tarIdent->name] == 0 ) {
       		std::cout<<" [ Error ] No such Invoker."<<std::endl;
        	return NULL ;
    	}
	Value* addr= Builder.CreateLoad(NamedValues[tarIdent->name]);
	for(int i=0;i<fillList.fillList.size();i++)
   	 {
		Value *exp=fillList.fillList[i]->codeGen();
		Value *my_addr=CreatePtrAdd(addr,(i+1)*8,exp->getType()->getPointerTo());
		Builder.CreateStore(exp,my_addr);
	}
	Value* my_func=CreatePtrAdd(addr,0,GetLambdaType()->getPointerTo()->getPointerTo());
	my_func=Builder.CreateLoad(my_func);

	vector<Value*> _value_list_1;
	_value_list_1.clear();
	_value_list_1.push_back(addr);
	ArrayRef<Value*> _value_list_2 ( _value_list_1 ) ;
	assert(addr->getType()==GetIntType()->getPointerTo()&&"nsknojj");
	if ( code_gen_level >= 1 ) std::cout << " [ Lambda ]  Create Call Finish. "<<tarIdent->name<<endl;
	return Builder.CreateCall(my_func, _value_list_2);
}

TypeInfo* LamdaGenExpr::typeCheck()
{
	if ( exprType ) return exprType ;
	exprType = new InvokerType() ;
	if ( type_check_level >= 1 ) std::cout << " [ Type Check ] < LambdaExpr > LambdaGen Start"<<endl;
	map<string,TypeInfo*> __TypeNamedValues(TypeNamedValues);
	std::vector<class VarArg*>::iterator vit;
	if ( type_check_level >= 2 ) std::cout << " [ Type Check ] < LambdaExpr > VarArgList: "<<varArgList.declList.size()<<endl;
	for ( vit = varArgList.declList.begin() ;
	      vit != varArgList.declList.end() ; vit ++ ) {
		TypeNamedValues[(*vit)->varIdent->name] = (*vit)->typeCheck() ;
	}
	std::vector< class Stmt * >::iterator sit ;
	if ( type_check_level >= 2 ) std::cout << " [ Type Check ] < LambdaExpr> StmtList: "<<stmtList.stmtList.size()<<endl;
	for ( sit = stmtList.stmtList.begin() ;
	      sit != stmtList.stmtList.end() ; sit ++ ) {
		if ( ( (*sit)->typeCheck() ) == NULL ) return NULL ;
	}
	if ( (rtnExpr->typeCheck()) == NULL ) return NULL ;
	TypeNamedValues=__TypeNamedValues;
	if ( type_check_level >= 1 ) std::cout << " [ Type Check ] < LambdaExpr > LambdaGen Finish"<<endl;
	return exprType ;
}

TypeInfo* LamdaAppExpr::typeCheck()
{
	if (exprType) return exprType ;
	exprType = new IntType();
	if ( type_check_level >= 1 ) std::cout << " [ Type Check ] < LambdaExpr > LambdaApp Start"<<endl;
	tarIdent->typeCheck();
	std::vector<class Expr*>::iterator vit;
	for ( vit = fillList.fillList.begin() ;
	      vit != fillList.fillList.end() ; vit ++ )
			(*vit)->typeCheck();
	if ( type_check_level >= 1 ) std::cout << " [ Type Check ] < LambdaExpr > LambdaApp Finish"<<endl;
	return exprType	;
}

llvm::Type* InvokerType::llvmTypeGen()
{
	if ( tarType ) return tarType ;
	tarType = Type::getInt64Ty(getGlobalContext())->getPointerTo();
	return tarType ;
}
