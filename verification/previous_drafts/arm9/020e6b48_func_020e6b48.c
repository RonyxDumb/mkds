/* Decompiled C draft; module arm9; ROM address 020e6b48. No matching claim. */
#include "types.h"
#include "deps/020e6b48_func_020e6b48.h"

uint func_020e6b48(void)

{
  return *(uint *)(uRam020e6b54 & 0xfffffffc) >> (uRam020e6b54 & 3) * 8 |
         *(uint *)(uRam020e6b54 & 0xfffffffc) << (uRam020e6b54 & 3) * -8 + 0x20;
}

