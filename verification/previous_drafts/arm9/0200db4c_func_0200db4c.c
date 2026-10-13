/* Decompiled C draft; module arm9; ROM address 0200db4c. No matching claim. */
#include "types.h"
#include "deps/0200db4c_func_0200db4c.h"

uint func_0200db4c(void)

{
  return *(uint *)(uRam0200db58 & 0xfffffffc) >> (uRam0200db58 & 3) * 8 |
         *(uint *)(uRam0200db58 & 0xfffffffc) << (uRam0200db58 & 3) * -8 + 0x20;
}

