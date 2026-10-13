/* Decompiled C draft; module arm9; ROM address 02110100. No matching claim. */
#include "types.h"
#include "deps/02110100_func_02110100.h"

bool func_02110100(uint param_1)

{
  return *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 != 0 ||
         *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20 != 0;
}

