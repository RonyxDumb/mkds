/* Decompiled C draft; module arm9; ROM address 0212c478. No matching claim. */
#include "types.h"
#include "deps/0212c478_func_0212c478.h"

void func_0212c478(uint param_1,undefined2 param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  if (uVar1 != 0) {
    *(undefined2 *)(uVar1 + 0x34) = 1;
    *(undefined2 *)
     ((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
      *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0x38) = param_2;
  }
  return;
}

