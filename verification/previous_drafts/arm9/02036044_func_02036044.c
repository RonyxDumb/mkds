/* Decompiled C draft; module arm9; ROM address 02036044. No matching claim. */
#include "types.h"
#include "deps/02036044_func_02036044.h"

void func_02036044(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam02036054 & 0xfffffffc) >> (uRam02036054 & 3) * 8 |
    *(uint *)(uRam02036054 & 0xfffffffc) << (uRam02036054 & 3) * -8 + 0x20) + 8) = param_1;
  return;
}

