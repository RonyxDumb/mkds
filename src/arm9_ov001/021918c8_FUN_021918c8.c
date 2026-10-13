/* Decompiled C draft; module arm9_ov001; ROM address 021918c8. No matching claim. */
#include "types.h"
#include "deps/021918c8_FUN_021918c8.h"

void FUN_021918c8(int param_1)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = 0;
  local_10 = 0;
  local_14 = *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191958);
  FUN_021924cc();
  FUN_02187218(param_1,3,0);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0219195c),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191960));
  FUN_02188950(param_1,&local_18);
  FUN_02188b78(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191964),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191968));
  FUN_02188998(param_1,(undefined4 *)(uintptr_t)(param_1 + DAT_0219196c));
  FUN_02188cd8(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191970),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191974));
  FUN_02188e24(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191978),DAT_0219197c);
  return;
}

