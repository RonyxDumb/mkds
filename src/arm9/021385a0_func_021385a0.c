/* Decompiled C draft; module arm9; ROM address 021385a0. No matching claim. */
#include "types.h"
#include "deps/021385a0_func_021385a0.h"

uint func_021385a0(int *param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  if (param_3 == 0) {
    uVar1 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
            *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
    uVar2 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) & 0xff;
    if (uVar2 == 0) {
      param_1[1] = 1;
      uVar2 = 0xffffffff;
    }
    else {
      *param_1 = uVar1 + 1;
    }
    return uVar2;
  }
  if (param_3 == 1) {
    uVar2 = (uint)(param_1 + 1) & 3;
    uVar1 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
    if (uVar1 >> uVar2 * 8 == 0 && uVar1 << uVar2 * -8 + 0x20 == 0) {
      *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                 *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) - 1;
    }
    else {
      param_1[1] = 0;
    }
    return param_2;
  }
  if (param_3 == 2) {
    uVar2 = (uint)(param_1 + 1) & 3;
    uVar1 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
    return uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  }
  return 0;
}

