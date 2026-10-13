/* Decompiled C draft; module arm9_ov003; ROM address 021d2e68. No matching claim. */
#include "types.h"
#include "deps/021d2e68_FUN_021d2e68.h"

void FUN_021d2e68(int *param_1,int *param_2)

{
  func_0x0200ca9c(1);
  *(int **)(*param_1 + 4) = param_2;
  *param_2 = *param_1;
  param_2[1] = (int)param_1;
  *param_1 = (int)param_2;
  func_0x0200cae4();
  return;
}

