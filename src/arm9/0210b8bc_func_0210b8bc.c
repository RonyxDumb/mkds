/* Decompiled C draft; module arm9; ROM address 0210b8bc. No matching claim. */
#include "types.h"
#include "deps/0210b8bc_func_0210b8bc.h"

void func_0210b8bc(undefined4 param_1,int param_2)

{
  param_2 = param_2 >> 0xc;
  if (0x1e < param_2) {
    param_2 = 0x1e;
  }
                    /* WARNING: Could not recover jumptable at 0x0210b8e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0210b8ec)(param_1,uRam0210b8f0,param_2 * 2 + 0x3cU & 0xff,(param_2 + -10) * 0x10000 >> 0x10
                  );
  return;
}

