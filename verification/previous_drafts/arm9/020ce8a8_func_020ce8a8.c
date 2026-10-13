/* Decompiled C draft; module arm9; ROM address 020ce8a8. No matching claim. */
#include "types.h"
#include "deps/020ce8a8_func_020ce8a8.h"

void func_020ce8a8(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam020ce8b8 & 0xfffffffc) >> (uRam020ce8b8 & 3) * 8 |
    *(uint *)(uRam020ce8b8 & 0xfffffffc) << (uRam020ce8b8 & 3) * -8 + 0x20) + 8) = param_1;
  return;
}

