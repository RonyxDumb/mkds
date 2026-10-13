/* Decompiled C draft; module arm9; ROM address 020d22d0. No matching claim. */
#include "types.h"
#include "deps/020d22d0_func_020d22d0.h"

uint func_020d22d0(void)

{
  return *(uint *)(uRam020d22dc & 0xfffffffc) >> (uRam020d22dc & 3) * 8 |
         *(uint *)(uRam020d22dc & 0xfffffffc) << (uRam020d22dc & 3) * -8 + 0x20;
}

