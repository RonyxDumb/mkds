/* Decompiled C draft; module arm9; ROM address 020a2350. No matching claim. */
#include "types.h"
#include "deps/020a2350_func_020a2350.h"

void func_020a2350(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam020a2360 & 0xfffffffc) >> (uRam020a2360 & 3) * 8 |
    *(uint *)(uRam020a2360 & 0xfffffffc) << (uRam020a2360 & 3) * -8 + 0x20) + 900) = param_1;
  return;
}

