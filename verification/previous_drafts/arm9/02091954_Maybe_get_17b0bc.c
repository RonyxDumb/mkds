/* Decompiled C draft; module arm9; ROM address 02091954. No matching claim. */
#include "types.h"
#include "deps/02091954_Maybe_get_17b0bc.h"

void Maybe_get_17b0bc(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x02091960. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02091968)(param_1,*(uint *)(uRam02091964 & 0xfffffffc) >> (uRam02091964 & 3) * 8 |
                           *(uint *)(uRam02091964 & 0xfffffffc) << (uRam02091964 & 3) * -8 + 0x20);
  return;
}

