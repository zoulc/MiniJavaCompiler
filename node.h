#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include "llvm/IR/Value.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/ADT/ArrayRef.h"
#include "llvm/IR/Constant.h"
#include "llvm/IR/Argument.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/BasicBlock.h"

#include <map>
#include <queue>

using namespace std;
using namespace llvm;

class Ident;
class TypeInfo;
class Expr;
class Stmt;
class MtdDecl;
class ClassDecl;
class TemplateClassDecl;
class VarArg;
class VarDecl;
class StmtList ;
class ExprList ;
class MtdDeclList ;
class ClassDeclList ;
class VarArgList ;
class VarDeclList ;
class Program;
class MainClassDecl ;
class BiOpExpr;
class ItfaceDecl;
class ItfaceDeclList;
class AbsMtdDecl;
class AbsMtdDeclList;
class ImpItface ;
class ImpItfaceList ;
class ExtItface ;
class ExtItfaceList ;

enum GenerateStatus{ NoneStatus , TypingStatus , TypedStatus , GeningStatus , GenedStatus } ;

class Stmt {
public:
	virtual llvm::Value* codeGen();
	virtual TypeInfo* typeCheck();
	//virtual Stmt * deepCopy();
	TypeInfo* stmtType;
	Stmt(){ stmtType = NULL ;} 
	virtual Stmt* replaceCopy(map<string, string> &rule) ;
};

class Expr {
public:
	virtual llvm::Value* codeGen();
	virtual TypeInfo* typeCheck();
	//virtual Expr * deepCopy();
	TypeInfo* exprType;
	Expr(){ exprType = NULL ; } 
	virtual Expr* replaceCopy(map<string, string> &rule) ;
};

class StmtList {
public:
    std::vector<class Stmt *> stmtList;
    StmtList(){ /*stmtList.clear() ;*/ }
    StmtList( StmtList* _sL ,
              Stmt * _s )
    : stmtList(_sL->stmtList)
    {
        stmtList.push_back(_s);
    }
    StmtList( StmtList & _sL ) : stmtList(_sL.stmtList) {} ;
    StmtList( StmtList * _sL ) : stmtList(_sL->stmtList) {} ;
    virtual llvm::Value* codeGen();
	//virtual StmtList* deepCopy();
	virtual StmtList* replaceCopy(map<string, string> &rule);
} ;

class VarArg {
public:
    TypeInfo * varType ;
    Ident * varIdent ;
    VarArg( TypeInfo* _vT , Ident* _vI )
    : varType(_vT) , varIdent(_vI) { } ;
    llvm::Type* llvmType;
    llvm::Type* getLLVMType();
    virtual TypeInfo * typeCheck();
	virtual VarArg* deepCopy();
	virtual VarArg* replaceCopy(map<string, string> &rule);
};

class VarArgList {
public:
    std::vector< class VarArg * > declList ;
	bool __codeGen;
	ArrayRef<Type*> TypeArray;

	VarArgList(){};
    VarArgList( VarArgList* _vAL,VarArg* _vA)
    : declList(_vAL->declList)
    {
        declList.push_back(_vA);
    }
    VarArgList( VarArgList & _vAL ) : declList(_vAL.declList) {} ;
    VarArgList( VarArgList * _vAL ) : declList(_vAL->declList) {} ;

	ArrayRef<Type*>* getTypeArray(Type*);
	void codeGen(llvm::Type* ClassType);
	void setNamedValues();
	//virtual VarArg* deepCopy();
	virtual VarArgList* replaceCopy(map<string, string> &rule);
};

class VarDecl {
public:
    TypeInfo* varType ;
    Ident* varIdent ;
    VarDecl( TypeInfo* _vT , Ident* _vI )
    : varType(_vT) , varIdent(_vI) {} ;
	llvm::Type* llvmType;
    llvm::Type* getLLVMType();
    TypeInfo* typeCheck();
    virtual VarDecl* replaceCopy(map<string, string> &rule) ;
};

class VarDeclList {
public:
    std::vector< class VarDecl * > declList ;
    VarDeclList(){};
    VarDeclList( VarDeclList* _vDL ,
                   VarDecl* _vD )
    : declList(_vDL->declList)
    {
        declList.push_back(_vD);
    }
    VarDeclList( VarDeclList& _vDL ) : declList(_vDL.declList) {} ;
    VarDeclList( VarDeclList* _vDL ) : declList(_vDL->declList) {} ;
    virtual VarDeclList* replaceCopy(map<string, string> &rule) ;
};
class ImpItface
{
public:
	Ident* impIdent ;
	ImpItface( Ident* _iI ) : impIdent(_iI) {} ;
};

class ImpItfaceList
{
public:
	std::vector<ImpItface*> impList;
	ImpItfaceList(){ impList.clear(); }
	ImpItfaceList( ImpItfaceList & _iIL ) : impList(_iIL.impList) {}
	ImpItfaceList( ImpItfaceList * _iIL ) : impList(_iIL->impList) {}
	ImpItfaceList* AddImpItface( ImpItface * _iI )
	{
		impList.push_back( _iI ) ;
		return this ;
	}
};

class ExtItface
{
public:
	Ident* extIdent ;
	ExtItface( Ident* _eI ) : extIdent(_eI) {} ;
};

class ExtItfaceList
{
public:
	std::vector<ExtItface*> extList;
	ExtItfaceList(){ extList.clear(); }
	ExtItfaceList( ExtItfaceList & _eIL ) : extList(_eIL.extList) {}
	ExtItfaceList( ExtItfaceList * _eIL ) : extList(_eIL->extList) {}
	ExtItfaceList* AddExtItface( ExtItface * _eI )
	{
		extList.push_back( _eI ) ;
		return this ;
	}
};

class MtdDecl {
private:
    Function * func ;
public:
    Ident *mtdIdent ;
    ClassDecl* Owner;
	ClassDecl* formOwner ; 
    TypeInfo  *rtnType ;
    VarArgList varArgList ;
    StmtList    stmtList ;
    Expr    *rtnExpr ;
    MtdDecl( TypeInfo* _rT ,
             Ident* _mI ,
             VarArgList* _vAL ,
             StmtList* _sL ,
             Expr* _rE) :
    mtdIdent(_mI) , rtnType(_rT) ,
    varArgList(_vAL) ,
    stmtList(*_sL) , rtnExpr(_rE),mtdDeclType(NULL) {} ;
    llvm::FunctionType * func_type;
    llvm::Type * llvmType;
    llvm::Type * getFunctionType();
    Function * codeGen();
    Function * llvmFunc;
    Function * getFunction();
    bool isCreated;
    virtual TypeInfo* typeCheck();
    TypeInfo * mtdDeclType;
	/* Used for lambda */
	void ClearNamedValues();
    virtual MtdDecl* replaceCopy(map<string, string> &rule);
};

class AbsMtdDecl {
public:
	ItfaceDecl* Owner ;
    Ident * absMtdIdent ;
    TypeInfo  *rtnType ;
    VarArgList varArgList ;
	AbsMtdDecl( TypeInfo* _rT ,
             Ident* _mI ,
             VarArgList* _vAL) :
    absMtdIdent(_mI) , rtnType(_rT) ,
    varArgList(_vAL) {} ;
	virtual TypeInfo* typeCheck();
    TypeInfo * absMtdDeclType;
	virtual llvm::Value* codeGen();
	virtual llvm::Type* llvmTypeGen();
	//use Class Number to dynamic call the corresponding functions .
	bool isCodeGened ;
	llvm::Function* absMtdDynFunc;
	llvm::Type* llvmType ;
	virtual AbsMtdDecl* deepCopy();
};

class MtdDeclList {
public:
    std::vector< class MtdDecl *> declList ;
    MtdDeclList(){};
    MtdDeclList( MtdDeclList* _mDL ,
                   MtdDecl* _mD )
    : declList(_mDL->declList)
    {
        declList.push_back(_mD);
    }
    MtdDeclList( MtdDeclList * _mDL ) : declList(_mDL->declList) {} ;
    MtdDeclList( MtdDeclList & _mDL ) : declList(_mDL.declList) {} ;
    virtual MtdDeclList *replaceCopy(map<string, string> &rule) ;
};

class AbsMtdDeclList {
public:
    std::vector< class AbsMtdDecl *> declList ;
    AbsMtdDeclList(){};
    AbsMtdDeclList( AbsMtdDeclList* _aMDL ,
                   AbsMtdDecl* _aMD )
    : declList(_aMDL->declList)
    {
        declList.push_back(_aMD);
    }
    AbsMtdDeclList( AbsMtdDeclList * _aMDL ) : declList(_aMDL->declList) {} ;
    AbsMtdDeclList( AbsMtdDeclList & _aMDL ) : declList(_aMDL.declList) {} ;
};

class ArrNewExpr : public Expr {
public:
    Expr * sizeExpr ;
    ArrNewExpr( Expr * _sE )
    : sizeExpr(_sE) {} ;
    virtual ArrNewExpr* replaceCopy(map<string, string> &rule);
};

class BiOpExpr : public Expr{
public:
    Expr * leftExpr ;
    Expr * rightExpr ;
    BiOpExpr( Expr * _lE ,
              Expr * _rE )
    : leftExpr(_lE), rightExpr(_rE) {};
	virtual TypeInfo* typeCheck();
    virtual llvm::Value* codeGen();
    virtual BiOpExpr* replaceCopy(map<string, string> &rule);
};

class AddExpr : public BiOpExpr {
public:
    AddExpr ( Expr * lE ,
              Expr *  rE )
        :BiOpExpr( lE , rE ) {} ;
    virtual llvm::Value* codeGen();
    virtual BiOpExpr* replaceCopy(map<string, string> &rule);
};

class LessCmpExpr : public BiOpExpr {
public:
    LessCmpExpr ( Expr * lE ,
                  Expr *  rE )
        :BiOpExpr( lE , rE ) {} ;
    virtual llvm::Value* codeGen();
    virtual BiOpExpr* replaceCopy(map<string, string> &rule);
};

class GreaterCmpExpr : public BiOpExpr {
public:
    GreaterCmpExpr ( Expr * lE ,
                  Expr *  rE )
        :BiOpExpr( lE , rE ) {} ;
    virtual llvm::Value* codeGen();
    virtual BiOpExpr* replaceCopy(map<string, string> &rule);
};

class EqualCmpExpr : public BiOpExpr {
public:
    EqualCmpExpr ( Expr * lE ,
                  Expr *  rE )
        :BiOpExpr( lE , rE ) {} ;
    virtual llvm::Value* codeGen();
    virtual BiOpExpr* replaceCopy(map<string, string> &rule);
};

class NotEqualCmpExpr : public BiOpExpr {
public:
    NotEqualCmpExpr ( Expr * lE ,
                  Expr *  rE )
        :BiOpExpr( lE , rE ) {} ;
    virtual llvm::Value* codeGen();
    virtual BiOpExpr* replaceCopy(map<string, string> &rule);
};

class AndExpr : public BiOpExpr {
public:
    AndExpr ( Expr * lE ,
                  Expr *  rE )
        :BiOpExpr( lE , rE ) {};
    virtual llvm::Value* codeGen();
    virtual BiOpExpr* replaceCopy(map<string, string> &rule);
};

class SubExpr : public BiOpExpr {
public:
    SubExpr ( Expr * lE ,
                  Expr *  rE )
        :BiOpExpr( lE , rE ) {} ;
    virtual llvm::Value* codeGen();
    virtual BiOpExpr* replaceCopy(map<string, string> &rule);
};

class MultExpr : public BiOpExpr {
public:
    MultExpr ( Expr * lE ,
                  Expr *  rE )
        :BiOpExpr( lE , rE ){} ;
    virtual llvm::Value* codeGen();
    virtual BiOpExpr* replaceCopy(map<string, string> &rule);
};

class ArrAcsExpr : public BiOpExpr{
public:
    ArrAcsExpr ( Expr * lE ,
                  Expr *  rE )
        :BiOpExpr( lE , rE ){} ;
};

class ItfaceDecl {
public:
	GenerateStatus genStatus ;
	Ident * itfaceIdent ;
	ExtItfaceList extItfaceList ;
	AbsMtdDeclList absMtdDeclList ;
	ItfaceDecl( Ident * _iI ,
				ExtItfaceList * _eIL ,
				AbsMtdDeclList * _aMDL )
	: itfaceIdent(_iI) , extItfaceList(_eIL) , absMtdDeclList(_aMDL) {};
	TypeInfo * itfaceDeclType ;
	virtual TypeInfo* typeCheck();
	virtual llvm::Value* codeGen();
	TypeInfo * getAbsMethodRtnType( std::string absMtdName ) ;
	llvm::Value* getConcreMethod(std::string mtdName );
	std::vector<class AbsMtdDecl*> absMtdDecl;
	std::map<std::string,int> absMtdName2Pos ;

	std::vector< class ItfaceDecl* > extItfaces ;
	std::map<std::string,int> impCls2Pos ;
	std::vector< class ClassDecl* > impClasses ;
	void AddImpClass( ClassDecl * clsDecl ) ;
	bool isCodeGened ;
};

class ItfaceDeclList {
public:
	std::vector<class ItfaceDecl *> declList;
    ItfaceDeclList(){ declList.clear();};
    ItfaceDeclList( ItfaceDeclList* _iDL ,
                   ItfaceDecl* _iD )
    : declList(_iDL->declList)
    {
        declList.push_back(_iD);
    }
    ItfaceDeclList( ItfaceDeclList& _iDL ) : declList(_iDL.declList) {} ;
    ItfaceDeclList( ItfaceDeclList* _iDL ) : declList(_iDL->declList) {} ;
	void AddItfaceDecl( ItfaceDecl * _iD )
	{	declList.push_back(_iD);	}
};

class ClassDecl {
public:
	GenerateStatus genStatus ;
	long long classDeclNumber ;
    Ident * classIdent ;
    Ident * extClassIdent ;
	ImpItfaceList impItfaceList;
	VarDeclList varDeclList ;
    MtdDeclList mtdDeclList ;
	std::vector< ItfaceDecl* > impItfaces ;
    ClassDecl( Ident* _cI ,
               Ident* _eCI ,
			   ImpItfaceList* _iIL ,
			   VarDeclList* _vDL ,
               MtdDeclList* _mDL ):
    classIdent(_cI) , extClassIdent(_eCI) ,
	impItfaceList(_iIL) , varDeclList(_vDL) , mtdDeclList(_mDL) {};

	//Type Checking
	/*
	    0. prepare some basic information ( like NamedClassDecls etc )
		1. get Base Class and Exam whether it is type checked .
		2. Put all the methods and variables from the Base Class into this Class Declaration .
		3. Put its own fields and methods into the Base Class into this Class Declaration .
		4. Then do some more checkings in the newly added methods .
	*/
	// ABANDONED : ClassDecl * getBaseClass();
	ClassDecl * baseClass ;
	std::vector<class VarDecl*> fieldDecl;
	std::map<std::string , int>	fieldName2Pos;
	std::vector<class MtdDecl*> mtdDecl;
	std::map<std::string , int> mtdName2Pos;
	TypeInfo * typeCheck();
	TypeInfo * classDeclType;
	TypeInfo * getMethodRtnType( std::string mtdName ) ;

	/*
	The baisc Field of the ClassDecl:
	*/
	llvm::Type* getClassLLVMType() ;
	llvm::Type* classLLVMType;

	//Field
	void setNamedField(llvm::Value* thisClass );

	//Method
	int getMethodId(std::string mtdName);
	llvm::Type* getMethodType(std::string mtdName);

	//VTable
	llvm::Type* vtableType;
	llvm::Type* getVTableType();
	llvm::Value* vtableLoc;
	llvm::Value* getVTableLoc();

	//codeGen
	llvm::Value* codeGen();

	//virtual ClassDecl* deepCopy();
	virtual ClassDecl *replaceCopy(map<string, string> &rule);
};

class ClassDeclList {
public:
    std::vector<class ClassDecl *> declList;
    ClassDeclList(){ declList.clear();};
    ClassDeclList( ClassDeclList* _cDL ,
                   ClassDecl* _cD )
    : declList(_cDL->declList)
    {
        declList.push_back(_cD);
    }
    ClassDeclList( ClassDeclList& _cDL ) : declList(_cDL.declList) {} ;
    ClassDeclList( ClassDeclList* _cDL ) : declList(_cDL->declList) {} ;
	void AddClassDecl( ClassDecl * _cD )
	{	declList.push_back(_cD);	}
} ;

class ExprList {
public:
    std::vector<class Expr *> fillList;
    ExprList(){};
    ExprList( ExprList* _eL ,
                   Expr* _e )
    : fillList(_eL->fillList)
    {
        fillList.push_back(_e);
    }
    ExprList( ExprList * _eL ) : fillList(_eL->fillList) {} ;
    ExprList( ExprList & _eL ) : fillList(_eL.fillList) {} ;
    virtual ExprList* replaceCopy(map<string, string> &rule);
} ;

class GetLenExpr : public Expr{
public:
    Expr * tarExpr ;
    GetLenExpr( Expr * _tE )
    : tarExpr(_tE) {} ;
	virtual TypeInfo* typeCheck();
	virtual GetLenExpr* replaceCopy(map<string, string> &rule);
};

class GetMtdCallExpr : public Expr{
public:
    Expr *tarExpr ;
    Ident *mtdIdent ;
    ExprList fillList ;
	bool isClass ;
	ClassDecl* tarClassDecl ;
	ItfaceDecl* tarItfaceDecl ;
    GetMtdCallExpr( Expr * _tE ,
                    Ident * _mI ,
                    ExprList * _fL )
    : tarExpr(_tE) , mtdIdent(_mI) , fillList(_fL) {}  ;
    virtual llvm::Value* codeGen();
    virtual TypeInfo* typeCheck();
    virtual GetMtdCallExpr* replaceCopy(map<string, string> &rule);
};

class IdentAccessExpr : public Expr {
public:
    Ident * tarIdent ;
    IdentAccessExpr( Ident * _tI )
    : tarIdent(_tI) {} ;
    virtual llvm::Value* codeGen();
    virtual TypeInfo* typeCheck();
    virtual IdentAccessExpr* replaceCopy(map<string, string> &rule);
};

class Ident {
public:
    std::string name ;
	std::string identCate ;
    Ident(){};
    Ident( std::string & _n , std::string _iC = "Undefined") : name(_n) , identCate(_iC) {} ;
	TypeInfo* identType ;
	virtual llvm::Value* codeGen();
	virtual TypeInfo* typeCheck();
	virtual Ident* deepCopy();
	virtual Ident* replaceCopy(map<string, string> &rule);

	// Only for TypeUseIdent
	virtual bool isItfaceTypeIdent();
	virtual bool isClassTypeIdent();
	virtual ItfaceDecl* getCorItfaceDecl();
	virtual ClassDecl*  getCorClassDecl();

	// Only for VarUseIdent
	virtual bool isVarUseIdent();
	virtual TypeInfo* getVarUseIdentType();
};

class ItfaceDeclIdent : public Ident {
public:
	ItfaceDeclIdent( std::string & _n)
	: Ident( _n , "ItfaceDecl" ) {} ;
	virtual Ident* deepCopy();
};

class ClassDeclIdent : public Ident {
public:
	ClassDeclIdent( std::string & _n)
	: Ident(_n , "ClassDecl") {} ;
	virtual Ident* deepCopy();
};

class VarDeclIdent : public Ident {
public:
	VarDeclIdent( std::string & _n)
	: Ident(_n , "VarDecl") {} ;
	virtual Ident* deepCopy();
};

class ArgDeclIdent : public Ident {
public:
	ArgDeclIdent( std::string & _n)
	: Ident(_n , "ArgDecl") {} ;
	virtual Ident* deepCopy();
};

class MtdDeclIdent : public Ident {
public:
	MtdDeclIdent( std::string & _n)
	: Ident(_n , "MtdDecl") {} ;
	virtual Ident* deepCopy();
};

class VarUseIdent : public Ident{
public:
	VarUseIdent( std::string & _n)
	: Ident(_n , "VarUse") {} ;
	virtual TypeInfo* typeCheck();
	virtual Ident* deepCopy();
	virtual bool isVarUseIdent();
	virtual TypeInfo* getVarUseIdentType();
	TypeInfo* corVarType ;
};

class MtdUseIdent : public Ident{
public:
	MtdUseIdent( std::string & _n)
	: Ident(_n , "MtdUse") {} ;
	virtual Ident* deepCopy();
};

class TypeUseIdent : public Ident{
public:
	TypeUseIdent( std::string & _n)
	: Ident(_n , "TypeUse") {} ;
	bool isClass ;
	ClassDecl*  corClassDecl ;
	ItfaceDecl* corItfaceDecl ;
	virtual bool isItfaceTypeIdent();
	virtual bool isClassTypeIdent();
	virtual ItfaceDecl* getCorItfaceDecl();
	virtual ClassDecl*  getCorClassDecl();
	virtual TypeInfo* typeCheck();
	virtual Ident* deepCopy();
};

class IntLiterExpr : public Expr {
public:
    long long int value;
    IntLiterExpr( long long int _v )
    : value(_v) {} ;
    virtual llvm::Value* codeGen();
	virtual TypeInfo* typeCheck();
    virtual IntLiterExpr* replaceCopy(map<string, string> &rule);
};

class TrueLiterExpr : public Expr {
public:
    bool value ;
    TrueLiterExpr()
    : value(true) {} ;
    virtual llvm::Value* codeGen();
	virtual TypeInfo* typeCheck();
	virtual TrueLiterExpr* replaceCopy(map<string, string> &rule);
};

class FalseLiterExpr : public Expr {
public:
    bool value ;
    FalseLiterExpr()
    : value(false) {} ;
    virtual llvm::Value* codeGen();
	virtual TypeInfo* typeCheck();
	virtual FalseLiterExpr* replaceCopy(map<string, string> &rule);
};

class MainClassDecl {
public:
    Ident *mainClassName;
    Ident *inputArgs;
    StmtList stmtList ;
    MainClassDecl( Ident * _mCN , Ident * _iA , StmtList * _sL )
    : mainClassName(_mCN) ,  inputArgs(_iA) , stmtList(_sL), mainClassDeclType(NULL) {};

	virtual TypeInfo* typeCheck();
	TypeInfo * mainClassDeclType ;
    virtual Value *codeGen();
};

class ObjNewExpr : public Expr {
public:
    Ident * tarIdent ;
    ObjNewExpr( Ident * _tI )
    : tarIdent(_tI) {} ;
    virtual llvm::Value* codeGen();
    virtual TypeInfo* typeCheck();
    virtual ObjNewExpr* replaceCopy(map<string, string> &rule);
};

class TemplateObjNewExpr : public ObjNewExpr {
public:
	string instanceClassName;
	vector<string> parameters;
	TemplateObjNewExpr( Ident *_tI, string tparam)
	: ObjNewExpr(_tI) {
		parameters.clear();
		parameters.push_back(tparam);
		instanceClassName = tarIdent->name;
		for (unsigned i = 0; i < parameters.size(); ++i)
			instanceClassName += "#" + parameters[i];
	}
	virtual TypeInfo* typeCheck();
	TemplateObjNewExpr* replaceCopy(map<string, string> &rule);
};

class Program {
public:
    MainClassDecl * mainClassDecl ;
    ClassDeclList classDeclList ;
	ItfaceDeclList itfaceDeclList ;
    Program( MainClassDecl* _mC , ClassDeclList *_cD ,
			ItfaceDeclList* _iDL )
    : mainClassDecl(_mC) , classDeclList(_cD) , itfaceDeclList(_iDL) {};
	Program( MainClassDecl* _mC )
	: mainClassDecl(_mC) , classDeclList() , itfaceDeclList() {};
	Program * AddClassDecl( ClassDecl * _cD )
	{
		classDeclList.AddClassDecl(_cD);
		return this ;
	};
	Program * AddItfaceDecl( ItfaceDecl * _iD )
	{
		itfaceDeclList.AddItfaceDecl(_iD);
		return this ;
	};
	virtual Value *codeGen();
    void ClassInitial();
    virtual TypeInfo* typeCheck();
};

class SiOpExpr : public Expr{
public:
    Expr * tarExpr ;
    SiOpExpr( Expr * _tE )
    : tarExpr ( _tE)  {};
    virtual llvm::Value* codeGen();
	virtual TypeInfo* typeCheck();
	virtual SiOpExpr* replaceCopy(map<string, string> &rule);
};

class NegExpr : public SiOpExpr {
public:
    NegExpr ( Expr * _tE )
    : SiOpExpr( _tE) {} ;
    virtual llvm::Value* codeGen();
	virtual TypeInfo* typeCheck();
	virtual NegExpr* replaceCopy(map<string, string> &rule);
};

class ParenExpr : public SiOpExpr {
public:
    ParenExpr ( Expr * _tE)
    : SiOpExpr( _tE ) {} ;
    virtual llvm::Value* codeGen();
	virtual TypeInfo* typeCheck();
	virtual ParenExpr* replaceCopy(map<string, string> &rule);
};

class BlockStmt : public Stmt{
public:
    StmtList stmtList ;
    BlockStmt() {} ;
    BlockStmt( StmtList *_sL )
    : stmtList(_sL) {} ;
    virtual llvm::Value* codeGen();
	virtual TypeInfo* typeCheck();
	virtual BlockStmt* replaceCopy(map<string, string> &rule);
};

class IfThenElseStmt : public Stmt {
public:
    Expr* condExpr ;
    Stmt* thenStmt ,*elseStmt ;
    IfThenElseStmt( Expr * _cE ,
                    Stmt * _tS ,
                    Stmt * _eS )
    : condExpr(_cE) , thenStmt(_tS) , elseStmt(_eS) {};
    virtual llvm::Value* codeGen();
	virtual TypeInfo* typeCheck();
	virtual IfThenElseStmt* replaceCopy(map<string, string> &rule);
};

class WhileStmt : public Stmt {
public:
    Expr* condExpr ;
    Stmt* bodyStmt ;
    WhileStmt( Expr * _cE , Stmt * _bS )
    : condExpr(_cE) , bodyStmt(_bS) {} ;
    virtual llvm::Value* codeGen();
	virtual TypeInfo* typeCheck();
	virtual WhileStmt* replaceCopy(map<string, string> &rule);
};

class SysOutPrtStmt : public Stmt {
public :
    Expr * prtExpr ;
    SysOutPrtStmt( Expr * _pE )
    : prtExpr(_pE) {} ;
	virtual TypeInfo* typeCheck();
    virtual llvm::Value* codeGen();
    virtual SysOutPrtStmt* replaceCopy(map<string, string> &rule);
};

class SysOutPrtCharStmt : public Stmt {
public :
    Expr * prtExpr ;
    SysOutPrtCharStmt( Expr * _pE )
    : prtExpr(_pE) {} ;
	virtual TypeInfo* typeCheck();
    virtual llvm::Value* codeGen();
    virtual SysOutPrtCharStmt* replaceCopy(map<string, string> &rule);
};

class SysInReadExpr : public Expr {
public :
    SysInReadExpr( ) {} ;
    virtual llvm::Value* codeGen();
    SysInReadExpr* replaceCopy(map<string, string> &rule);
};

class SysInReadCharExpr : public Expr {
public :
    SysInReadCharExpr( ) {} ;
    virtual llvm::Value* codeGen();
    SysInReadCharExpr* replaceCopy(map<string, string> &rule);
};

class AssignStmt : public Stmt {
public :
    Ident * assignIdent ;
    Expr *     valueExpr ;
    AssignStmt( Ident * _aI ,
                Expr * _vE )
    : assignIdent(_aI) , valueExpr(_vE) {};
    virtual llvm::Value* codeGen();
	virtual TypeInfo* typeCheck();
    virtual AssignStmt* replaceCopy(map<string, string> &rule);
};

class ArrAssignStmt : public Stmt {
public:
    Ident * arrIdent ;
    Expr *     valueExpr ;
    Expr *     addressExpr ;
    ArrAssignStmt( Ident * _aI ,
                   Expr * _aE ,
                   Expr * _vE )
    : arrIdent(_aI) , valueExpr(_aE) ,
    addressExpr(_vE) {} ;
	//virtual TypeInfo* typeCheck();
	virtual ArrAssignStmt* replaceCopy(map<string, string> &rule);
};

class VarDeclStmt : public Stmt {
public:
    TypeInfo * type ;
    Ident * varIdent ;
    VarDeclStmt( TypeInfo* _t , Ident* _i ) : type(_t) , varIdent(_i) {} ;
    virtual llvm::Value* codeGen();
	virtual TypeInfo* typeCheck();
	virtual VarDeclStmt* replaceCopy(map<string, string> &rule);
};

class ThisExpr : public Expr {
public:
    ThisExpr() {} ;
};

class TypeInfo {
public:
    std::string typeName ;
    llvm::Type* tarType ;
	long long classNo ;
    TypeInfo(){};
    TypeInfo( std::string _tN ) : typeName(_tN) , classNo(0) { tarType = NULL ; } ;
    TypeInfo( TypeInfo * _t ) : typeName(_t->typeName) , classNo(_t->classNo){} ;
	TypeInfo( TypeInfo & _t ) : typeName(_t.typeName) , classNo(_t.classNo){} ;
    virtual llvm::Type* llvmTypeGen();
	int operator == ( TypeInfo * _type ) {
		return ( ( _type->typeName ) == typeName ) ;
	}
	int operator == ( std::string _typeName ) {
		return ( typeName == _typeName ) ;
	}
	virtual TypeInfo* typeCheck();
	bool isTypeChecked ;
	virtual TypeInfo* deepCopy();
	virtual TypeInfo* replaceCopy(map<string, string> &rule);
	virtual bool isUsrDefIdentType();
};

class IntType : public TypeInfo {
public:
    IntType() : TypeInfo("int") {} ;
    virtual llvm::Type* llvmTypeGen();
    virtual TypeInfo* replaceCopy(map<string, string> &rule);
};

class ArrType : public TypeInfo {
public:
    TypeInfo* elemType ;
    ArrType( TypeInfo* _e )
    : TypeInfo("Arr") , elemType(_e){} ;
};

class BoolType : public TypeInfo {
public:
    BoolType() : TypeInfo("boolean") { } ;
    virtual llvm::Type* llvmTypeGen();
    virtual TypeInfo* replaceCopy(map<string, string> &rule);
};

class VoidType : public TypeInfo {
public:
    VoidType() : TypeInfo("Void") {} ;
};

class ClassType : public TypeInfo {
public:
	Ident * tarIdent ;
	ClassDecl* tarClassDecl ;
	ClassType( Ident * _tI , ClassDecl* _tCD )
	: TypeInfo("Class") , tarIdent(_tI) , tarClassDecl(_tCD) {} ;
	virtual llvm::Type* llvmTypeGen();
	virtual TypeInfo* deepCopy();
	virtual TypeInfo* replaceCopy(map<string, string> &rule);
};

class ItfaceType : public TypeInfo {
public:
	Ident * tarIdent ;
	ItfaceDecl* tarItfaceDecl ;
	ItfaceType( Ident * _tI , ItfaceDecl* _tID )
	: TypeInfo("Itface") , tarIdent(_tI) , tarItfaceDecl(_tID) {} ;
	virtual llvm::Type* llvmTypeGen();
	virtual TypeInfo* deepCopy();
	virtual TypeInfo* replaceCopy(map<string, string> &rule);
};

class UsrDefIdentType : public TypeInfo {
public:
    Ident * tarIdent ;
	TypeInfo* concreType ;

    UsrDefIdentType(Ident *_cI )
    : TypeInfo("ClassOrItface") , tarIdent(_cI) {} ;
    virtual llvm::Type* llvmTypeGen();
	virtual TypeInfo* typeCheck();
	virtual TypeInfo* deepCopy();
	virtual TypeInfo* replaceCopy(map<string, string> &rule);

	virtual bool isUsrDefIdentType();
	bool isItfaceType();
	bool isClassType();
	ItfaceDecl* getItfaceDecl();
 	ClassDecl* getClassDecl();
	TypeInfo* getConcreType();
};

class TemplateUsrDefIdentType : public UsrDefIdentType {
public:
    vector<string> parameters;
    string instanceClassName;

    TemplateUsrDefIdentType(Ident *_cI, string _t)
    : UsrDefIdentType(_cI) {
	parameters.clear();
	parameters.push_back(_t);
	instanceClassName = tarIdent->name;
	for (unsigned i = 0; i < parameters.size(); ++i)
		instanceClassName += "#" + parameters[i];
    }
    virtual TypeInfo* typeCheck();
    virtual TypeInfo* replaceCopy(map<string, string> &rule);
};

class InvokerType : public TypeInfo {
public:
	InvokerType()
	: TypeInfo("Invoker") {} ;
    virtual TypeInfo* replaceCopy(map<string, string> &rule);
    virtual llvm::Type* llvmTypeGen();
};

class NullType : public TypeInfo {
public:
	NullType() : TypeInfo("NullType") {} ;
};

class InsOfExpr : public Expr {
public:
	Expr* tarExpr ;
	TypeInfo* srcType ;
	InsOfExpr( Expr* _tE , TypeInfo* _sT)
	: tarExpr(_tE) , srcType(_sT) {} ;
	virtual llvm::Value* codeGen();
	virtual TypeInfo* typeCheck();
	virtual InsOfExpr* replaceCopy(map<string, string> &rule);
};

class TemplateClassDecl : public ClassDecl {
public:
	vector<string> prototypes;
	TemplateClassDecl(Ident *_cI,
			string tparam,
			Ident *_eCI,
			ImpItfaceList* _iIL,
			VarDeclList *_vDL,
			MtdDeclList *_mDL ):
	ClassDecl(_cI, _eCI, _iIL, _vDL, _mDL) {
		prototypes.push_back(tparam);
	}
	ClassDecl *replaceCopy(vector<string> parameters);
};

/*  Used for lambda  */


void NamedValuesAccess(std::string);

Value* CreatePtrAdd(Value*,int,Type*);

FunctionType* GetLambdaType();

void ArgValuesAccess(std::string,Type*,int);

class LamdaGenExpr : public Expr {
public :
	VarArgList varArgList ;
	StmtList    stmtList ;
	Expr    *rtnExpr ;
	LamdaGenExpr( VarArgList* _vAL ,
			 StmtList* _sL ,
			 Expr* _rE) :
	varArgList(_vAL) ,
	stmtList(*_sL) , rtnExpr(_rE) {} ;
	virtual TypeInfo* typeCheck();
	virtual llvm::Value* codeGen();
	virtual LamdaGenExpr *replaceCopy(map<string, string> &rule);
};

class LamdaAppExpr : public Expr {
public :
	Ident *tarIdent ;
	ExprList fillList ;
	LamdaAppExpr( Ident * _tI ,
				  ExprList * _fL )
	: tarIdent(_tI) , fillList(_fL) { exprType = NULL ; }  ;
	virtual llvm::Value* codeGen();
	virtual TypeInfo* typeCheck();
	virtual LamdaAppExpr* replaceCopy(map<string, string> &rule);
};
/*  Used for lambda  */
