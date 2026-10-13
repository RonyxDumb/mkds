/* Decompiled C draft; module arm9; ROM address 020ceb0c. No matching claim. */
#include "types.h"
#include "deps/020ceb0c_func_020ceb0c.h"

void func_020ceb0c(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam020ceb1c & 0xfffffffc) >> (uRam020ceb1c & 3) * 8 |
    *(uint *)(uRam020ceb1c & 0xfffffffc) << (uRam020ceb1c & 3) * -8 + 0x20) + 8) = param_1;
  return;
}

