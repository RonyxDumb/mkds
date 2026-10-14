/* Decompiled C draft; module arm9; ROM address 020db198. No matching claim. */
#include "types.h"
#include "deps/020db198_Maybe_get_17b688.h"

void Maybe_get_17b688(void)

{
                    /* WARNING: Could not recover jumptable at 0x020db1a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020db1ac)(*(uint *)(uRam020db1a8 & 0xfffffffc) >> (uRam020db1a8 & 3) * 8 |
                   *(uint *)(uRam020db1a8 & 0xfffffffc) << (uRam020db1a8 & 3) * -8 + 0x20);
  return;
}

