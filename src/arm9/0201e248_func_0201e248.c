/* Decompiled C draft; module arm9; ROM address 0201e248. No matching claim. */
#include "types.h"
#include "deps/0201e248_func_0201e248.h"

void func_0201e248(uint param_1,int param_2,int *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar1 = param_2 + 8U & 3;
  uVar5 = *(uint *)(param_2 + 8U & 0xfffffffc);
  uVar2 = param_2 + 0x14U & 3;
  uVar3 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
  *param_3 = (*(uint *)((uint)param_3 & 0xfffffffc) >> ((uint)param_3 & 3) * 8 |
             *(uint *)((uint)param_3 & 0xfffffffc) << ((uint)param_3 & 3) * -8 + 0x20) +
             ((int)((int)*(short *)(param_1 + 0xc) *
                   (((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                     *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) -
                    (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20)) -
                   (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20))) >> 0xc);
  uVar1 = param_1 + 4 & 3;
  uVar8 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar2 = param_2 + 0xcU & 3;
  uVar7 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
  uVar3 = param_2 + 0x18U & 3;
  uVar4 = *(uint *)(param_2 + 0x18U & 0xfffffffc);
  uVar5 = (uint)(param_3 + 1) & 3;
  uVar6 = *(uint *)((uint)(param_3 + 1) & 0xfffffffc);
  param_3[1] = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) +
               ((int)((int)*(short *)(param_1 + 0xc) *
                     (((uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20) -
                      (uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20)) -
                     (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20))) >> 0xc);
  uVar1 = param_1 + 8 & 3;
  uVar8 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar2 = param_2 + 0x10U & 3;
  uVar7 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
  uVar3 = param_2 + 0x1cU & 3;
  uVar4 = *(uint *)(param_2 + 0x1cU & 0xfffffffc);
  uVar5 = (uint)(param_3 + 2) & 3;
  uVar6 = *(uint *)((uint)(param_3 + 2) & 0xfffffffc);
  param_3[2] = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) +
               ((int)((int)*(short *)(param_1 + 0xc) *
                     (((uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20) -
                      (uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20)) -
                     (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20))) >> 0xc);
  return;
}

