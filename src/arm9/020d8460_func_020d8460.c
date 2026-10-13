/* Decompiled C draft; module arm9; ROM address 020d8460. No matching claim. */
#include "types.h"
#include "deps/020d8460_func_020d8460.h"

void func_020d8460(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x5cU & 3;
  uVar2 = *(uint *)(param_1 + 0x5cU & 0xfffffffc);
                    /* WARNING: Could not recover jumptable at 0x020d846c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020d8470)(param_1,uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,param_2);
  return;
}

