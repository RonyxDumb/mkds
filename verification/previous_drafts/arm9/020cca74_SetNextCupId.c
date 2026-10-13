/* Decompiled C draft; module arm9; ROM address 020cca74. No matching claim. */
#include "types.h"
#include "deps/020cca74_SetNextCupId.h"

void SetNextCupId(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam020cca84 & 0xfffffffc) >> (uRam020cca84 & 3) * 8 |
    *(uint *)(uRam020cca84 & 0xfffffffc) << (uRam020cca84 & 3) * -8 + 0x20) + 0x1ec) = param_1;
  return;
}

