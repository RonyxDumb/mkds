/* Decompiled C draft; module arm9; ROM address 0209a5f8. No matching claim. */
#include "types.h"
#include "deps/0209a5f8_Maybe_get_17b140.h"

void Maybe_get_17b140(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0209a604. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0209a60c)(param_1,*(uint *)(uRam0209a608 & 0xfffffffc) >> (uRam0209a608 & 3) * 8 |
                           *(uint *)(uRam0209a608 & 0xfffffffc) << (uRam0209a608 & 3) * -8 + 0x20);
  return;
}

