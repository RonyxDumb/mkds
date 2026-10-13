/* Decompiled C draft; module arm9; ROM address 020298e0. No matching claim. */
#include "types.h"
#include "deps/020298e0_func_020298e0.h"

void func_020298e0(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam020298f0 & 0xfffffffc) >> (uRam020298f0 & 3) * 8 |
    *(uint *)(uRam020298f0 & 0xfffffffc) << (uRam020298f0 & 3) * -8 + 0x20) + 0x1f8) = param_1;
  return;
}

