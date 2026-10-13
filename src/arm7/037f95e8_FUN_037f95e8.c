/* Decompiled C draft; module arm7; ROM address 037f95e8. No matching claim. */
#include "types.h"
#include "deps/037f95e8_FUN_037f95e8.h"

void FUN_037f95e8(uint *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  while ((uVar5 != 0 &&
         (uVar2 = uVar5 + 0x54 & 3, uVar4 = *(uint *)(uVar5 + 0x54 & 0xfffffffc),
         uVar3 = param_2 + 0x54 & 3, uVar1 = *(uint *)(param_2 + 0x54 & 0xfffffffc),
         (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) <=
         (uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20)))) {
    if (uVar5 == param_2) {
      return;
    }
    uVar2 = uVar5 + 100 & 3;
    uVar5 = *(uint *)(uVar5 + 100 & 0xfffffffc);
    uVar5 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
  }
  if (uVar5 != 0) {
    uVar2 = uVar5 + 0x60 & 3;
    uVar3 = *(uint *)(uVar5 + 0x60 & 0xfffffffc);
    uVar2 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
    if (uVar2 == 0) {
      *param_1 = param_2;
    }
    else {
      *(uint *)(uVar2 + 100) = param_2;
    }
    *(uint *)(param_2 + 0x60) = uVar2;
    *(uint *)(param_2 + 100) = uVar5;
    *(uint *)(uVar5 + 0x60) = param_2;
    return;
  }
  uVar5 = (uint)(param_1 + 1) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  uVar5 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
  if (uVar5 == 0) {
    *param_1 = param_2;
  }
  else {
    *(uint *)(uVar5 + 100) = param_2;
  }
  *(uint *)(param_2 + 0x60) = uVar5;
  *(undefined4 *)(param_2 + 100) = 0;
  param_1[1] = param_2;
  return;
}

