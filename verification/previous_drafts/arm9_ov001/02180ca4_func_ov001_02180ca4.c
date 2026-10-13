/* Decompiled C draft; module arm9_ov001; ROM address 02180ca4. No matching claim. */
#include "types.h"
#include "deps/02180ca4_func_ov001_02180ca4.h"

uint func_ov001_02180ca4(void)

{
  return *(uint *)(uRam02180cb0 & 0xfffffffc) >> (uRam02180cb0 & 3) * 8 |
         *(uint *)(uRam02180cb0 & 0xfffffffc) << (uRam02180cb0 & 3) * -8 + 0x20;
}

