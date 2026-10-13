/* Decompiled C draft; module arm7; ROM address 060099bc. No matching claim. */
#include "types.h"
#include "deps/060099bc_FUN_060099bc.h"

void FUN_060099bc(void)

{
                    /* WARNING: Could not recover jumptable at 0x060099d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_060099dc)((*(uint *)(DAT_060099d4 & 0xfffffffc) >> (DAT_060099d4 & 3) * 8 |
                  *(uint *)(DAT_060099d4 & 0xfffffffc) << (DAT_060099d4 & 3) * -8 + 0x20) +
                  DAT_060099d8);
  return;
}

