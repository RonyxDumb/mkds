/* Decompiled C draft; module arm9_ov003; ROM address 021d2e90. No matching claim. */
#include "types.h"
#include "deps/021d2e90_FUN_021d2e90.h"

void FUN_021d2e90(int *param_1)

{
  func_0x0200ca9c(1);
  *(int *)(*param_1 + 4) = param_1[1];
  *(int *)param_1[1] = *param_1;
  param_1[1] = 0;
  *param_1 = param_1[1];
  func_0x0200cae4();
  return;
}

