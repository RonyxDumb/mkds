/* Decompiled C draft; module arm9_ov001; ROM address 0219ad98. No matching claim. */
#include "types.h"
#include "deps/0219ad98_FUN_0219ad98.h"

void FUN_0219ad98(void)

{
  int *piVar1;
  
  piVar1 = DAT_0219adb0;
  *(undefined4 *)(*DAT_0219adb0 + 0x34) = 9;
  *(undefined4 *)(*piVar1 + 0x38) = 0;
                    /* WARNING: Could not recover jumptable at 0x0219adac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_0219adb8)(DAT_0219adb4,0,0x15);
  return;
}

