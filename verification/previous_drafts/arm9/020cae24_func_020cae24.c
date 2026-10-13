/* Decompiled C draft; module arm9; ROM address 020cae24. No matching claim. */
#include "types.h"
#include "deps/020cae24_func_020cae24.h"

void func_020cae24(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam020cae34 & 0xfffffffc) >> (uRam020cae34 & 3) * 8 |
    *(uint *)(uRam020cae34 & 0xfffffffc) << (uRam020cae34 & 3) * -8 + 0x20) + 0x74) = param_1;
  return;
}

