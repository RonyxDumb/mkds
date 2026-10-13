/* Decompiled C draft; module arm9; ROM address 0205a534. No matching claim. */
#include "types.h"
#include "deps/0205a534_func_0205a534.h"

void func_0205a534(uint param_1)

{
  *(uint *)(param_1 + 4) =
       *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
       *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  *(undefined2 *)(param_1 + 0xc) = 4;
  return;
}

