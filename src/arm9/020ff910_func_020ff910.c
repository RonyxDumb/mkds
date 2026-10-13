/* Decompiled C draft; module arm9; ROM address 020ff910. No matching claim. */
#include "types.h"
#include "deps/020ff910_func_020ff910.h"

void func_020ff910(int param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar4;
  
  uVar1 = param_1 + 0xd0U & 3;
  uVar3 = *(uint *)(param_1 + 0xd0U & 0xfffffffc);
  uVar4 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  *(int *)(param_1 + 0xb8) =
       (int)(*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
            *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) >> 4;
  uVar1 = uVar4 + 4 & 3;
  uVar3 = *(uint *)(uVar4 + 4 & 0xfffffffc);
  *(int *)(param_1 + 0xbc) = (int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = uVar4 + 8 & 3;
  uVar3 = *(uint *)(uVar4 + 8 & 0xfffffffc);
  *(int *)(param_1 + 0xc0) = (int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) >> 4;
  uVar2 = *(undefined4 *)(param_1 + 0x98);
  uVar5 = *(undefined4 *)(param_1 + 0x9c);
  uVar6 = *(undefined4 *)(param_1 + 0xa0);
  *param_2 = *(undefined4 *)(param_1 + 0x94);
  param_2[1] = uVar2;
  param_2[2] = uVar5;
  param_2[3] = uVar6;
  uVar2 = *(undefined4 *)(param_1 + 0xa8);
  uVar5 = *(undefined4 *)(param_1 + 0xac);
  uVar6 = *(undefined4 *)(param_1 + 0xb0);
  param_2[4] = *(undefined4 *)(param_1 + 0xa4);
  param_2[5] = uVar2;
  param_2[6] = uVar5;
  param_2[7] = uVar6;
  uVar2 = *(undefined4 *)(param_1 + 0xb8);
  uVar5 = *(undefined4 *)(param_1 + 0xbc);
  uVar6 = *(undefined4 *)(param_1 + 0xc0);
  param_2[8] = *(undefined4 *)(param_1 + 0xb4);
  param_2[9] = uVar2;
  param_2[10] = uVar5;
  param_2[0xb] = uVar6;
  MTX_Concat33(uRam020ff978,param_2,param_2);
  return;
}

