/* Decompiled C draft; module arm9; ROM address 0212dfa0. No matching claim. */
#include "types.h"
#include "deps/0212dfa0_AnotherSoundDtorFn.h"

void AnotherSoundDtorFn(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  Sound_DisposeFile(param_1,param_3,param_4);
  func_02020990(param_1,param_1 + param_2);
  SND_func_0042(param_1);
  return;
}

