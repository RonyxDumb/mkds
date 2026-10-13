/* Decompiled C draft; module arm9_ov003; ROM address 021cfa30. No matching claim. */
#include "types.h"
#include "deps/021cfa30_FUN_021cfa30.h"

void FUN_021cfa30(int param_1)

{
  int *piVar1;
  
  *DAT_021cfa58 = param_1;
  FUN_021d0810(param_1 + DAT_021cfa5c);
  piVar1 = DAT_021cfa58;
  *(undefined4 *)(*DAT_021cfa58 + DAT_021cfa60) = 0;
  *(undefined4 *)(*piVar1 + DAT_021cfa64) = 0;
  return;
}

