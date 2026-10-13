/* Decompiled C draft; module arm9; ROM address 0209e938. No matching claim. */
#include "types.h"
#include "deps/0209e938_Maybe_get_17b190.h"

void Maybe_get_17b190(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0209e944. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0209e94c)(param_1,*(uint *)(uRam0209e948 & 0xfffffffc) >> (uRam0209e948 & 3) * 8 |
                           *(uint *)(uRam0209e948 & 0xfffffffc) << (uRam0209e948 & 3) * -8 + 0x20);
  return;
}

