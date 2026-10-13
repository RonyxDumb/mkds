/* Decompiled C draft; module arm9; ROM address 02036058. No matching claim. */
#include "types.h"
#include "deps/02036058_func_02036058.h"

void func_02036058(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam02036068 & 0xfffffffc) >> (uRam02036068 & 3) * 8 |
    *(uint *)(uRam02036068 & 0xfffffffc) << (uRam02036068 & 3) * -8 + 0x20) + 4) = param_1;
  return;
}

