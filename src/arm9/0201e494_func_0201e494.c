/* Decompiled C draft; module arm9; ROM address 0201e494. No matching claim. */
#include "types.h"
#include "deps/0201e494_func_0201e494.h"

void func_0201e494(undefined4 *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  if (uVar2 == 0) {
    *param_1 = param_2;
    param_1[2] = param_2;
    *param_2 = 0;
    param_2[1] = *(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
                 *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20;
  }
  else {
    *param_2 = uVar2;
    param_2[1] = 0;
    *(uint **)((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 4) =
         param_2;
    *param_1 = param_2;
  }
  uVar2 = (uint)(param_1 + 1) & 3;
  uVar1 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  param_1[1] = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 1;
  return;
}

