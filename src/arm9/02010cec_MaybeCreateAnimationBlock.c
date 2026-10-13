/* Decompiled C draft; module arm9; ROM address 02010cec. No matching claim. */
#include "types.h"
#include "deps/02010cec_MaybeCreateAnimationBlock.h"

void MaybeCreateAnimationBlock
               (undefined4 *param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar3;
  uint uVar2;
  
  uVar3 = 0;
  *param_1 = 0;
  param_1[2] = param_2;
  param_1[4] = 0;
  *(undefined1 *)(param_1 + 6) = 0x7f;
  param_1[1] = 0x1000;
  uVar1 = uRam02010d8c;
  param_1[5] = param_4;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 == 0) {
    return;
  }
  while ((*param_2 != *(char *)(iRam02010d90 + uVar3 * 8) ||
         (*(short *)(param_2 + 2) != *(short *)(iRam02010d90 + uVar3 * 8 + 2)))) {
    uVar3 = uVar3 + 1;
    if (uVar2 <= uVar3) {
      return;
    }
  }
  uVar2 = iRam02010d94 + uVar3 * 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  (*(code *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20))();
  return;
}

