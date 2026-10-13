/* Decompiled C draft; module arm9; ROM address 020a2328. No matching claim. */
#include "types.h"
#include "deps/020a2328_func_020a2328.h"

void func_020a2328(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam020a2338 & 0xfffffffc) >> (uRam020a2338 & 3) * 8 |
    *(uint *)(uRam020a2338 & 0xfffffffc) << (uRam020a2338 & 3) * -8 + 0x20) + 0x38c) = param_1;
  return;
}

