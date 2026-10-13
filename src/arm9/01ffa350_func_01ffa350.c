/* Decompiled C draft; module arm9; ROM address 01ffa350. No matching claim. */
#include "types.h"
#include "deps/01ffa350_func_01ffa350.h"

void func_01ffa350(int param_1,uint param_2)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  uint uVar2;
  
  uVar1 = param_1 + 0x44U & 3;
  uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  *(uint *)(param_1 + 0x44) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & ~param_2;
  uVar1 = param_1 + 0x208U & 3;
  uVar2 = *(uint *)(param_1 + 0x208U & 0xfffffffc);
  *(undefined4 *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) = 0;
  UNRECOVERED_JUMPTABLE = DAT_01ffa37c;
  *(undefined4 *)(param_1 + 0x3dc) = 0xffffffff;
                    /* WARNING: Could not recover jumptable at 0x01ffa378. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

