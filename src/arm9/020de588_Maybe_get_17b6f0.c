/* Decompiled C draft; module arm9; ROM address 020de588. No matching claim. */
#include "types.h"
#include "deps/020de588_Maybe_get_17b6f0.h"

void Maybe_get_17b6f0(void)

{
                    /* WARNING: Could not recover jumptable at 0x020de594. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020de59c)(*(uint *)(uRam020de598 & 0xfffffffc) >> (uRam020de598 & 3) * 8 |
                   *(uint *)(uRam020de598 & 0xfffffffc) << (uRam020de598 & 3) * -8 + 0x20);
  return;
}

