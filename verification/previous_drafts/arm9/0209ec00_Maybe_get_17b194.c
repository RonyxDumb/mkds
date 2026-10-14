/* Decompiled C draft; module arm9; ROM address 0209ec00. No matching claim. */
#include "types.h"
#include "deps/0209ec00_Maybe_get_17b194.h"

void Maybe_get_17b194(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0209ec0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0209ec14)(param_1,*(uint *)(uRam0209ec10 & 0xfffffffc) >> (uRam0209ec10 & 3) * 8 |
                           *(uint *)(uRam0209ec10 & 0xfffffffc) << (uRam0209ec10 & 3) * -8 + 0x20);
  return;
}

