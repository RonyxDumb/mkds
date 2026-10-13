/* Decompiled C draft; module arm9; ROM address 0210dc50. No matching claim. */
#include "types.h"
#include "deps/0210dc50_func_0210dc50.h"

void func_0210dc50(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 8U & 3;
  uVar2 = *(uint *)(param_1 + 8U & 0xfffffffc);
                    /* WARNING: Could not recover jumptable at 0x0210dc58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0210dc5c)(param_1,uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  return;
}

