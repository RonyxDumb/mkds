/* Decompiled C draft; module arm9; ROM address 020df064. No matching claim. */
#include "types.h"
#include "deps/020df064_Maybe_get_17b710.h"

void Maybe_get_17b710(void)

{
                    /* WARNING: Could not recover jumptable at 0x020df070. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020df078)(*(uint *)(uRam020df074 & 0xfffffffc) >> (uRam020df074 & 3) * 8 |
                   *(uint *)(uRam020df074 & 0xfffffffc) << (uRam020df074 & 3) * -8 + 0x20);
  return;
}

