/* Decompiled C draft; module arm9; ROM address 020f40dc. No matching claim. */
#include "types.h"
#include "deps/020f40dc_func_020f40dc.h"

void func_020f40dc(int *param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  *param_1 = param_2;
  param_1[2] = param_3;
  param_1[8] = 0;
  uVar2 = (uint)(param_1 + 1) & 3;
  uVar1 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  uVar2 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 0x1fc;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  func_0206c14c(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  uVar2 = param_2 * 0x1c +
          (*(uint *)(uRam020f4138 & 0xfffffffc) >> (uRam020f4138 & 3) * 8 |
          *(uint *)(uRam020f4138 & 0xfffffffc) << (uRam020f4138 & 3) * -8 + 0x20) + 0x10;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  param_1[3] = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  *(undefined2 *)(param_1 + 4) = 0;
  *(undefined2 *)((int)param_1 + 0x12) = 0;
  return;
}

