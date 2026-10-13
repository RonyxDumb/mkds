/* Decompiled C draft; module arm9; ROM address 020ce894. No matching claim. */
#include "types.h"
#include "deps/020ce894_func_020ce894.h"

void func_020ce894(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam020ce8a4 & 0xfffffffc) >> (uRam020ce8a4 & 3) * 8 |
    *(uint *)(uRam020ce8a4 & 0xfffffffc) << (uRam020ce8a4 & 3) * -8 + 0x20) + 4) = param_1;
  return;
}

