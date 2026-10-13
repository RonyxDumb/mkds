/* Decompiled C draft; module arm9; ROM address 021201e4. No matching claim. */
#include "types.h"
#include "deps/021201e4_GetWorstRankStarValue.h"

undefined1 GetWorstRankStarValue(int param_1)

{
  return *(undefined1 *)
          (param_1 * 0x244 +
           (*(uint *)(uRam021201fc & 0xfffffffc) >> (uRam021201fc & 3) * 8 |
           *(uint *)(uRam021201fc & 0xfffffffc) << (uRam021201fc & 3) * -8 + 0x20) + 0x451);
}

