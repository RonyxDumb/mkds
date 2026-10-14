/* Decompiled C draft; module arm9; ROM address 020a0ff0. No matching claim. */
#include "types.h"
#include "deps/020a0ff0_func_020a0ff0.h"

int func_020a0ff0(int param_1)

{
  return param_1 * 0x70 +
         (*(uint *)(uRam020a1008 & 0xfffffffc) >> (uRam020a1008 & 3) * 8 |
         *(uint *)(uRam020a1008 & 0xfffffffc) << (uRam020a1008 & 3) * -8 + 0x20) + 0xc;
}

