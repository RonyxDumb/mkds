/* Decompiled C draft; module arm9_ov000; ROM address 02198b9c. No matching claim. */
#include "types.h"
#include "deps/02198b9c_FUN_02198b9c.h"

void FUN_02198b9c(undefined4 param_1,int param_2)

{
  *(undefined1 *)(param_2 + 2) = 0x67;
                    /* WARNING: Could not recover jumptable at 0x02198ba2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_02198ba4)();
  return;
}

