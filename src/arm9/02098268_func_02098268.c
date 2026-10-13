/* Decompiled C draft; module arm9; ROM address 02098268. No matching claim. */
#include "types.h"
#include "deps/02098268_func_02098268.h"

void func_02098268(int param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = pcRam02098288;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam02098284;
                    /* WARNING: Could not recover jumptable at 0x02098280. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

