/* Decompiled C draft; module arm9; ROM address 020d275c. No matching claim. */
#include "types.h"
#include "deps/020d275c_func_020d275c.h"

void func_020d275c(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x94U & 3;
  uVar2 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
                    /* WARNING: Could not recover jumptable at 0x020d276c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020d2770)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,param_2,0x7f,0);
  return;
}

