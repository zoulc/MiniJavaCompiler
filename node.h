#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

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
};

class Expr {
public:
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
} ;

class VarArg {
public:
    TypeInfo * varType ;
    Ident * varIdent ;
    VarArg( TypeInfo* _vT , Ident* _vI )
    : varType(_vT) , varIdent(_vI) {} ;
};

class VarArgList {
public:
    std::vector< class VarArg * > declList ;
    VarArgList(){};
    VarArgList( VarArgList* _vAL ,
                   VarArg* _vA )
    : declList(_vAL->declList)
    {
        declList.push_back(_vA);
    }
    VarArgList( VarArgList & _vAL ) : declList(_vAL.declList) {} ;
    VarArgList( VarArgList * _vAL ) : declList(_vAL->declList) {} ;
};

class VarDecl {
public:
    TypeInfo* varType ;
    Ident* varIdent ;
    VarDecl( TypeInfo* _vT , Ident* _vI )
    : varType(_vT) , varIdent(_vI) {} ;
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
public:
    Ident *mtdIdent ;
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
};

class AddExpr : public BiOpExpr {
public:
    AddExpr ( Expr * lE ,
              Expr *  rE )
        :BiOpExpr( lE , rE ) {} ;
};

class LessCmpExpr : public BiOpExpr {
public:
    LessCmpExpr ( Expr * lE ,
                  Expr *  rE )
        :BiOpExpr( lE , rE ) {} ;
};

class AndExpr : public BiOpExpr {
public:
    AndExpr ( Expr * lE ,
                  Expr *  rE )
        :BiOpExpr( lE , rE ) {};
};

class SubExpr : public BiOpExpr {
public:
    SubExpr ( Expr * lE ,
                  Expr *  rE )
        :BiOpExpr( lE , rE ) {} ;
};

class MultExpr : public BiOpExpr {
public:
    MultExpr ( Expr * lE ,
                  Expr *  rE )
        :BiOpExpr( lE , rE ){} ;
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
};

class ClassDeclList {
public:
    std::vector<class ClassDecl *> declList;
    ClassDeclList(){};
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
};

class IdentAccessExpr : public Expr {
public:
    Ident * tarIdent ;
    IdentAccessExpr( Ident * _tI )
    : tarIdent(_tI) {} ;
};

class Ident {
public:
    std::string name ;
    Ident(){};
    Ident( std::string & _n ) : name(_n) {} ;
};

class IntLiterExpr : public Expr {
public:
    long long int value;
    IntLiterExpr( long long int _v )
    : value(_v) {} ;
};

class TrueLiterExpr : public Expr {
public:
    bool value ;
    TrueLiterExpr()
    : value(true) {} ;
};

class FalseLiterExpr : public Expr {
public:
    bool value ;
    FalseLiterExpr()
    : value(false) {} ;
};

class MainClassDecl {
public:
    Ident *mainClassName;
    Ident *inputArgs;
    StmtList stmtList ;
    MainClassDecl( Ident * _mCN , Ident * _iA , StmtList * _sL )
    : mainClassName(_mCN) ,  inputArgs(_iA) , stmtList(_sL) {};
};

class ObjNewExpr : public Expr {
public:
    Ident * tarIdent ;
    ObjNewExpr( Ident * _tI )
    : tarIdent(_tI) {} ;
};

class Program {
public:
    MainClassDecl * mainClassDecl ;
    ClassDeclList classDeclList ;
    Program( MainClassDecl* _mC , ClassDeclList *_cD )
    : mainClassDecl(_mC) , classDeclList(_cD) {};
};

class SiOpExpr : public Expr{
public:
    Expr * tarExpr ;
    SiOpExpr( Expr * _tE )
    : tarExpr ( _tE)  {};
};

class NegExpr : public SiOpExpr {
public:
    NegExpr ( Expr * _tE )
    : SiOpExpr( _tE) {} ;
};

class ParenExpr : public SiOpExpr {
public:
    ParenExpr ( Expr * _tE)
    : SiOpExpr( _tE ) {} ;
};

class BlockStmt : public Stmt{
public:
    StmtList stmtList ;
    BlockStmt( StmtList *_sL )
    : stmtList(_sL) {} ;
};

class IfThenElseStmt : public Stmt {
public:
    Expr* condExpr ;
    Stmt* thenStmt ,*elseStmt ;
    IfThenElseStmt( Expr * _cE ,
                    Stmt * _tS ,
                    Stmt * _eS )
    : condExpr(_cE) , thenStmt(_tS) , elseStmt(_eS) {};
};

class WhileStmt : public Stmt {
public:
    Expr* condExpr ;
    Stmt* bodyStmt ;
    WhileStmt( Expr * _cE , Stmt * _bS )
    : condExpr(_cE) , bodyStmt(_bS) {} ;
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
};

class ArrAssignStmt : public Stmt {
public:
    Ident * arrIdent ;
    Expr *     valueExpr ;
    Expr *     addressExpr ;
    ArrAssignStmt( Ident * _aI ,
                   Expr * _aE ,
                   Expr * _vE )
    : arrIdent(_aI) , addressExpr(_aE) ,
    valueExpr(_vE) {} ;
};

class VarDeclStmt : public Stmt {
public:
    TypeInfo * type ;
    Ident * varIdent ;
    VarDeclStmt( TypeInfo* _t , Ident* _i ) : type(_t) , varIdent(_i) {} ;
};

class ThisExpr : public Expr {
public:
    ThisExpr() {} ;
};

class TypeInfo {
public:
    std::string typeName ;
    TypeInfo(){};
    TypeInfo( std::string _tN ) : typeName(_tN) {} ;
    TypeInfo( TypeInfo * _t ) : typeName(_t->typeName) {} ;
};

class IntType : public TypeInfo {
public:
    IntType() : TypeInfo("int") {} ;
};

class ArrType : public TypeInfo {
public:
    TypeInfo* elemType ;
    ArrType( TypeInfo* _e )
    : elemType(_e) , TypeInfo("Arr") {} ;
};

class BoolType : public TypeInfo {
public:
    BoolType() : TypeInfo("boolean") { } ;
};

class ClassIdentType : public TypeInfo {
public:
    Ident * classIdent ;
    ClassIdentType(Ident *_cI )
    : classIdent(_cI) , TypeInfo("Class") {} ;
};

