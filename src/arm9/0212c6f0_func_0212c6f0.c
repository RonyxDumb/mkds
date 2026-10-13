/* Decompiled C draft; module arm9; ROM address 0212c6f0. No matching claim. */
#include "types.h"
#include "deps/0212c6f0_func_0212c6f0.h"

void func_0212c6f0(uint param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0212c6f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0212c6fc)(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                   *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20);
  return;
}

