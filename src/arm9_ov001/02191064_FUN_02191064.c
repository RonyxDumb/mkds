/* Decompiled C draft; module arm9_ov001; ROM address 02191064. No matching claim. */
#include "types.h"
#include "deps/02191064_FUN_02191064.h"

void FUN_02191064(int param_1)

{
  FUN_02187218(param_1,7,DAT_021910b8);
  FUN_02188d30(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_021910bc),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_021910c0),DAT_021910c4);
  FUN_02188c90(param_1);
  FUN_02188cec(param_1,0);
  *(undefined4 *)(param_1 + DAT_021910c8) = 1;
  FUN_0219226c(param_1);
  FUN_02188200(param_1,DAT_021910cc);
  func_0x020d2774(param_1,DAT_021910d0);
  return;
}

