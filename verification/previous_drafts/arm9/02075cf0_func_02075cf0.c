/* Decompiled C draft; module arm9; ROM address 02075cf0. No matching claim. */
#include "types.h"
#include "deps/02075cf0_func_02075cf0.h"

void func_02075cf0(void)

{
  *(undefined4 *)
   ((*(uint *)(uRam02075d04 & 0xfffffffc) >> (uRam02075d04 & 3) * 8 |
    *(uint *)(uRam02075d04 & 0xfffffffc) << (uRam02075d04 & 3) * -8 + 0x20) + 0x234) = 1;
  return;
}

