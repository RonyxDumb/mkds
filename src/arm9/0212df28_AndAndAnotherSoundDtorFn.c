/* Decompiled C draft; module arm9; ROM address 0212df28. No matching claim. */
#include "types.h"
#include "deps/0212df28_AndAndAnotherSoundDtorFn.h"

void AndAndAnotherSoundDtorFn(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = SND_GetWaveDataAddress(param_3,param_4);
  if (param_1 == iVar1) {
    SND_SetWaveDataAddress(param_3,param_4,0);
  }
  func_02020990(param_1,param_1 + param_2);
  return;
}

