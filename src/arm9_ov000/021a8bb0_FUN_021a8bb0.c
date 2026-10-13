/* Decompiled C draft; module arm9_ov000; ROM address 021a8bb0. No matching claim. */
#include "types.h"
#include "deps/021a8bb0_FUN_021a8bb0.h"

void FUN_021a8bb0(undefined4 param_1,undefined1 *param_2)

{
  *param_2 = (char)((uint)param_1 >> 0x18);
  param_2[1] = (char)((uint)param_1 >> 0x10);
  param_2[2] = (char)((uint)param_1 >> 8);
  param_2[3] = (char)param_1;
  return;
}

