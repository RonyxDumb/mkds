/* Decompiled C draft; module arm9; ROM address 0214f5e0. No matching claim. */
#include "types.h"
#include "deps/0214f5e0_func_0214f5e0.h"

void func_0214f5e0(int *param_1,int param_2)

{
  if (param_1 != (int *)0x0) {
    *(uint *)(param_2 + 8) =
         *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
         *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
    *param_1 = param_2;
  }
  return;
}

