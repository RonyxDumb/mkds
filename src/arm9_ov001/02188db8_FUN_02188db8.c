/* Decompiled C draft; module arm9_ov001; ROM address 02188db8. No matching claim. */
#include "types.h"
#include "deps/02188db8_FUN_02188db8.h"

void FUN_02188db8(int param_1,int param_2)

{
  if (param_2 == 0) {
    param_2 = DAT_02188dc4;
  }
  *(int *)(param_1 + DAT_02188dc8) = param_2;
  return;
}

