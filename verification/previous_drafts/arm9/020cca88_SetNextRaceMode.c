/* Decompiled C draft; module arm9; ROM address 020cca88. No matching claim. */
#include "types.h"
#include "deps/020cca88_SetNextRaceMode.h"

void SetNextRaceMode(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam020cca98 & 0xfffffffc) >> (uRam020cca98 & 3) * 8 |
    *(uint *)(uRam020cca98 & 0xfffffffc) << (uRam020cca98 & 3) * -8 + 0x20) + 0x1f0) = param_1;
  return;
}

