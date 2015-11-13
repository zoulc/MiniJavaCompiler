#include "llvm/IR/Verifier.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/ArrayRef.h"
#include <cctype>
#include <cstdio>
#include <map>
#include <string>
#include <vector>

using namespace std;
using namespace llvm;

#include "node.h"
#include "parser.hpp"

extern Program *programAst;
extern int yyparse();

//===----------------------------------------------------------------------===//
// Code Generation
//===----------------------------------------------------------------------===//

static std::map<std::string, Value*> NamedClassTypes ; 
static std::map<std::string, ClassDecl*> NamedClassDecls ; 

static Module *TheModule;
static IRBuilder<> Builder(getGlobalContext());
static std::map<std::string, Value*> NamedValues;

#include "codegen.cpp"

Value *MainClassDecl::codeGen() {
  std::vector<Type*> Args;

  NamedValues.clear();

  FunctionType *FT = FunctionType::get(Type::getInt32Ty(getGlobalContext()),
				       Args, false);
  Function *MainFunction = Function::Create(FT, Function::ExternalLinkage, "main", TheModule);

  // Create a new basic block to start insertion into.
  BasicBlock *BB = BasicBlock::Create(getGlobalContext(), "entry", MainFunction);
  Builder.SetInsertPoint(BB);

  stmtList.codeGen();

  if (Value *RetVal = ConstantInt::get(getGlobalContext(), APInt(32, 0, false))) {
    // Finish off the function
    Builder.CreateRet(RetVal);

    // Validate the generated code, checking for consistency.
    verifyFunction(*MainFunction);

    return MainFunction;
  }
  else
    cerr << "Main function generation failed!" << endl;
  return NULL;
}

Value *Program::codeGen() {
  return mainClassDecl->codeGen();
}

//===----------------------------------------------------------------------===//
// Main driver code.
//===----------------------------------------------------------------------===//

int main() {
  cerr << "Main driver started, running yyparse()..." << endl;

  yyparse();

  cerr << "Ready for llvm IR generation." << endl;

  LLVMContext &Context = getGlobalContext();

  // Make the module, which holds all the code.
  TheModule = new Module("my cool mini-java", Context);

  if (Value *PROG = programAst->codeGen()) {
    cerr << "Codegen result for Main Function(programAst):" << endl;
    PROG->dump();
  }
  else
    cerr << "Codegen failed! So sad..." << endl;

  cerr << "All of the generated code:" << endl;
  // Print out all of the generated code.
  TheModule->dump();

  return 0;
}
