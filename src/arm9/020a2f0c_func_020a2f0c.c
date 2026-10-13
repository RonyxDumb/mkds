/* Decompiled C draft; module arm9; ROM address 020a2f0c. No matching claim. */
#include "types.h"
#include "deps/020a2f0c_func_020a2f0c.h"

void func_020a2f0c(int param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  *(undefined4 *)(param_1 + 0xa4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xf4) = 1;
  UNRECOVERED_JUMPTABLE = pcRam020a2f2c;
  *(undefined4 *)(param_1 + 0xf8) = 0;
                    /* WARNING: Could not recover jumptable at 0x020a2f28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

