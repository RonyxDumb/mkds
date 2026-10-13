/* Decompiled C draft; module arm7; ROM address 03804e48. No matching claim. */
#include "types.h"
#include "deps/03804e48_FUN_03804e48.h"

undefined4 FUN_03804e48(uint param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 extraout_r1;
  
  if (param_2 - 1U < 2) {
    param_1 = param_1 - 1;
    param_2 = param_2 + 0xc;
  }
  iVar1 = FUN_03806d38(param_1,400);
  iVar2 = FUN_03806d38(param_1,100);
  iVar3 = FUN_03806d38(param_2 * 0xd + 8,5);
  FUN_03806d38(param_3 + iVar1 + ((param_1 + (param_1 >> 2)) - iVar2) + iVar3,7);
  return extraout_r1;
}

