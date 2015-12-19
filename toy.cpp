#include "llvm/IR/Verifier.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/ADT/ArrayRef.h"
#include "llvm/IR/Constant.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Analysis/Passes.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/IR/DataLayout.h"
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
static std::map<std::string, ClassDecl*> TypeNamedClassDecls ;
static std::map<std::string, TypeInfo*> TypeNamedValues ; 


static Module *TheModule;
static IRBuilder<> Builder(getGlobalContext());
static std::map<std::string, Value*> NamedValues;
static legacy::FunctionPassManager *TheFPM;

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
  std::cout<<" Reached CodeGen. "<<std::endl;
  this->typeCheck();
  std::cout<<" All Classes have been checked successfully. "<<std::endl;
  this->ClassInitial();
  std::cout<<" All Classes have been initialized successfully. "<<std::endl;
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

  legacy::FunctionPassManager OurFPM(TheModule);
  // Set up the optimizer pipeline.  Start with registering info about how the
  // target lays out data structures.
//  TheModule->setDataLayout(*TheExecutionEngine->getDataLayout());
  // Provide basic AliasAnalysis support for GVN.
  OurFPM.add(createBasicAliasAnalysisPass());
  // Do simple "peephole" optimizations and bit-twiddling optzns.
  OurFPM.add(createInstructionCombiningPass());
  // Reassociate expressions.
  OurFPM.add(createReassociatePass());
  // Eliminate Common SubExpressions.
  OurFPM.add(createGVNPass());
  // Simplify the control flow graph (deleting unreachable blocks, etc).
  OurFPM.add(createCFGSimplificationPass());
  OurFPM.doInitialization();
  // Set the global so the code gen can use this.
  TheFPM = &OurFPM;
  TheFPM->doInitialization();
  if (Value *PROG = programAst->codeGen()) {
    cerr << "Codegen result for Main Function(programAst):" << endl;
    PROG->dump();
  }
  else
    cerr << "Codegen failed! So sad..." << endl;

  cerr << "All of the generated code:" << endl;
  // Print out all of the generated code.
  
  TheFPM->doFinalization();

  freopen("tmp.ll","wb",stderr);
  TheModule->dump();

  return 0;
}
