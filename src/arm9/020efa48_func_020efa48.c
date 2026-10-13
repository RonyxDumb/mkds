/* Decompiled C draft; module arm9; ROM address 020efa48. No matching claim. */
#include "types.h"
#include "deps/020efa48_func_020efa48.h"

void func_020efa48(int param_1)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  uint uVar2;
  
  UNRECOVERED_JUMPTABLE = pcRam020efa5c;
  uVar1 = param_1 + 0x20U & 3;
  uVar2 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  *(uint *)(param_1 + 0x20) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) - 1;
                    /* WARNING: Could not recover jumptable at 0x020efa58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

