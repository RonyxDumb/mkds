/* Decompiled C draft; module arm9; ROM address 020c0b84. No matching claim. */
#include "types.h"
#include "deps/020c0b84_func_020c0b84.h"

void func_020c0b84(undefined4 *param_1)

{
  *(undefined4 *)
   (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
   *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
    *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 0xc) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
    *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 0x10) = 0;
  *param_1 = 0;
  return;
}

