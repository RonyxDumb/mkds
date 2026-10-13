/* Decompiled C draft; module arm9; ROM address 020e6b38. No matching claim. */
#include "types.h"
#include "deps/020e6b38_func_020e6b38.h"

uint func_020e6b38(void)

{
  return *(uint *)(uRam020e6b44 & 0xfffffffc) >> (uRam020e6b44 & 3) * 8 |
         *(uint *)(uRam020e6b44 & 0xfffffffc) << (uRam020e6b44 & 3) * -8 + 0x20;
}

