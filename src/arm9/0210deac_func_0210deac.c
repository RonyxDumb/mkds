/* Decompiled C draft; module arm9; ROM address 0210deac. No matching claim. */
#include "types.h"
#include "deps/0210deac_func_0210deac.h"

void func_0210deac(uint param_1,uint *param_2,int param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar10;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  uint uVar9;
  
  uVar4 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  if ((int)uVar4 <= param_3) {
    return;
  }
  uVar9 = param_1 + 4 & 3;
  uVar8 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar9 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
  while (uVar8 = uVar9 + param_3 * 0x10, uVar2 = uVar8 & 3, uVar8 = *(uint *)(uVar8 & 0xfffffffc),
        (uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) <=
        (*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
        *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20)) {
    param_3 = param_3 + 1;
    if ((int)uVar4 <= param_3) {
      return;
    }
  }
  puVar10 = (uint *)(uVar9 + param_3 * 0x10);
  uVar4 = *puVar10;
  uVar9 = puVar10[1];
  uVar2 = puVar10[2];
  uVar5 = puVar10[3];
  uVar8 = param_2[1];
  uVar3 = param_2[2];
  uVar6 = param_2[3];
  *puVar10 = *param_2;
  puVar10[1] = uVar8;
  puVar10[2] = uVar3;
  puVar10[3] = uVar6;
  uVar8 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  param_3 = param_3 + 1;
  if ((int)uVar8 <= param_3) {
    return;
  }
  if ((int)uVar8 <= param_3) {
    return;
  }
  uVar3 = param_1 + 4 & 3;
  uVar6 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar3 = uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20;
  while (uVar6 = uVar3 + param_3 * 0x10, uVar7 = uVar6 & 3, uVar6 = *(uint *)(uVar6 & 0xfffffffc),
        (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) <= uVar4) {
    param_3 = param_3 + 1;
    if ((int)uVar8 <= param_3) {
      return;
    }
  }
  puVar10 = (uint *)(uVar3 + param_3 * 0x10);
  uVar8 = *puVar10;
  uVar3 = puVar10[1];
  uVar6 = puVar10[2];
  uVar7 = puVar10[3];
  *puVar10 = uVar4;
  puVar10[1] = uVar9;
  puVar10[2] = uVar2;
  puVar10[3] = uVar5;
  uVar4 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  param_3 = param_3 + 1;
  if (param_3 < (int)uVar4) {
    if ((int)uVar4 <= param_3) {
      return;
    }
    uVar9 = param_1 + 4 & 3;
    uVar2 = *(uint *)(param_1 + 4 & 0xfffffffc);
    uVar9 = uVar2 >> uVar9 * 8 | uVar2 << uVar9 * -8 + 0x20;
    while (uVar2 = uVar9 + param_3 * 0x10, uVar5 = uVar2 & 3, uVar2 = *(uint *)(uVar2 & 0xfffffffc),
          (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) <= uVar8) {
      param_3 = param_3 + 1;
      if ((int)uVar4 <= param_3) {
        return;
      }
    }
    puVar1 = (undefined4 *)(uVar9 + param_3 * 0x10);
    uStack_20 = *puVar1;
    uStack_1c = puVar1[1];
    uStack_18 = puVar1[2];
    uStack_14 = puVar1[3];
    uVar4 = param_1 + 4 & 3;
    uVar9 = *(uint *)(param_1 + 4 & 0xfffffffc);
    puVar10 = (uint *)((uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20) + param_3 * 0x10);
    *puVar10 = uVar8;
    puVar10[1] = uVar3;
    puVar10[2] = uVar6;
    puVar10[3] = uVar7;
    if (param_3 + 1 <
        (int)(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
             *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20)) {
      func_0210deac(param_1,&uStack_20);
      return;
    }
    return;
  }
  return;
}

