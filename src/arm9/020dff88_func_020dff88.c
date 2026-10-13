/* Decompiled C draft; module arm9; ROM address 020dff88. No matching claim. */
#include "types.h"
#include "deps/020dff88_func_020dff88.h"

void func_020dff88(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020dff9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020dffa4)(*(uint *)(uRam020dffa0 & 0xfffffffc) >> (uRam020dffa0 & 3) * 8 |
                   *(uint *)(uRam020dffa0 & 0xfffffffc) << (uRam020dffa0 & 3) * -8 + 0x20,param_1,
                   uRam020dffa8);
  return;
}

