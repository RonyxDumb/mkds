/* Decompiled C draft; module arm7; ROM address 0600983c. No matching claim. */
#include "types.h"
#include "deps/0600983c_FUN_0600983c.h"

void FUN_0600983c(void)

{
                    /* WARNING: Could not recover jumptable at 0x06009850. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_0600985c)((*(uint *)(DAT_06009854 & 0xfffffffc) >> (DAT_06009854 & 3) * 8 |
                  *(uint *)(DAT_06009854 & 0xfffffffc) << (DAT_06009854 & 3) * -8 + 0x20) +
                  DAT_06009858);
  return;
}

