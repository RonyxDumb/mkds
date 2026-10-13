/* Decompiled C draft; module arm9; ROM address 0212e95c. No matching claim. */
#include "types.h"
#include "deps/0212e95c_Sound_LoadSbnk.h"

bool Sound_LoadSbnk(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = Sound_GetSbnkPointer(param_1,0xff,param_2,1,0);
  return iVar1 == 0;
}

