/* Decompiled C draft; module arm9; ROM address 020a2364. No matching claim. */
#include "types.h"
#include "deps/020a2364_func_020a2364.h"

void func_020a2364(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam020a2374 & 0xfffffffc) >> (uRam020a2374 & 3) * 8 |
    *(uint *)(uRam020a2374 & 0xfffffffc) << (uRam020a2374 & 3) * -8 + 0x20) + 0x380) = param_1;
  return;
}

