/* Decompiled C draft; module arm9_ov001; ROM address 02191c14. No matching claim. */
#include "types.h"
#include "deps/02191c14_FUN_02191c14.h"

void FUN_02191c14(int param_1)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = 0;
  local_10 = 0;
  local_14 = *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191cbc);
  FUN_02187218(param_1,3,DAT_02191cc0);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191cc4),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191cc8));
  FUN_02188950(param_1,&local_18);
  FUN_02188c0c(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191ccc),DAT_02191cd0);
  FUN_02188cd8(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191cd4),DAT_02191cd0);
  FUN_02188e24(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191cd8),DAT_02191cdc);
  FUN_021875c0(param_1,0,DAT_02191ce4,DAT_02191ce8,DAT_02191ce0,0);
  FUN_021875c0(param_1,0,DAT_02191ce4,DAT_02191ce8,DAT_02191cec,0);
  *(undefined4 *)(param_1 + DAT_02191cf0) = 0;
  return;
}

