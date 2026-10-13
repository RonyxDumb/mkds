/* Decompiled C draft; module arm9; ROM address 020cbabc. No matching claim. */
#include "types.h"
#include "deps/020cbabc_SetSinglePlayerMenuTarget.h"

void SetSinglePlayerMenuTarget(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam020cbacc & 0xfffffffc) >> (uRam020cbacc & 3) * 8 |
    *(uint *)(uRam020cbacc & 0xfffffffc) << (uRam020cbacc & 3) * -8 + 0x20) + 8) = param_1;
  return;
}

