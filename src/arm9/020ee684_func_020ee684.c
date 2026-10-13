/* Decompiled C draft; module arm9; ROM address 020ee684. No matching claim. */
#include "types.h"
#include "deps/020ee684_func_020ee684.h"

void func_020ee684(int param_1,int param_2)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  uint uVar2;
  
  *(int *)(param_1 + 0xc) = param_2;
  uVar1 = param_2 + 0x1fcU & 3;
  uVar2 = *(uint *)(param_2 + 0x1fcU & 0xfffffffc);
  *(uint *)(param_1 + 0x10) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  UNRECOVERED_JUMPTABLE = pcRam020ee6a4;
  *(undefined2 *)(param_1 + 0x28) = *(undefined2 *)(param_2 + 0x1f8);
                    /* WARNING: Could not recover jumptable at 0x020ee6a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

