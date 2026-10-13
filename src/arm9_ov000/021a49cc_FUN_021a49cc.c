/* Decompiled C draft; module arm9_ov000; ROM address 021a49cc. No matching claim. */
#include "types.h"
#include "deps/021a49cc_FUN_021a49cc.h"

void FUN_021a49cc(int param_1,undefined4 param_2)

{
  if (param_1 == 0) {
    param_1 = *DAT_021a49dc;
  }
  *(undefined4 *)(param_1 + 0xa8) = param_2;
  return;
}

