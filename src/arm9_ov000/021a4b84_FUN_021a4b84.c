/* Decompiled C draft; module arm9_ov000; ROM address 021a4b84. No matching claim. */
#include "types.h"
#include "deps/021a4b84_FUN_021a4b84.h"

void FUN_021a4b84(int param_1,undefined4 param_2)

{
  if ((0x31 < param_1) && (param_1 < 0xff)) {
    *(undefined4 *)(DAT_021a4b94 + param_1 * 4) = param_2;
  }
  return;
}

