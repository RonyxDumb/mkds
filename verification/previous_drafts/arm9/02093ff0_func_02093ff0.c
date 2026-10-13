/* Decompiled C draft; module arm9; ROM address 02093ff0. No matching claim. */
#include "types.h"
#include "deps/02093ff0_func_02093ff0.h"

uint func_02093ff0(void)

{
  return *(uint *)(uRam02093ffc & 0xfffffffc) >> (uRam02093ffc & 3) * 8 |
         *(uint *)(uRam02093ffc & 0xfffffffc) << (uRam02093ffc & 3) * -8 + 0x20;
}

