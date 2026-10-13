/* Decompiled C draft; module arm9; ROM address 0212c450. No matching claim. */
#include "types.h"
#include "deps/0212c450_func_0212c450.h"

void func_0212c450(uint param_1,undefined2 param_2,undefined2 param_3)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  if (uVar1 == 0) {
    return;
  }
  *(undefined2 *)(uVar1 + 0x34) = 2;
  *(undefined2 *)
   ((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
    *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0x38) = param_2;
  *(undefined2 *)
   ((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
    *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0x3a) = param_3;
  return;
}

