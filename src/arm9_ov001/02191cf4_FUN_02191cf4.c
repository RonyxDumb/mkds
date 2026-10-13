/* Decompiled C draft; module arm9_ov001; ROM address 02191cf4. No matching claim. */
#include "types.h"
#include "deps/02191cf4_FUN_02191cf4.h"

void FUN_02191cf4(int param_1)

{
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  
  local_18 = 0;
  local_10 = 0;
  local_14 = -*(int *)(*(int *)(param_1 + 0xa0) + DAT_02191d94);
  FUN_02187218(param_1,3,DAT_02191d98);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191d9c),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191da0));
  FUN_02188950(param_1,&local_18);
  FUN_02188c0c(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191da4),DAT_02191da8);
  FUN_02188cd8(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191dac),DAT_02191da8);
  FUN_021875c0(param_1,0,DAT_02191db4,DAT_02191db8,DAT_02191db0,0);
  FUN_021875c0(param_1,0,DAT_02191db4,DAT_02191db8,DAT_02191dbc,0);
  FUN_02188db8(param_1,DAT_02191dc0);
  *(undefined4 *)(param_1 + DAT_02191dc4) = 0;
  return;
}

