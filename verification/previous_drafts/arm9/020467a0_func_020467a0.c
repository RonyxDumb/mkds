/* Decompiled C draft; module arm9; ROM address 020467a0. No matching claim. */
#include "types.h"
#include "deps/020467a0_func_020467a0.h"

void func_020467a0(void)

{
  CreateGlobalLU();
  *(undefined2 *)
   ((*(uint *)(uRam020467cc & 0xfffffffc) >> (uRam020467cc & 3) * 8 |
    *(uint *)(uRam020467cc & 0xfffffffc) << (uRam020467cc & 3) * -8 + 0x20) + 0x248) = 1;
  return;
}

