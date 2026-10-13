/* Decompiled C draft; module arm9; ROM address 0208b5b0. No matching claim. */
#include "types.h"
#include "deps/0208b5b0_func_0208b5b0.h"

void func_0208b5b0(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar4 = param_1 + 0x20U & 3;
  uVar2 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar2 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
  uVar4 = uVar2 & 3;
  uVar3 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = param_2 + 4 & 3;
  uVar6 = *(uint *)(param_2 + 4 & 0xfffffffc);
  uVar4 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 4;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar1 = param_2 + 8 & 3;
  uVar5 = *(uint *)(param_2 + 8 & 0xfffffffc);
  *(uint *)(param_1 + 0x28) =
       (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) +
       ((int)(*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
             *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) >> 4);
  uVar4 = param_1 + 0x20U & 3;
  uVar3 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar3 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar4 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 8;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(uint *)(param_1 + 0x2c) =
       (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) +
       ((int)(uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) >> 4);
  uVar4 = param_1 + 0x20U & 3;
  uVar2 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar2 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
  uVar4 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar4 = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) + 0xc;
  uVar2 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(uint *)(param_1 + 0x30) =
       (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) +
       ((int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) >> 4);
  return;
}

