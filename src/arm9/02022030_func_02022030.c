/* Decompiled C draft; module arm9; ROM address 02022030. No matching claim. */
#include "types.h"
#include "deps/02022030_func_02022030.h"

void func_02022030(int param_1,undefined4 param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = pcRam0202203c;
  *(undefined4 *)(param_1 + 0x18) = param_2;
                    /* WARNING: Could not recover jumptable at 0x02022038. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

