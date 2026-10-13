/* Decompiled C draft; module arm9_ov001; ROM address 02196f64. No matching claim. */
#include "types.h"
#include "deps/02196f64_FUN_02196f64.h"

void FUN_02196f64(void)

{
  int *piVar1;
  
  piVar1 = DAT_02196f78;
  *(undefined4 *)(*DAT_02196f78 + 0x54) = 8;
  *(undefined4 *)(*piVar1 + 0x58) = 0;
                    /* WARNING: Could not recover jumptable at 0x02196f74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_02196f7c)();
  return;
}

