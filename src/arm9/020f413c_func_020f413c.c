/* Decompiled C draft; module arm9; ROM address 020f413c. No matching claim. */
#include "types.h"
#include "deps/020f413c_func_020f413c.h"

void func_020f413c(undefined4 *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  *param_2 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
             *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  uVar1 = (uint)(param_1 + 2) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  *param_3 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  *param_1 = 0x13;
  param_1[2] = 0;
  param_1[8] = 0;
  param_1[3] = 0;
  *(undefined2 *)(param_1 + 4) = 0;
  *(undefined2 *)((int)param_1 + 0x12) = 0;
  iVar3 = 0;
  do {
    iVar4 = iVar3 + 1;
    param_1[iVar3 + 5] = 0;
    iVar3 = iVar4;
  } while (iVar4 < 3);
  return;
}

