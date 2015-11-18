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

using namespace llvm;

class Ident;
class TypeInfo;
class Expr;
class Stmt;
class MtdDecl;
class ClassDecl;
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

class Stmt {
public:
	virtual llvm::Value* codeGen();
	virtual TypeInfo* typeCheck();
	TypeInfo* stmtType;
};

class Expr {
public:
	virtual llvm::Value* codeGen();
	virtual TypeInfo* typeCheck();
	TypeInfo* exprType;
};

class StmtList {
public:
    std::vector<class Stmt *> stmtList;
    StmtList(){}
    StmtList( StmtList* _sL ,
              Stmt * _s )
    : stmtList(_sL->stmtList)
    {
        stmtList.push_back(_s);
    }
    StmtList( StmtList & _sL ) : stmtList(_sL.stmtList) {} ;
    StmtList( StmtList * _sL ) : stmtList(_sL->stmtList) {} ;
    virtual llvm::Value* codeGen();
} ;

class VarArg {
public:
    TypeInfo * varType ;
    Ident * varIdent ;
    VarArg( TypeInfo* _vT , Ident* _vI )
    : varType(_vT) , varIdent(_vI) {} ;
    llvm::Type* llvmType;
    llvm::Type* getLLVMType();
    virtual TypeInfo * typeCheck();
};

class VarArgList {
public:
    std::vector< class VarArg * > declList ;
	bool __codeGen;
	ArrayRef<Type*> TypeArray; 
	
	VarArgList(){};
    VarArgList( VarArgList* _vAL ,
                   VarArg* _vA )
    : declList(_vAL->declList)
    {
        declList.push_back(_vA);
    }
    VarArgList( VarArgList & _vAL ) : declList(_vAL.declList) {} ; 
    VarArgList( VarArgList * _vAL ) : declList(_vAL->declList) {} ; 

	ArrayRef<Type*>* getTypeArray(Type*);
	void codeGen(llvm::Type* ClassType);
	void setNamedValues();
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
};

class MtdDecl {
private:
    Function * func ; 
public:
    Ident *mtdIdent ;
    ClassDecl* Owner;
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
    stmtList(*_sL) , rtnExpr(_rE) {} ; 
    llvm::Type * llvmType; 
    llvm::Type * getFunctionType();
    Function * codeGen();
    Function * llvmFunc;
    Function * getFunction();
    bool isCreated;
    virtual TypeInfo* typeCheck();
    TypeInfo * mtdDeclType;
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
};

class ArrNewExpr : public Expr {
public:
    Expr * sizeExpr ;
    ArrNewExpr( Expr * _sE )
    : sizeExpr(_sE) {} ;
};

class BiOpExpr : public Expr{
public:
    Expr * leftExpr ;
    Expr * rightExpr ;
    BiOpExpr( Expr * _lE ,
              Expr * _rE )
    : leftExpr(_lE), rightExpr(_rE) {};
    virtual llvm::Value* codeGen();
};

class AddExpr : public BiOpExpr {
public:
    AddExpr ( Expr * lE ,
              Expr *  rE )
        :BiOpExpr( lE , rE ) {} ;
    virtual llvm::Value* codeGen();
};

class LessCmpExpr : public BiOpExpr {
public:
    LessCmpExpr ( Expr * lE ,
                  Expr *  rE )
        :BiOpExpr( lE , rE ) {} ;
    virtual llvm::Value* codeGen();
};

class AndExpr : public BiOpExpr {
public:
    AndExpr ( Expr * lE ,
                  Expr *  rE )
        :BiOpExpr( lE , rE ) {};
    virtual llvm::Value* codeGen();
};

class SubExpr : public BiOpExpr {
public:
    SubExpr ( Expr * lE ,
                  Expr *  rE )
        :BiOpExpr( lE , rE ) {} ;
    virtual llvm::Value* codeGen();
};

class MultExpr : public BiOpExpr {
public:
    MultExpr ( Expr * lE ,
                  Expr *  rE )
        :BiOpExpr( lE , rE ){} ;
    virtual llvm::Value* codeGen();
};

class ArrAcsExpr : public BiOpExpr{
public:
    ArrAcsExpr ( Expr * lE ,
                  Expr *  rE )
        :BiOpExpr( lE , rE ){} ;
};

class ClassDecl {
public:
    Ident * classIdent ;
    Ident * extClassIdent ;
    VarDeclList varDeclList ;
    MtdDeclList mtdDeclList ;
    ClassDecl( Ident* _cI ,
               Ident* _eCI ,
               VarDeclList* _vDL ,
               MtdDeclList* _mDL ):
    classIdent(_cI) , extClassIdent(_eCI) ,
    varDeclList(_vDL) , mtdDeclList(_mDL) {};

	/*
	The baisc Field of the ClassDecl:
	*/
	llvm::Type* getClassLLVMType() ;
	llvm::Type* classLLVMType;

	//Field
	std::vector<class VarDecl*> fieldDecl;
	std::map<std::string , int>	fieldName2Pos;
	void setNamedField(llvm::Value* thisClass );

	//Method
	std::vector<class MtdDecl*> mtdDecl;
	std::map<std::string , int> mtdName2Pos;
	int getMethodId(std::string mtdName);
	llvm::Type* getMethodType(std::string mtdName);

	//Base Class.
	ClassDecl * baseClass ;
    ClassDecl * getBaseClass();
    
	//VTable
	llvm::Type* vtableType;
	llvm::Type* getVTableType();
	llvm::Value* vtableLoc;
	llvm::Value* getVTableLoc();

	//codeGen
	llvm::Value* codeGen();

   	//Type Checking 
	TypeInfo * typeCheck();
	TypeInfo * classDeclType;
	TypeInfo * getMethodRtnType( std::string mtdName ) ;

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
} ;

class GetLenExpr : public Expr{
public:
    Expr * tarExpr ;
    GetLenExpr( Expr * _tE )
    : tarExpr(_tE) {} ;
};

class GetMtdCallExpr : public Expr{
public:
    Expr *tarExpr ;
    Ident *mtdIdent ;
    ExprList fillList ;
    GetMtdCallExpr( Expr * _tE ,
                    Ident * _mI ,
                    ExprList * _fL )
    : tarExpr(_tE) , mtdIdent(_mI) , fillList(_fL) {}  ; 
    virtual llvm::Value* codeGen();
    virtual TypeInfo* typeCheck();
};

class IdentAccessExpr : public Expr {
public:
    Ident * tarIdent ;
    IdentAccessExpr( Ident * _tI )
    : tarIdent(_tI) {} ;
    virtual llvm::Value* codeGen();
    virtual TypeInfo* typeCheck();
};

class Ident {
public:
    std::string name ;
    Ident(){};
    Ident( std::string & _n ) : name(_n) {} ;
    virtual llvm::Value* codeGen();
};

class IntLiterExpr : public Expr {
public:
    long long int value;
    IntLiterExpr( long long int _v )
    : value(_v) {} ;
    virtual llvm::Value* codeGen();
};

class TrueLiterExpr : public Expr {
public:
    bool value ;
    TrueLiterExpr()
    : value(true) {} ;
    virtual llvm::Value* codeGen();
};

class FalseLiterExpr : public Expr {
public:
    bool value ;
    FalseLiterExpr()
    : value(false) {} ;
    virtual llvm::Value* codeGen();
};

class MainClassDecl {
public:
    Ident *mainClassName;
    Ident *inputArgs;
    StmtList stmtList ;
    MainClassDecl( Ident * _mCN , Ident * _iA , StmtList * _sL )
    : mainClassName(_mCN) ,  inputArgs(_iA) , stmtList(_sL) {};

    virtual Value *codeGen();
};

class ObjNewExpr : public Expr {
public:
    Ident * tarIdent ;
    ObjNewExpr( Ident * _tI )
    : tarIdent(_tI) {} ;
    virtual llvm::Value* codeGen();
    virtual TypeInfo* typeCheck();
};

class Program {
public:
    MainClassDecl * mainClassDecl ;
    ClassDeclList classDeclList ;
    Program( MainClassDecl* _mC , ClassDeclList *_cD )
    : mainClassDecl(_mC) , classDeclList(_cD) {};
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
};

class NegExpr : public SiOpExpr {
public:
    NegExpr ( Expr * _tE )
    : SiOpExpr( _tE) {} ;
    virtual llvm::Value* codeGen();
};

class ParenExpr : public SiOpExpr {
public:
    ParenExpr ( Expr * _tE)
    : SiOpExpr( _tE ) {} ;
    virtual llvm::Value* codeGen();
};

class BlockStmt : public Stmt{
public:
    StmtList stmtList ;
    BlockStmt( StmtList *_sL )
    : stmtList(_sL) {} ;
    virtual llvm::Value* codeGen();
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
};

class WhileStmt : public Stmt {
public:
    Expr* condExpr ;
    Stmt* bodyStmt ;
    WhileStmt( Expr * _cE , Stmt * _bS )
    : condExpr(_cE) , bodyStmt(_bS) {} ;
    virtual llvm::Value* codeGen();
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
    virtual llvm::Value* codeGen();
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
};

class VarDeclStmt : public Stmt {
public:
    TypeInfo * type ;
    Ident * varIdent ;
    VarDeclStmt( TypeInfo* _t , Ident* _i ) : type(_t) , varIdent(_i) {} ;
    virtual llvm::Value* codeGen();
};

class ThisExpr : public Expr {
public:
    ThisExpr() {} ;
};

class TypeInfo {
public:
    std::string typeName ;
    llvm::Type* tarType ;
    TypeInfo(){};
    TypeInfo( std::string _tN ) : typeName(_tN) {} ;
    TypeInfo( TypeInfo * _t ) : typeName(_t->typeName) {} ;
    virtual llvm::Type* llvmTypeGen();  
};

class IntType : public TypeInfo {
public:
    IntType() : TypeInfo("int") {} ;
    virtual llvm::Type* llvmTypeGen();
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
};

class VoidType : public TypeInfo {
public:
    VoidType() : TypeInfo("Void") {} ; 
};

class ClassIdentType : public TypeInfo {
public:
    Ident * classIdent ;
    
    ClassIdentType(Ident *_cI )
    : TypeInfo("Class") , classIdent(_cI) {} ;
    virtual llvm::Type* llvmTypeGen();
};
