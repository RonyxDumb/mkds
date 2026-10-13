/* Decompiled C draft; module arm9; ROM address 020a3f18. No matching claim. */
#include "types.h"
#include "deps/020a3f18_func_020a3f18.h"

void func_020a3f18(int param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = pcRam020a3f28;
  *(undefined4 *)(param_1 + 0xa4) = 0xffffffff;
                    /* WARNING: Could not recover jumptable at 0x020a3f24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

