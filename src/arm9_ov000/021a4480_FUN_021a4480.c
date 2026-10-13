/* Decompiled C draft; module arm9_ov000; ROM address 021a4480. No matching claim. */
#include "types.h"
#include "deps/021a4480_FUN_021a4480.h"

void FUN_021a4480(undefined1 *param_1,undefined1 param_2,undefined1 *param_3)

{
  *param_1 = param_2;
  param_1[1] = *param_3;
  param_1[2] = param_3[1];
  param_1[3] = param_3[2];
  param_1[4] = param_3[3];
  *(undefined4 *)(param_1 + DAT_021a449c) = 5;
  return;
}

