/* Decompiled C draft; module arm9; ROM address 020617f0. No matching claim. */
#include "types.h"
#include "deps/020617f0_func_020617f0.h"

void func_020617f0(void)

{
  *(undefined4 *)
   ((*(uint *)(uRam02061804 & 0xfffffffc) >> (uRam02061804 & 3) * 8 |
    *(uint *)(uRam02061804 & 0xfffffffc) << (uRam02061804 & 3) * -8 + 0x20) + 0x34) = 1;
  return;
}

