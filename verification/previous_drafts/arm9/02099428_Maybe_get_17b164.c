/* Decompiled C draft; module arm9; ROM address 02099428. No matching claim. */
#include "types.h"
#include "deps/02099428_Maybe_get_17b164.h"

void Maybe_get_17b164(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x02099434. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0209943c)(param_1,*(uint *)(uRam02099438 & 0xfffffffc) >> (uRam02099438 & 3) * 8 |
                           *(uint *)(uRam02099438 & 0xfffffffc) << (uRam02099438 & 3) * -8 + 0x20);
  return;
}

