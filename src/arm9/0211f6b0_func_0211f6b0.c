/* Decompiled C draft; module arm9; ROM address 0211f6b0. No matching claim. */
#include "types.h"
#include "deps/0211f6b0_func_0211f6b0.h"

void func_0211f6b0(void)

{
  *(undefined4 *)
   ((*(uint *)(uRam0211f6c8 & 0xfffffffc) >> (uRam0211f6c8 & 3) * 8 |
    *(uint *)(uRam0211f6c8 & 0xfffffffc) << (uRam0211f6c8 & 3) * -8 + 0x20) + 0x1cfc) = 1;
  return;
}

