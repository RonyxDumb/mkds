/* Decompiled C draft; module arm9; ROM address 020df220. No matching claim. */
#include "types.h"
#include "deps/020df220_Maybe_get_17b71c.h"

void Maybe_get_17b71c(void)

{
                    /* WARNING: Could not recover jumptable at 0x020df22c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020df234)(*(uint *)(uRam020df230 & 0xfffffffc) >> (uRam020df230 & 3) * 8 |
                   *(uint *)(uRam020df230 & 0xfffffffc) << (uRam020df230 & 3) * -8 + 0x20);
  return;
}

