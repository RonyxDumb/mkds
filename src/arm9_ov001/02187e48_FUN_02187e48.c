/* Decompiled C draft; module arm9_ov001; ROM address 02187e48. No matching claim. */
#include "types.h"
#include "deps/02187e48_FUN_02187e48.h"

void FUN_02187e48(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)*(short *)(*(int *)(param_1 + 0x9c) + 0x26);
  uVar1 = *(int *)(param_1 + DAT_02187e70) + 1;
  if ((int)(uVar2 + param_2) <= (int)uVar1) {
    uVar1 = uVar2;
  }
  *(uint *)(param_1 + DAT_02187e70) = uVar1 & 0xffff;
  *(undefined4 *)(param_1 + DAT_02187e74) = 0;
  return;
}

