/* Decompiled C draft; module arm9_ov001; ROM address 02191318. No matching claim. */
#include "types.h"
#include "deps/02191318_FUN_02191318.h"

void FUN_02191318(int param_1)

{
  int iVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  iVar1 = func_0x0207a974((short)*(char *)(*DAT_021913ac + 0x62));
  local_18 = 0;
  local_10 = 0;
  local_14 = *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xa4);
  FUN_02187218(param_1,3,DAT_021913b0);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x8c),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x90));
  FUN_02188950(param_1,&local_18);
  FUN_02188c90(param_1);
  FUN_02188998(param_1,iVar1 + 0x80);
  FUN_02188cd8(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x94),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x98));
  FUN_02188e24(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xa8),DAT_021913b4);
  return;
}

