/* Decompiled C draft; module arm9; ROM address 020a238c. No matching claim. */
#include "types.h"
#include "deps/020a238c_func_020a238c.h"

void func_020a238c(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam020a239c & 0xfffffffc) >> (uRam020a239c & 3) * 8 |
    *(uint *)(uRam020a239c & 0xfffffffc) << (uRam020a239c & 3) * -8 + 0x20) + 0x3bc) = param_1;
  return;
}

