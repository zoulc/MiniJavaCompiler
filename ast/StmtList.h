#ifndef STMTLIST_H
#define STMTLIST_H
#include <iostream>
#include <vector>
#include "AstStruct.h"

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

Value * StmtList::codegen()
{
	std::vector <class Stmt * > i;
	Value * res=NULL;
	for(i=stmtList.begin();i!=stmtList.end();i++)
		res=i->codegen();
	return res;
}

#endif
