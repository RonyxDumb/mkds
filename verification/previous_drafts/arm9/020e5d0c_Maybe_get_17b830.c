/* Decompiled C draft; module arm9; ROM address 020e5d0c. No matching claim. */
#include "types.h"
#include "deps/020e5d0c_Maybe_get_17b830.h"

void Maybe_get_17b830(void)

{
                    /* WARNING: Could not recover jumptable at 0x020e5d18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020e5d20)(*(uint *)(uRam020e5d1c & 0xfffffffc) >> (uRam020e5d1c & 3) * 8 |
                   *(uint *)(uRam020e5d1c & 0xfffffffc) << (uRam020e5d1c & 3) * -8 + 0x20);
  return;
}

