/* Decompiled C draft; module arm9; ROM address 020a2300. No matching claim. */
#include "types.h"
#include "deps/020a2300_func_020a2300.h"

void func_020a2300(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam020a2310 & 0xfffffffc) >> (uRam020a2310 & 3) * 8 |
    *(uint *)(uRam020a2310 & 0xfffffffc) << (uRam020a2310 & 3) * -8 + 0x20) + 0x39c) = param_1;
  return;
}

