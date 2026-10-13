/* Decompiled C draft; module arm9; ROM address 020e435c. No matching claim. */
#include "types.h"
#include "deps/020e435c_func_020e435c.h"

void func_020e435c(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020e4370. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020e4378)(*(uint *)(uRam020e4374 & 0xfffffffc) >> (uRam020e4374 & 3) * 8 |
                   *(uint *)(uRam020e4374 & 0xfffffffc) << (uRam020e4374 & 3) * -8 + 0x20,param_1,
                   uRam020e437c);
  return;
}

