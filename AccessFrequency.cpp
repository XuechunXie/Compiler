//===- AccessFrequency.cpp - Caculate the AccessFrequency  ---------------===//
//
// This file implements Compute the read and write access frequency for 
// pointer type function arguments.
// Identify addresses related to this type of arguments, and combine all their load/store
// access frequency.
//
//===----------------------------------------------------------------------===//

#include "llvm/ADT/Statistic.h"
#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
using namespace llvm;

#define DEBUG_TYPE "hello"

STATISTIC(HelloCounter, "Counts number of functions greeted");

namespace {
  // declare an AccessFrequency class to be a subclass of FunctionPass
  struct AccessFrequency : public FunctionPass {
    static char ID; // Pass identification, replacement for typeid
    AccessFrequency() : FunctionPass(ID) {} //This declares pass identifier used by LLVM to identify pass

    bool runOnFunction(Function &F) override {
      ++HelloCounter;
      errs() << "AccessFrequency: ";
      errs().write_escaped(F.getName()) << '\n';
      return false;
    }
        // We don't modify the program, so we preserve all analyses.
    void getAnalysisUsage(AnalysisUsage &AU) const override {
      AU.setPreservesAll();
    }
  };
}

char AccessFrequency::ID = 0;
static RegisterPass<AccessFrequency> X("AccessFrequency", "Access Frequency Caluculation pass");
