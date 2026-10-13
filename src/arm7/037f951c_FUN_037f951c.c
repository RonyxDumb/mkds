/* Decompiled C draft; module arm7; ROM address 037f951c. No matching claim. */
#include "types.h"
#include "deps/037f951c_FUN_037f951c.h"

void FUN_037f951c(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar6;
  uint uVar7;
  uint uVar5;
  
  uVar6 = DAT_037f9580 + 8U & 3;
  uVar4 = *(uint *)(DAT_037f9580 + 8U & 0xfffffffc);
  uVar5 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
  uVar6 = 0;
  uVar4 = uVar5;
  while ((uVar4 != 0 &&
         (uVar1 = uVar4 + 0x54 & 3, uVar3 = *(uint *)(uVar4 + 0x54 & 0xfffffffc),
         uVar7 = param_1 + 0x54U & 3, uVar2 = *(uint *)(param_1 + 0x54U & 0xfffffffc),
         (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) <
         (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20)))) {
    uVar1 = uVar4 + 0x4c & 3;
    uVar7 = *(uint *)(uVar4 + 0x4c & 0xfffffffc);
    uVar6 = uVar4;
    uVar4 = uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20;
  }
  if (uVar6 == 0) {
    *(uint *)(param_1 + 0x4c) = uVar5;
    *(int *)(DAT_037f9580 + 8) = param_1;
  }
  else {
    uVar4 = uVar6 + 0x4c & 3;
    uVar5 = *(uint *)(uVar6 + 0x4c & 0xfffffffc);
    *(uint *)(param_1 + 0x4c) = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
    *(int *)(uVar6 + 0x4c) = param_1;
  }
  return;
}

