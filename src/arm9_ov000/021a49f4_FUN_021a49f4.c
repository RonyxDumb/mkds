/* Decompiled C draft; module arm9_ov000; ROM address 021a49f4. No matching claim. */
#include "types.h"
#include "deps/021a49f4_FUN_021a49f4.h"

void FUN_021a49f4(int param_1,undefined4 param_2)

{
  if (param_1 == 0) {
    param_1 = *DAT_021a4a04;
  }
  *(undefined4 *)(param_1 + 0xa0) = param_2;
  return;
}

