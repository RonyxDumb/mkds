/* Decompiled C draft; module arm9; ROM address 0210dcb8. No matching claim. */
#include "types.h"
#include "deps/0210dcb8_func_0210dcb8.h"

void func_0210dcb8(uint param_1,undefined4 param_2)

{
                    /* WARNING: Could not recover jumptable at 0x0210dcc4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0210dcc8)(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                   *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20,param_2,
                   param_1 + 0xc);
  return;
}

