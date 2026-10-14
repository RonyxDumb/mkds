/* Decompiled C draft; module arm9; ROM address 02011558. No matching claim. */
#include "types.h"
#include "deps/02011558_func_02011558.h"

void func_02011558(int *param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_4 != 0) {
    *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + param_3;
    uVar1 = (uint)(param_1 + 1) & 3;
    uVar2 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
    param_1[1] = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + param_3;
    uVar1 = (uint)(param_1 + 2) & 3;
    uVar2 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    param_1[2] = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + param_3;
    return;
  }
  *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
             *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) +
             ((int)(param_3 *
                   (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                   *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20)) >> 0xc);
  uVar1 = param_2 + 4 & 3;
  uVar3 = *(uint *)(param_2 + 4 & 0xfffffffc);
  uVar2 = (uint)(param_1 + 1) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  param_1[1] = (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) +
               ((int)(param_3 * (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20)) >> 0xc);
  uVar1 = param_2 + 8 & 3;
  uVar3 = *(uint *)(param_2 + 8 & 0xfffffffc);
  uVar2 = (uint)(param_1 + 2) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  param_1[2] = (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) +
               ((int)(param_3 * (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20)) >> 0xc);
  return;
}

