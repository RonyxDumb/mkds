/* Decompiled C draft; module arm9; ROM address 020a2314. No matching claim. */
#include "types.h"
#include "deps/020a2314_func_020a2314.h"

void func_020a2314(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam020a2324 & 0xfffffffc) >> (uRam020a2324 & 3) * 8 |
    *(uint *)(uRam020a2324 & 0xfffffffc) << (uRam020a2324 & 3) * -8 + 0x20) + 0x390) = param_1;
  return;
}

