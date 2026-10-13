/* Decompiled C draft; module arm9; ROM address 020f4754. No matching claim. */
#include "types.h"
#include "deps/020f4754_func_020f4754.h"

void func_020f4754(undefined4 *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  uVar2 = uRam020f47dc;
  uVar5 = (uint)(param_1 + 2) & 3;
  uVar1 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  param_1[2] = (uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20) - param_2;
  uVar5 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar5 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) * 0x1c +
          (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) + 8;
  uVar2 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  iVar3 = (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) * 0x44 +
          (*(uint *)(uRam020f47e0 & 0xfffffffc) >> (uRam020f47e0 & 3) * 8 |
          *(uint *)(uRam020f47e0 & 0xfffffffc) << (uRam020f47e0 & 3) * -8 + 0x20);
  uVar5 = iVar3 + 0x1c;
  uVar2 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  *(uint *)(iVar3 + 0x1c) = (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) - param_2;
  uVar5 = (uint)(param_1 + 2) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  if (uVar2 >> uVar5 * 8 != 0 || uVar2 << uVar5 * -8 + 0x20 != 0) {
    return;
  }
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

