TypeInfo* ObjNewExpr::typeCheck()
{
	if ( exprType ) return exprType;
	if ( TypeNamedClassDecls.count( tarIdent->name ) == 0 ) {
		cout<<"Error , class not defined"<<endl;
		return NULL ;
	}
	exprType = new ClassIdentType( tarIdent );
	return exprType ;
}

TypeInfo* GetLenExpr::tyepCheck()
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
	std::out <<"  [ Type Check ] \"SiOpExpr\" should not be type checked. " << std::endl ;
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
	stmtList.stmtList::iterator sit ;
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
	if ( tarExpr->typeCheck()->typeName != "Class" ) {
		cout<<"Error empty class"<<endl;
		return NULL ;
	}
	class ClassDecl * cls = TypeNamedClassDecls[((class ClassIdentType*)tarExpr->typeCheck())->classIdent->name] ;
	cls->typeCheck();
	exprType = cls->getMethodRtnType( mtdIdent->name ) ;
	return exprType ;
}

TypeInfo* IdentAccessExpr::typeCheck()
{
	if ( exprType ) return exprType ;
	if ( TypeNamedValues.count( tarIdent->name ) == 0 ) {
		cout<<"Error"<<endl;
		return NULL;
	}
	exprType = TypeNamedValues[ tarIdent->name ] ;
	return exprType ;
}

TypeInfo* VarDecl::typeCheck()
{
	if ( varType ) return varType;
	return NULL ;
}

TypeInfo* VarDeclStmt::typeCheck()
{
	TypeNamedValues[varIdent->name] = type ;
	return type ;
}

TypeInfo* ClassDecl::typeCheck()
{
	if ( classDeclType ) return classDeclType ;
	cout << " [ TypeCheck ] " << classIdent->name << endl ;
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
			fieldName2Pos[(*vit)->varIdent->name] = fieldDecl.size();
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
		fieldName2Pos[(*vit)->varIdent->name] = fieldDecl.size();
	}

	std::cout << " [ Type Check ] Class " << classIdent->name << " initialize the methods ."<< std::endl ;
	std::vector<class MtdDecl*>::iterator mit;
	for( mit = (mtdDeclList.declList).begin() ; mit !=(mtdDeclList.declList).end() ; mit++ ) {
		std::cout << " [ Type Check ] Add the method "<<(*mit)->mtdIdent->name<<" to Class "<<classIdent->name<<std::endl;
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

	// ABANDONED : getClassLLVMType();
	std::vector<class MtdDecl*>::iterator mit ;
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
	if ( varType ) return varType ;
	return NULL ;
}

TypeInfo* MtdDecl::typeCheck() {
	if ( mtdDeclType ) return mtdDeclType ;
	std::vector< class VarArg *>::iterator vit ;
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
	for ( cit = classDeclList.declList.begin() ; cit != classDeclList.declList.end() ; cit ++ ) {
		(*cit)->typeCheck();
 	}
	return NULL ;
}
