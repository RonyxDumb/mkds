/* Decompiled C draft; module arm9; ROM address 0210e328. No matching claim. */
#include "types.h"
#include "deps/0210e328_func_0210e328.h"

void func_0210e328(int param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = pcRam0210e338;
  *(undefined4 *)(param_1 + 4) = 0;
                    /* WARNING: Could not recover jumptable at 0x0210e334. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

