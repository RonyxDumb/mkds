/* Decompiled C draft; module arm9; ROM address 0210f858. No matching claim. */
#include "types.h"
#include "deps/0210f858_func_0210f858.h"

uint func_0210f858(void)

{
  return *(uint *)(uRam0210f864 & 0xfffffffc) >> (uRam0210f864 & 3) * 8 |
         *(uint *)(uRam0210f864 & 0xfffffffc) << (uRam0210f864 & 3) * -8 + 0x20;
}

