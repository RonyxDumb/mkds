/* Decompiled C draft; module arm9; ROM address 02015eb8. No matching claim. */
#include "types.h"
#include "deps/02015eb8_func_02015eb8.h"

void func_02015eb8(uint *param_1,uint param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  
  if ((param_4 & 4) == 0) {
    param_1[1] = *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                 *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
    uVar1 = param_2 + 4 & 3;
    uVar2 = *(uint *)(param_2 + 4 & 0xfffffffc);
    param_1[2] = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
    uVar1 = param_2 + 8 & 3;
    uVar2 = *(uint *)(param_2 + 8 & 0xfffffffc);
    param_1[3] = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  }
  else {
    *param_1 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20 | 1;
  }
  *param_1 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
             *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20 | 0x18;
  return;
}

