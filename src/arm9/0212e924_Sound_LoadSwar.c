/* Decompiled C draft; module arm9; ROM address 0212e924. No matching claim. */
#include "types.h"
#include "deps/0212e924_Sound_LoadSwar.h"

bool Sound_LoadSwar(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = Sound_GetSwarPointer(param_1,0xff,param_2,1,0);
  return iVar1 == 0;
}

