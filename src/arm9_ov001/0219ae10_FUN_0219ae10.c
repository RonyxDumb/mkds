/* Decompiled C draft; module arm9_ov001; ROM address 0219ae10. No matching claim. */
#include "types.h"
#include "deps/0219ae10_FUN_0219ae10.h"

void FUN_0219ae10(void)

{
  int *piVar1;
  
  piVar1 = DAT_0219ae24;
  *(undefined4 *)(*DAT_0219ae24 + 0x34) = 5;
  *(undefined4 *)(*piVar1 + 0x38) = 0;
                    /* WARNING: Could not recover jumptable at 0x0219ae22. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_0219ae2c)(DAT_0219ae28);
  return;
}

