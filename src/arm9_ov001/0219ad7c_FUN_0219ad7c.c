/* Decompiled C draft; module arm9_ov001; ROM address 0219ad7c. No matching claim. */
#include "types.h"
#include "deps/0219ad7c_FUN_0219ad7c.h"

void FUN_0219ad7c(void)

{
  int *piVar1;
  
  piVar1 = DAT_0219ad90;
  *(undefined4 *)(*DAT_0219ad90 + 0x34) = 10;
  *(undefined4 *)(*piVar1 + 0x38) = 0;
                    /* WARNING: Could not recover jumptable at 0x0219ad8c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_0219ad94)();
  return;
}

