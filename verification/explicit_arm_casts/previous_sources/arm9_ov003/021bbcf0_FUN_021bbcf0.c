/* Decompiled C draft; module arm9_ov003; ROM address 021bbcf0. No matching claim. */
#include "types.h"
#include "deps/021bbcf0_FUN_021bbcf0.h"

void FUN_021bbcf0(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = *(uint *)(param_1 + 0x10) >> 3 & 0x3f;
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) + param_3 * 8;
  if (*(uint *)(param_1 + 0x10) < param_3 * 8) {
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  }
  *(uint *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + (param_3 >> 0x1d);
  uVar2 = -uVar1 + 0x40;
  if (param_3 < uVar2) {
    uVar3 = 0;
  }
  else {
    FUN_021bb3bc(param_1 + 0x18 + uVar1,param_2,uVar2);
    FUN_021bb438(param_1,param_1 + 0x18);
    uVar1 = -uVar1;
    while (uVar3 = uVar2, uVar1 + 0x7f < param_3) {
      FUN_021bb438(param_1,param_2 + uVar3);
      uVar2 = uVar3 + 0x40;
      uVar1 = uVar3;
    }
    uVar1 = 0;
  }
  FUN_021bb3bc(param_1 + 0x18 + uVar1,param_2 + uVar3,param_3 - uVar3);
  return;
}

