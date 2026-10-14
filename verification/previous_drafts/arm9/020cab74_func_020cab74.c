/* Decompiled C draft; module arm9; ROM address 020cab74. No matching claim. */
#include "types.h"
#include "deps/020cab74_func_020cab74.h"

uint func_020cab74(void)

{
  return ((*(uint *)(uRam020cab88 & 0xfffffffc) >> (uRam020cab88 & 3) * 8 |
          *(uint *)(uRam020cab88 & 0xfffffffc) << (uRam020cab88 & 3) * -8 + 0x20) & 0x1f00) >> 8;
}

