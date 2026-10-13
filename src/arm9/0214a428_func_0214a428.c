/* Decompiled C draft; module arm9; ROM address 0214a428. No matching claim. */
#include "types.h"
#include "deps/0214a428_func_0214a428.h"

void func_0214a428(uint *param_1,uint param_2,int param_3,int param_4,int param_5,int param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar1 = param_2 + 4 & 3;
  uVar2 = *(uint *)(param_2 + 4 & 0xfffffffc);
  *param_1 = (int)((*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                   *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) << 0xc) >> 0x10 &
             0xffffU | ((int)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) << 0xc) >> 0x10) <<
                       0x10;
  uVar1 = param_2 + 8 & 3;
  uVar5 = *(uint *)(param_2 + 8 & 0xfffffffc);
  uVar2 = param_2 + 0xc & 3;
  uVar3 = *(uint *)(param_2 + 0xc & 0xfffffffc);
  param_1[1] = (int)((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) << 0xc) >> 0x10 & 0xffffU |
               ((int)((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) << 0xc) >> 0x10) << 0x10;
  uVar1 = param_2 + 4 & 3;
  uVar6 = *(uint *)(param_2 + 4 & 0xfffffffc);
  uVar2 = param_2 + 0xc & 3;
  uVar5 = *(uint *)(param_2 + 0xc & 0xfffffffc);
  uVar3 = param_2 + 8 & 3;
  uVar4 = *(uint *)(param_2 + 8 & 0xfffffffc);
  param_1[2] = (int)((*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                     *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) *
                     (param_5 - param_3) +
                     (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) * (param_6 - param_4) +
                    param_3 * 0x1000) >> 4;
  param_1[3] = (int)((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) * (param_5 - param_3) +
                     (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) * (param_6 - param_4) +
                    param_4 * 0x1000) >> 4;
  return;
}

