/* Decompiled C draft; module arm9; ROM address 020ad848. No matching claim. */
#include "types.h"
#include "deps/020ad848_SetB488SinglePlayerMenuTarget.h"

void SetB488SinglePlayerMenuTarget(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam020ad858 & 0xfffffffc) >> (uRam020ad858 & 3) * 8 |
    *(uint *)(uRam020ad858 & 0xfffffffc) << (uRam020ad858 & 3) * -8 + 0x20) + 8) = param_1;
  return;
}

