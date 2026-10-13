/* Decompiled C draft; module arm9; ROM address 0203a3b8. No matching claim. */
#include "types.h"
#include "deps/0203a3b8_SetNextRaceDisplayMode.h"

void SetNextRaceDisplayMode(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam0203a3c8 & 0xfffffffc) >> (uRam0203a3c8 & 3) * 8 |
    *(uint *)(uRam0203a3c8 & 0xfffffffc) << (uRam0203a3c8 & 3) * -8 + 0x20) + 500) = param_1;
  return;
}

