/* Decompiled C draft; module arm9; ROM address 02035e44. No matching claim. */
#include "types.h"
#include "deps/02035e44_func_02035e44.h"

bool func_02035e44(void)

{
  return *(char *)((*(uint *)(uRam02035e60 & 0xfffffffc) >> (uRam02035e60 & 3) * 8 |
                   *(uint *)(uRam02035e60 & 0xfffffffc) << (uRam02035e60 & 3) * -8 + 0x20) + 0x457)
         != '\0';
}

