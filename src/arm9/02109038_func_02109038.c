/* Decompiled C draft; module arm9; ROM address 02109038. No matching claim. */
#include "types.h"
#include "deps/02109038_func_02109038.h"

void func_02109038(int param_1,undefined1 param_2,undefined4 param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = pcRam02109050;
  *(undefined1 *)(param_1 + 0x3c) = param_2;
  *(undefined4 *)(param_1 + 0x40) = 0xffffffff;
                    /* WARNING: Could not recover jumptable at 0x0210904c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,param_3);
  return;
}

