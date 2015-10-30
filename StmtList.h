#include <iostream>
#include <vector>
#include <llvm/Value.h>
#include "MJParser.h"

class StmtList {
public:
    vector<class Stmt *> stmtList;
    StmtList( StmtList& _sL ,
              Stmt * _s )
    : declList(_sL->stmtList)
    {
        declList.push_back(_s);
    }
} ;
