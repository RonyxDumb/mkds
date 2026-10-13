/* Decompiled C draft; module arm9; ROM address 020ff1b8. No matching claim. */
#include "types.h"
#include "deps/020ff1b8_func_020ff1b8.h"

void func_020ff1b8(int param_1,uint *param_2)

{
  if (param_1 == 0) {
    *param_2 = (*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
               *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20) &
               0xfffffdff;
  }
  else {
    *param_2 = *(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
               *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20 | 0x200;
  }
  return;
}

