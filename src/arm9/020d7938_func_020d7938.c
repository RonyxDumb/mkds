/* Decompiled C draft; module arm9; ROM address 020d7938. No matching claim. */
#include "types.h"
#include "deps/020d7938_func_020d7938.h"

void func_020d7938(uint param_1,int param_2,int *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar1 = param_2 + 0xcU & 3;
  uVar6 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
  uVar2 = param_1 + 8 & 3;
  uVar5 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar4 = param_2 + 4U & 3;
  uVar3 = *(uint *)(param_2 + 4U & 0xfffffffc);
  *param_3 = (int)((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                   *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) *
                   (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) -
                  (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) *
                  (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20)) >> 0xc;
  uVar1 = param_1 + 0xc & 3;
  uVar3 = *(uint *)(param_1 + 0xc & 0xfffffffc);
  uVar2 = param_2 + 4U & 3;
  uVar4 = *(uint *)(param_2 + 4U & 0xfffffffc);
  param_3[1] = (int)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) *
                    (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20)) >> 0xc;
  uVar1 = param_2 + 4U & 3;
  uVar3 = *(uint *)(param_2 + 4U & 0xfffffffc);
  uVar2 = param_1 + 8 & 3;
  uVar6 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar4 = param_2 + 0xcU & 3;
  uVar5 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
  param_3[2] = (int)((uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) *
                     (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) +
                    (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                    *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) *
                    (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20)) >> 0xc;
  uVar1 = param_1 + 0xc & 3;
  uVar3 = *(uint *)(param_1 + 0xc & 0xfffffffc);
  uVar2 = param_2 + 0xcU & 3;
  uVar4 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
  param_3[3] = (int)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) *
                    (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20)) >> 0xc;
  return;
}

