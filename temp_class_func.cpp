
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
