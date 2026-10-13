/* Decompiled C draft; module arm9; ROM address 01ffcebc. No matching claim. */
#include "types.h"
#include "deps/01ffcebc_func_01ffcebc.h"

void func_01ffcebc(uint param_1,uint param_2,int *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar1 = param_2 + 4 & 3;
  uVar8 = *(uint *)(param_2 + 4 & 0xfffffffc);
  uVar9 = uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 4 & 3;
  uVar8 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar6 = uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20;
  uVar1 = param_2 + 0xc & 3;
  uVar8 = *(uint *)(param_2 + 0xc & 0xfffffffc);
  uVar5 = uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20;
  uVar4 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar3 = *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
          *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
  uVar1 = param_2 + 8 & 3;
  uVar8 = *(uint *)(param_2 + 8 & 0xfffffffc);
  uVar7 = uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0xc & 3;
  uVar8 = *(uint *)(param_1 + 0xc & 0xfffffffc);
  uVar2 = uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 8 & 3;
  uVar8 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar1 = uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20;
  *param_3 = (int)(uVar2 * uVar3 + uVar4 * uVar5 + (uVar6 * uVar7 - uVar1 * uVar9)) >> 0xc;
  param_3[1] = (int)(uVar2 * uVar9 + uVar6 * uVar5 + (uVar1 * uVar3 - uVar4 * uVar7)) >> 0xc;
  param_3[2] = (int)(uVar2 * uVar7 + uVar1 * uVar5 + (uVar4 * uVar9 - uVar6 * uVar3)) >> 0xc;
  param_3[3] = (int)(uVar2 * uVar5 - (uVar1 * uVar7 + uVar4 * uVar3 + uVar6 * uVar9)) >> 0xc;
  return;
}

