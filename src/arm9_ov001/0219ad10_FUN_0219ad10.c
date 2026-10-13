/* Decompiled C draft; module arm9_ov001; ROM address 0219ad10. No matching claim. */
#include "types.h"
#include "deps/0219ad10_FUN_0219ad10.h"

void FUN_0219ad10(void)

{
  int *piVar1;
  
  piVar1 = DAT_0219ad30;
  *(int *)(*DAT_0219ad30 + 0x40) = *(int *)(*DAT_0219ad30 + 0x40) + -1;
  if (*(int *)(*piVar1 + 0x40) < 0) {
    *(undefined4 *)(*piVar1 + 0x40) = 2;
  }
                    /* WARNING: Could not recover jumptable at 0x0219ad2e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_0219ad38)(DAT_0219ad34,0,0);
  return;
}

