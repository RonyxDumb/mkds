/* Decompiled C draft; module arm9_ov000; ROM address 021b0138. No matching claim. */
#include "types.h"
#include "deps/021b0138_FUN_021b0138.h"

undefined4 FUN_021b0138(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = FUN_021b01b4(param_1,param_2,param_4);
  iVar2 = FUN_021b01b4(param_3 + 0xc,8,uVar1);
  uVar3 = iVar2 + param_2;
  if ((uVar3 & DAT_021b0180) != 0) {
    uVar3 = uVar3 + 1 & DAT_021b0184;
  }
  if (uVar3 != DAT_021b0184) {
    return 1;
  }
  return 0;
}

