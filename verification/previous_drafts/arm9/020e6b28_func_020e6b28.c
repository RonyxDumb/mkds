/* Decompiled C draft; module arm9; ROM address 020e6b28. No matching claim. */
#include "types.h"
#include "deps/020e6b28_func_020e6b28.h"

uint func_020e6b28(void)

{
  return *(uint *)(uRam020e6b34 & 0xfffffffc) >> (uRam020e6b34 & 3) * 8 |
         *(uint *)(uRam020e6b34 & 0xfffffffc) << (uRam020e6b34 & 3) * -8 + 0x20;
}

