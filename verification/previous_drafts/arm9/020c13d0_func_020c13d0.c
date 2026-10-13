/* Decompiled C draft; module arm9; ROM address 020c13d0. No matching claim. */
#include "types.h"
#include "deps/020c13d0_func_020c13d0.h"

void func_020c13d0(void)

{
  *(undefined4 *)
   ((*(uint *)(uRam020c13e4 & 0xfffffffc) >> (uRam020c13e4 & 3) * 8 |
    *(uint *)(uRam020c13e4 & 0xfffffffc) << (uRam020c13e4 & 3) * -8 + 0x20) + 0xa4) = 0;
  return;
}

