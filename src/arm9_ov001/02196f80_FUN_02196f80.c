/* Decompiled C draft; module arm9_ov001; ROM address 02196f80. No matching claim. */
#include "types.h"
#include "deps/02196f80_FUN_02196f80.h"

void FUN_02196f80(void)

{
  int *piVar1;
  
  piVar1 = DAT_02196fa0;
  *(undefined4 *)(*DAT_02196fa0 + 0x54) = 7;
  *(undefined4 *)(*piVar1 + 0x58) = 0;
  *(undefined4 *)(*(int *)(*piVar1 + 0x3c) + DAT_02196fa4) = 1;
                    /* WARNING: Could not recover jumptable at 0x02196f9e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_02196fac)(DAT_02196fa8,0,4);
  return;
}

