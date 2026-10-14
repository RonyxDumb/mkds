/* Decompiled C draft; module arm9; ROM address 020d4104. No matching claim. */
#include "types.h"
#include "deps/020d4104_func_020d4104.h"

int func_020d4104(int param_1)

{
  return param_1 * 0xc +
         (*(uint *)(uRam020d4118 & 0xfffffffc) >> (uRam020d4118 & 3) * 8 |
         *(uint *)(uRam020d4118 & 0xfffffffc) << (uRam020d4118 & 3) * -8 + 0x20);
}

