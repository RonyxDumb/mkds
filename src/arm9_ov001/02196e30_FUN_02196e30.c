/* Decompiled C draft; module arm9_ov001; ROM address 02196e30. No matching claim. */
#include "types.h"
#include "deps/02196e30_FUN_02196e30.h"

void FUN_02196e30(void)

{
  int *piVar1;
  
  piVar1 = DAT_02196e48;
  *(undefined4 *)(*DAT_02196e48 + 0x54) = 0xd;
  *(undefined4 *)(*piVar1 + 0x58) = 0;
                    /* WARNING: Could not recover jumptable at 0x02196e44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_02196e50)(DAT_02196e4c,0,6);
  return;
}

