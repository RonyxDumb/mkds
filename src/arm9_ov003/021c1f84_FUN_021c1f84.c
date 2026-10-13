/* Decompiled C draft; module arm9_ov003; ROM address 021c1f84. No matching claim. */
#include "types.h"
#include "deps/021c1f84_FUN_021c1f84.h"

void FUN_021c1f84(int param_1)

{
  FUN_021ba560();
  if (((param_1 != 0) && (*(char *)(*DAT_021c1fb8 + DAT_021c1fbc) == '\0')) &&
     (*DAT_021c1fc0 == '\x01')) {
    FUN_021cd4e8(*DAT_021c1fb8 + DAT_021c1fc4);
  }
  FUN_021d2808(DAT_021c1fb8);
  return;
}

