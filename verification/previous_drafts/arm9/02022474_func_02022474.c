/* Decompiled C draft; module arm9; ROM address 02022474. No matching claim. */
#include "types.h"
#include "deps/02022474_func_02022474.h"

void func_02022474(undefined4 *param_1,undefined4 param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = pcRam02022480;
  *param_1 = param_2;
                    /* WARNING: Could not recover jumptable at 0x0202247c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

