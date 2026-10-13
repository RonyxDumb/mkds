/* Decompiled C draft; module arm9_ov001; ROM address 02183e40. No matching claim. */
#include "types.h"
#include "deps/02183e40_FUN_02183e40.h"

void FUN_02183e40(int param_1)

{
  undefined4 uVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = 0;
  local_10 = 0;
  local_14 = *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02183ea4);
  FUN_02187218(param_1,5,DAT_02183ea8);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02183eac),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02183eb0));
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02183eb4);
  FUN_02188a8c(param_1,uVar1,uVar1);
  FUN_02188950(param_1,&local_18);
  FUN_02188db8(param_1,DAT_02183eb8);
  return;
}

