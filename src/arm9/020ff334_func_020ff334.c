/* Decompiled C draft; module arm9; ROM address 020ff334. No matching claim. */
#include "types.h"
#include "deps/020ff334_func_020ff334.h"

void func_020ff334(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x140U & 3;
  uVar2 = *(uint *)(param_1 + 0x140U & 0xfffffffc);
                    /* WARNING: Could not recover jumptable at 0x020ff33c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020ff340)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  return;
}

