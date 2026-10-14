/* Decompiled C draft; module arm9; ROM address 020e3724. No matching claim. */
#include "types.h"
#include "deps/020e3724_Maybe_get_17b7b8.h"

void Maybe_get_17b7b8(void)

{
                    /* WARNING: Could not recover jumptable at 0x020e3730. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020e3738)(*(uint *)(uRam020e3734 & 0xfffffffc) >> (uRam020e3734 & 3) * 8 |
                   *(uint *)(uRam020e3734 & 0xfffffffc) << (uRam020e3734 & 3) * -8 + 0x20);
  return;
}

