/* Decompiled C draft; module arm9_ov001; ROM address 021911a8. No matching claim. */
#include "types.h"
#include "deps/021911a8_FUN_021911a8.h"

void FUN_021911a8(int param_1)

{
  int iVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  iVar1 = func_0x0207a974((short)*(char *)(*DAT_02191238 + 0x62));
  local_18 = 0;
  local_10 = 0;
  local_14 = *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0219123c);
  FUN_02187218(param_1,3);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191240),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191244));
  FUN_02188950(param_1,&local_18);
  FUN_02188c90(param_1);
  FUN_02188998(param_1,(undefined4 *)(uintptr_t)(iVar1 + 0x80));
  FUN_02188cd8(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191248),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0219124c));
  FUN_02188db8(param_1,DAT_02191250);
  FUN_02188200(param_1,DAT_02191254);
  return;
}

