/* Decompiled C draft; module arm9; ROM address 02074854. No matching claim. */
#include "types.h"
#include "deps/02074854_func_02074854.h"

void func_02074854(void)

{
  *(uint *)((*(uint *)(uRam02074870 & 0xfffffffc) >> (uRam02074870 & 3) * 8 |
            *(uint *)(uRam02074870 & 0xfffffffc) << (uRam02074870 & 3) * -8 + 0x20) + 100) =
       (uint)*puRam0207486c;
  return;
}

