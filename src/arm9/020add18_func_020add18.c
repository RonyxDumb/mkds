/* Decompiled C draft; module arm9; ROM address 020add18. No matching claim. */
#include "types.h"
#include "deps/020add18_func_020add18.h"

void func_020add18(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = NFTR_GetCharacterWidthTileEntry(param_2,param_3);
  *param_1 = uVar1;
  uVar1 = NFTR_SomeFn_2(param_2,param_3);
  param_1[1] = uVar1;
  return;
}

