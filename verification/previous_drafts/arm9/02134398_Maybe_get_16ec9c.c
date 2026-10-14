/* Decompiled C draft; module arm9; ROM address 02134398. No matching claim. */
#include "types.h"
#include "deps/02134398_Maybe_get_16ec9c.h"

void Maybe_get_16ec9c(void)

{
                    /* WARNING: Could not recover jumptable at 0x021343a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam021343ac)(*(uint *)(uRam021343a8 & 0xfffffffc) >> (uRam021343a8 & 3) * 8 |
                   *(uint *)(uRam021343a8 & 0xfffffffc) << (uRam021343a8 & 3) * -8 + 0x20);
  return;
}

