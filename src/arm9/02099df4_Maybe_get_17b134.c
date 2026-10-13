/* Decompiled C draft; module arm9; ROM address 02099df4. No matching claim. */
#include "types.h"
#include "deps/02099df4_Maybe_get_17b134.h"

void Maybe_get_17b134(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x02099e00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02099e08)(param_1,*(uint *)(uRam02099e04 & 0xfffffffc) >> (uRam02099e04 & 3) * 8 |
                           *(uint *)(uRam02099e04 & 0xfffffffc) << (uRam02099e04 & 3) * -8 + 0x20);
  return;
}

