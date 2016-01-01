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
#include "llvm/IR/Verifier.h"
#include "llvm/ExecutionEngine/GenericValue.h"
//#include "llvm/ExecutionEngine/Interpreter.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Support/ManagedStatic.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Bitcode/ReaderWriter.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/IR/ValueSymbolTable.h"
#include <cctype>
#include <cstdio>
#include <map>
#include <string>
#include <vector>

using namespace std;
using namespace llvm;

#include "node.h"
std::map<std::string, TemplateClassDecl*> NamedTemplateClassDecls;
#include "parser.hpp"

extern Program *programAst;
extern int yyparse();

//===----------------------------------------------------------------------===//
// Code Generation
//===----------------------------------------------------------------------===//

static std::map<std::string, Value*> NamedClassTypes ;
static std::map<std::string, ClassDecl*> NamedClassDecls ;
static std::map<std::string, ItfaceDecl*> NamedItfaceDecls ;

static std::map<std::string, ClassDecl*> TypeNamedClassDecls ;
static std::map<std::string, TypeInfo*> TypeNamedValues ;
static std::map<std::string, ItfaceDecl*> TypeNamedItfaceDecls ;
static std::map<std::string, Ident*> IdentNamedValues ;
static std::vector<ClassDecl*> classToInit ;

static Module *TheModule;
static IRBuilder<> Builder(getGlobalContext());
static std::map<std::string, Value*> NamedValues;
static legacy::FunctionPassManager *TheFPM;

/*  Used for lambda  */
static int LambdaLevel;
static map<string, int> NamedValuesLevel;
static map<string, int> IsField;
static vector<BasicBlock *> LambdaBB;
static vector<BasicBlock *> FunctionBB;
static vector<Value *> LambdaArgStart;
static vector<Value *> FunctionArgStart;
static vector<int> LambdaArgCount;
static ClassDecl* LambdaOwner;

static int type_check_level = 0 ;
static int code_gen_level = 0 ;

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
    cerr << " [ Gava ] Main function generation failed!" << endl;
  return NULL;
}

Value *Program::codeGen() {
  this->typeCheck();
  std::cout<<" [ Gava ] All Classes have been checked. "<<std::endl;
  this->ClassInitial();
  std::cout<<" [ Gava ] Now check the instantiated template class. "<<std::endl;
  for (int i = 0; i < classToInit.size(); ++i)
    classToInit[i]->codeGen();
  std::cout<<" [ Gava ] All Classes have been initialized successfully. "<<std::endl;
  return mainClassDecl->codeGen();
}

//===----------------------------------------------------------------------===//
// Main driver code.
//===----------------------------------------------------------------------===//

int main( int argc , char** argv ) {
  std::string tarFile("tmp.ll");
	
  for ( int i = 0 ; i < argc ; i ++ ) {
      if ( ( argv[i][0] == '-') && ( argv[i][1] == 'v') && ( argv[i][2] != 't' ) && ( argv[i][2] !='i' ) ) {
          char tmp1 , tmp2 ;
          int level ;
          level = 0 ;
          sscanf( argv[i] , "%c%c%d" , &tmp1 , &tmp2 , &level ) ;
          if ( level >= 2 ) level = 2 ;
          type_check_level = level ;
          code_gen_level = level ; 
      } 
      if ( ( argv[i][0] == '-') && ( argv[i][1] == 'v') && ( argv[i][2] == 't' ) ) {
          char tmp1 , tmp2 , tmp3 ; 
          int level ;
          level = 0 ;
          sscanf( argv[i] , "%c%c%c%d" , &tmp1 , &tmp2 , &tmp3 , &level ) ;
          if ( level >= 2 ) level = 2 ;
          type_check_level = level ;
      } 
      if ( ( argv[i][0] == '-') && ( argv[i][1] == 'v') && ( argv[i][2] == 'i' ) ) {
          char tmp1 , tmp2 , tmp3 ;
          int level ;
          level = 0 ;
          sscanf( argv[i] , "%c%c%c%d" , &tmp1 , &tmp2 , &tmp3 , &level ) ;
          if ( level >= 2 ) level = 2 ;
          type_check_level = level ;
      } 
      if ( ( argv[i][0] == '-' ) && ( argv[i][1] == 'o' ) ) {
	  char name[100];
	  sscanf( argv[i+1], "%s" , name ) ; 
	  tarFile = name;
      }
  }

  cerr << " [ Gava ] Main driver started, running yyparse()..." << endl;

  yyparse();

  cerr << " [ Gava ] Ready for llvm IR generation." << endl;

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
    //cerr << "Codegen result for Main Function(programAst):" << endl;
    //PROG->dump();
  }
  else
    cerr << " [ Gava ] Codegen failed! So sad..." << endl;

  cerr << " [ Gava ] All of the generated code is write down to File \'"<<tarFile<<"\'" << endl;
  // Print out all of the generated code.

  TheFPM->doFinalization();

  //freopen("tmp.ll","wb",stderr);
  //TheModule->dump();
  std::error_code EC;
  llvm::raw_fd_ostream out( tarFile ,EC,llvm::sys::fs::F_None);
  TheModule->print(out,nullptr);

  return 0;
}
