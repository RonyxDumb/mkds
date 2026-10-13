/* Decompiled C draft; module arm9; ROM address 020d22c0. No matching claim. */
#include "types.h"
#include "deps/020d22c0_func_020d22c0.h"

uint func_020d22c0(void)

{
  return *(uint *)(uRam020d22cc & 0xfffffffc) >> (uRam020d22cc & 3) * 8 |
         *(uint *)(uRam020d22cc & 0xfffffffc) << (uRam020d22cc & 3) * -8 + 0x20;
}

