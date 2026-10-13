/* Decompiled C draft; module arm9; ROM address 0214f1a0. No matching claim. */
#include "types.h"
#include "deps/0214f1a0_func_0214f1a0.h"

uint func_0214f1a0(void)

{
  return *(uint *)(uRam0214f1ac & 0xfffffffc) >> (uRam0214f1ac & 3) * 8 |
         *(uint *)(uRam0214f1ac & 0xfffffffc) << (uRam0214f1ac & 3) * -8 + 0x20;
}

