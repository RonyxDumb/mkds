/* Decompiled C draft; module arm9; ROM address 0210008c. No matching claim. */
#include "types.h"
#include "deps/0210008c_func_0210008c.h"

uint func_0210008c(uint param_1)

{
  return *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
         *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
}

