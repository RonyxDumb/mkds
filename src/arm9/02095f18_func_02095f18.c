/* Decompiled C draft; module arm9; ROM address 02095f18. No matching claim. */
#include "types.h"
#include "deps/02095f18_func_02095f18.h"

void func_02095f18(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x9cU & 3;
  uVar2 = *(uint *)(param_1 + 0x9cU & 0xfffffffc);
                    /* WARNING: Could not recover jumptable at 0x02095f28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02095f2c)(param_1 + 0xb4,uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,0);
  return;
}

