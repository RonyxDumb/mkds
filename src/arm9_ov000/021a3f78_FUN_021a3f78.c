/* Decompiled C draft; module arm9_ov000; ROM address 021a3f78. No matching claim. */
#include "types.h"
#include "deps/021a3f78_FUN_021a3f78.h"

void FUN_021a3f78(undefined4 param_1,undefined1 *param_2)

{
  *(undefined4 *)(param_2 + DAT_021a3fc0) = 1;
  *param_2 = 0x5c;
  FUN_021a3fc8(param_1,(int)(uintptr_t)(param_2),0);
  FUN_021a3fc8(param_1,(int)(uintptr_t)(param_2),1);
  FUN_021a3fc8(param_1,(int)(uintptr_t)(param_2),2);
  FUN_021a471c((int)(uintptr_t)(param_2),DAT_021a3fc4);
  *(int *)(param_2 + DAT_021a3fc0) = *(int *)(param_2 + DAT_021a3fc0) + -1;
  return;
}

