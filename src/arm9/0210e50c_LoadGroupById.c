/* Decompiled C draft; module arm9; ROM address 0210e50c. No matching claim. */
#include "types.h"
#include "deps/0210e50c_LoadGroupById.h"

void LoadGroupById(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0210e518. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0210e520)(param_1,*(uint *)(uRam0210e51c & 0xfffffffc) >> (uRam0210e51c & 3) * 8 |
                           *(uint *)(uRam0210e51c & 0xfffffffc) << (uRam0210e51c & 3) * -8 + 0x20);
  return;
}

