/* Decompiled C draft; module arm7; ROM address 037fa96c. No matching claim. */
#include "types.h"
#include "deps/037fa96c_FUN_037fa96c.h"

undefined4 FUN_037fa96c(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_1 + 0xcU & 3;
  uVar2 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  param_3 = param_3 - *(short *)(param_1 + 0x10);
  if ((-1 < (int)(param_2 - uVar3)) && ((param_2 != uVar3 || (-1 < param_3)))) {
    if (param_3 < 0) {
      param_3 = param_3 + DAT_037fa9b8;
    }
    if (*(short *)(param_1 + 0x12) < param_3) {
      uVar1 = 2;
    }
    else {
      uVar1 = 1;
    }
    return uVar1;
  }
  return 0;
}

