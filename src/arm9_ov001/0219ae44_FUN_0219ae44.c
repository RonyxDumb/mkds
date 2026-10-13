/* Decompiled C draft; module arm9_ov001; ROM address 0219ae44. No matching claim. */
#include "types.h"
#include "deps/0219ae44_FUN_0219ae44.h"

void FUN_0219ae44(void)

{
  int *piVar1;
  
  piVar1 = DAT_0219ae58;
  *(undefined4 *)(*DAT_0219ae58 + 0x34) = 3;
  *(undefined4 *)(*piVar1 + 0x38) = 0;
                    /* WARNING: Could not recover jumptable at 0x0219ae54. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_0219ae5c)();
  return;
}

