/* Decompiled C draft; module arm9; ROM address 0206183c. No matching claim. */
#include "types.h"
#include "deps/0206183c_func_0206183c.h"

uint func_0206183c(void)

{
  return *(uint *)(uRam02061848 & 0xfffffffc) >> (uRam02061848 & 3) * 8 |
         *(uint *)(uRam02061848 & 0xfffffffc) << (uRam02061848 & 3) * -8 + 0x20;
}

