/* Decompiled C draft; module arm9_ov001; ROM address 021a04c0. No matching claim. */
#include "types.h"
#include "deps/021a04c0_FUN_021a04c0.h"

void FUN_021a04c0(void)

{
  int *piVar1;
  
  piVar1 = DAT_021a04d4;
  *(undefined4 *)(*DAT_021a04d4 + 100) = 2;
  *(undefined4 *)(*piVar1 + 0x68) = 0;
                    /* WARNING: Could not recover jumptable at 0x021a04d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_021a04d8)();
  return;
}

