/* Decompiled C draft; module arm9_ov001; ROM address 02188e24. No matching claim. */
#include "types.h"
#include "deps/02188e24_FUN_02188e24.h"

void FUN_02188e24(int param_1,undefined4 param_2,int param_3)

{
  *(undefined4 *)(param_1 + DAT_02188e3c) = param_2;
  *(undefined4 *)(param_1 + 0xb0) = 0;
  if (param_3 == 0) {
    param_3 = DAT_02188e40;
  }
  *(int *)(param_1 + DAT_02188e44) = param_3;
  return;
}

