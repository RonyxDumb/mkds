/* Decompiled C draft; module arm9_ov001; ROM address 0219ad3c. No matching claim. */
#include "types.h"
#include "deps/0219ad3c_FUN_0219ad3c.h"

void FUN_0219ad3c(void)

{
  int *piVar1;
  
  piVar1 = DAT_0219ad5c;
  *(int *)(*DAT_0219ad5c + 0x40) = *(int *)(*DAT_0219ad5c + 0x40) + 1;
  if (2 < *(int *)(*piVar1 + 0x40)) {
    *(undefined4 *)(*piVar1 + 0x40) = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0219ad5a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_0219ad64)(DAT_0219ad60,0,0);
  return;
}

