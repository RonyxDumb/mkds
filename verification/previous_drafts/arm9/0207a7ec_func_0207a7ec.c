/* Decompiled C draft; module arm9; ROM address 0207a7ec. No matching claim. */
#include "types.h"
#include "deps/0207a7ec_func_0207a7ec.h"

uint func_0207a7ec(void)

{
  return *(uint *)(uRam0207a7f8 & 0xfffffffc) >> (uRam0207a7f8 & 3) * 8 |
         *(uint *)(uRam0207a7f8 & 0xfffffffc) << (uRam0207a7f8 & 3) * -8 + 0x20;
}

