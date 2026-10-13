/* Decompiled C draft; module arm9; ROM address 020e3b28. No matching claim. */
#include "types.h"
#include "deps/020e3b28_func_020e3b28.h"

void func_020e3b28(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020e3b3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020e3b44)(*(uint *)(uRam020e3b40 & 0xfffffffc) >> (uRam020e3b40 & 3) * 8 |
                   *(uint *)(uRam020e3b40 & 0xfffffffc) << (uRam020e3b40 & 3) * -8 + 0x20,param_1,
                   uRam020e3b48);
  return;
}

