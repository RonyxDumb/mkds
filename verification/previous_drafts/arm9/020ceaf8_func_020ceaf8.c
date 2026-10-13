/* Decompiled C draft; module arm9; ROM address 020ceaf8. No matching claim. */
#include "types.h"
#include "deps/020ceaf8_func_020ceaf8.h"

void func_020ceaf8(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam020ceb08 & 0xfffffffc) >> (uRam020ceb08 & 3) * 8 |
    *(uint *)(uRam020ceb08 & 0xfffffffc) << (uRam020ceb08 & 3) * -8 + 0x20) + 4) = param_1;
  return;
}

