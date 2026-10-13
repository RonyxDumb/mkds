/* Decompiled C draft; module arm9; ROM address 02074888. No matching claim. */
#include "types.h"
#include "deps/02074888_func_02074888.h"

uint func_02074888(void)

{
  return *(uint *)(uRam02074894 & 0xfffffffc) >> (uRam02074894 & 3) * 8 |
         *(uint *)(uRam02074894 & 0xfffffffc) << (uRam02074894 & 3) * -8 + 0x20;
}

