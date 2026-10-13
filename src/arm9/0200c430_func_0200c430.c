/* Decompiled C draft; module arm9; ROM address 0200c430. No matching claim. */
#include "types.h"
#include "deps/0200c430_func_0200c430.h"

void func_0200c430(undefined4 param_1)

{
  *puRam0200c43c = param_1;
                    /* WARNING: Could not recover jumptable at 0x0200c43a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0200c444)(param_1,0,uRam0200c440);
  return;
}

