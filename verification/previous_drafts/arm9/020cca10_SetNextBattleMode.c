/* Decompiled C draft; module arm9; ROM address 020cca10. No matching claim. */
#include "types.h"
#include "deps/020cca10_SetNextBattleMode.h"

void SetNextBattleMode(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam020cca20 & 0xfffffffc) >> (uRam020cca20 & 3) * 8 |
    *(uint *)(uRam020cca20 & 0xfffffffc) << (uRam020cca20 & 3) * -8 + 0x20) + 0x200) = param_1;
  return;
}

