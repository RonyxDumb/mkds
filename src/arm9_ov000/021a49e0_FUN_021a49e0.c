/* Decompiled C draft; module arm9_ov000; ROM address 021a49e0. No matching claim. */
#include "types.h"
#include "deps/021a49e0_FUN_021a49e0.h"

void FUN_021a49e0(int param_1,undefined4 param_2)

{
  if (param_1 == 0) {
    param_1 = *DAT_021a49f0;
  }
  *(undefined4 *)(param_1 + 0xa4) = param_2;
  return;
}

