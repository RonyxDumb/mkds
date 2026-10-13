/* Decompiled C draft; module arm9; ROM address 02100084. No matching claim. */
#include "types.h"
#include "deps/02100084_func_02100084.h"

uint func_02100084(uint param_1)

{
  return *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
         *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
}

