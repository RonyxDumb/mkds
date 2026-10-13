/* Decompiled C draft; module arm9_ov001; ROM address 02181c3c. No matching claim. */
#include "types.h"
#include "deps/02181c3c_FUN_02181c3c.h"

void FUN_02181c3c(undefined4 param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 + 0xf8);
  if (9 < uVar1) {
    uVar1 = FUN_02182536();
  }
                    /* WARNING: Could not recover jumptable at 0x02181c5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(&DAT_02181c5e + *(short *)(&DAT_02181c5e + uVar1 * 2)))();
  return;
}

