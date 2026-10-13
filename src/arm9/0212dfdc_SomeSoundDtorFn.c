/* Decompiled C draft; module arm9; ROM address 0212dfdc. No matching claim. */
#include "types.h"
#include "deps/0212dfdc_SomeSoundDtorFn.h"

void SomeSoundDtorFn(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  Sound_DisposeFile(param_1,param_3,param_4);
  func_020209bc(param_1,param_1 + param_2);
  func_02021c34(param_1);
  return;
}

