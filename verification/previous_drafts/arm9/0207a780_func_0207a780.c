/* Decompiled C draft; module arm9; ROM address 0207a780. No matching claim. */
#include "types.h"
#include "deps/0207a780_func_0207a780.h"

uint func_0207a780(void)

{
  return *(uint *)(uRam0207a78c & 0xfffffffc) >> (uRam0207a78c & 3) * 8 |
         *(uint *)(uRam0207a78c & 0xfffffffc) << (uRam0207a78c & 3) * -8 + 0x20;
}

