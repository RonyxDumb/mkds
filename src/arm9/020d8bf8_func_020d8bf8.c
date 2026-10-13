/* Decompiled C draft; module arm9; ROM address 020d8bf8. No matching claim. */
#include "types.h"
#include "deps/020d8bf8_func_020d8bf8.h"

void func_020d8bf8(uint param_1,undefined4 param_2,int *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar3 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar1 = param_1 + 0xc & 3;
  uVar6 = *(uint *)(param_1 + 0xc & 0xfffffffc);
  uVar4 = uVar3 & 3;
  uVar8 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = param_1 + 0x14 & 3;
  uVar5 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
  uVar2 = param_1 + 0x10 & 3;
  uVar7 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
  func_020d939c((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) * 0x54 +
                (uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20),
                uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20,
                uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20,param_2,param_3);
  uVar1 = param_1 + 0x18 & 3;
  uVar4 = *(uint *)(param_1 + 0x18 & 0xfffffffc);
  if (uVar4 >> uVar1 * 8 == 0 && uVar4 << uVar1 * -8 + 0x20 == 0) {
    *param_3 = -(*(uint *)((uint)param_3 & 0xfffffffc) >> ((uint)param_3 & 3) * 8 |
                *(uint *)((uint)param_3 & 0xfffffffc) << ((uint)param_3 & 3) * -8 + 0x20);
    uVar1 = (uint)(param_3 + 1) & 3;
    uVar4 = *(uint *)((uint)(param_3 + 1) & 0xfffffffc);
    param_3[1] = -(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
    uVar1 = (uint)(param_3 + 2) & 3;
    uVar4 = *(uint *)((uint)(param_3 + 2) & 0xfffffffc);
    param_3[2] = -(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
    return;
  }
  return;
}

