/* Decompiled C draft; module arm9; ROM address 0214f598. No matching claim. */
#include "types.h"
#include "deps/0214f598_func_0214f598.h"

void func_0214f598(int *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_1 == (int *)0x0) {
    return;
  }
  uVar4 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  if (uVar4 == 0) {
    *(undefined4 *)(param_2 + 8) = 0;
    *param_1 = param_2;
    return;
  }
  uVar1 = uVar4 + 8 & 3;
  uVar2 = *(uint *)(uVar4 + 8 & 0xfffffffc);
  uVar1 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  while (uVar1 != 0) {
    uVar2 = uVar1 + 8 & 3;
    uVar3 = *(uint *)(uVar1 + 8 & 0xfffffffc);
    uVar4 = uVar1;
    uVar1 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  }
  *(undefined4 *)(param_2 + 8) = 0;
  *(int *)(uVar4 + 8) = param_2;
  return;
}

