/* Decompiled C draft; module arm9; ROM address 0213442c. No matching claim. */
#include "types.h"
#include "deps/0213442c_LogThrowAssertion.h"

void LogThrowAssertion(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  SomeSprintf(uRam02134468,param_1,param_2,param_3,param_4);
  OnAssertionFailed();
  return;
}

