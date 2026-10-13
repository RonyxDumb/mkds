/* Decompiled C draft; module arm9; ROM address 020ff638. No matching claim. */
#include "types.h"
#include "deps/020ff638_func_020ff638.h"

void func_020ff638(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_2 + 0x140U & 3;
  uVar2 = *(uint *)(param_2 + 0x140U & 0xfffffffc);
                    /* WARNING: Could not recover jumptable at 0x020ff64c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020ff650)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,(int)*(short *)(param_2 + 0xd8),
                   param_2 + 0x68);
  return;
}

