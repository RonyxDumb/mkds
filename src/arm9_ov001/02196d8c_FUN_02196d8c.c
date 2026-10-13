/* Decompiled C draft; module arm9_ov001; ROM address 02196d8c. No matching claim. */
#include "types.h"
#include "deps/02196d8c_FUN_02196d8c.h"

void FUN_02196d8c(void)

{
  int *piVar1;
  
  piVar1 = DAT_02196da0;
  *(undefined4 *)(*DAT_02196da0 + 0x54) = 0x10;
  *(undefined4 *)(*piVar1 + 0x58) = 0;
                    /* WARNING: Could not recover jumptable at 0x02196d9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_02196da4)();
  return;
}

