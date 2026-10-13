/* Decompiled C draft; module arm9; ROM address 0210a578. No matching claim. */
#include "types.h"
#include "deps/0210a578_func_0210a578.h"

uint func_0210a578(void)

{
  return *(uint *)(uRam0210a584 & 0xfffffffc) >> (uRam0210a584 & 3) * 8 |
         *(uint *)(uRam0210a584 & 0xfffffffc) << (uRam0210a584 & 3) * -8 + 0x20;
}

