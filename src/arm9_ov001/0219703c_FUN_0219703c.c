/* Decompiled C draft; module arm9_ov001; ROM address 0219703c. No matching claim. */
#include "types.h"
#include "deps/0219703c_FUN_0219703c.h"

void FUN_0219703c(void)

{
  int *piVar1;
  
  piVar1 = DAT_02197050;
  *(undefined4 *)(*DAT_02197050 + 0x54) = 1;
  *(undefined4 *)(*piVar1 + 0x58) = 0;
                    /* WARNING: Could not recover jumptable at 0x0219704c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_02197054)();
  return;
}

