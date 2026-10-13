/* Decompiled C draft; module arm9_ov001; ROM address 02194a34. No matching claim. */
#include "types.h"
#include "deps/02194a34_FUN_02194a34.h"

void FUN_02194a34(void)

{
  int *piVar1;
  
  piVar1 = DAT_02194a48;
  *(undefined4 *)(*DAT_02194a48 + 100) = 1;
  *(undefined4 *)(*piVar1 + 0x68) = 0;
                    /* WARNING: Could not recover jumptable at 0x02194a44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_02194a4c)();
  return;
}

