/* Decompiled C draft; module arm9_ov001; ROM address 02188da4. No matching claim. */
#include "types.h"
#include "deps/02188da4_FUN_02188da4.h"

void FUN_02188da4(int param_1,int param_2)

{
  if (param_2 == 0) {
    param_2 = DAT_02188db0;
  }
  *(int *)(param_1 + DAT_02188db4) = param_2;
  return;
}

