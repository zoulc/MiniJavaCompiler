#ifndef VARARGLIST_H
#define VARARGLIST_H

#include <iostream>
#include <vector>
#include "AstStruct.h"

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

#endif
