/* Decompiled C draft; module arm7; ROM address 037fa564. No matching claim. */
#include "types.h"
#include "deps/037fa564_FUN_037fa564.h"

void FUN_037fa564(undefined4 *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar4;
  uint uVar3;
  
  uVar1 = FUN_037faf70();
  if (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 == 0 &&
      *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20 == 0) {
    FUN_037faf84();
  }
  else {
    uVar3 = (uint)(param_1 + 6) & 3;
    uVar2 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    if (uVar3 == 0) {
      uVar2 = (uint)(param_1 + 5) & 3;
      uVar4 = *(uint *)((uint)(param_1 + 5) & 0xfffffffc);
      DAT_037fa5f0[1] = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
    }
    else {
      uVar2 = (uint)(param_1 + 5) & 3;
      uVar4 = *(uint *)((uint)(param_1 + 5) & 0xfffffffc);
      *(uint *)(uVar3 + 0x14) = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
    }
    uVar2 = (uint)(param_1 + 5) & 3;
    uVar4 = *(uint *)((uint)(param_1 + 5) & 0xfffffffc);
    uVar2 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
    if (uVar2 == 0) {
      *DAT_037fa5f0 = uVar3;
      if (uVar3 != 0) {
        FUN_037fa884();
      }
    }
    else {
      *(uint *)(uVar2 + 0x18) = uVar3;
    }
    *param_1 = 0;
    param_1[7] = 0;
    param_1[8] = 0;
    FUN_037faf84(uVar1);
  }
  return;
}

