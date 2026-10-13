/* Decompiled C draft; module arm9_ov001; ROM address 021913b8. No matching claim. */
#include "types.h"
#include "deps/021913b8_FUN_021913b8.h"

void FUN_021913b8(int param_1)

{
  int iVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  iVar1 = func_0x0207a974((short)*(char *)(*DAT_02191460 + 0x62));
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  FUN_02187e78(param_1);
  FUN_02187218(param_1,3,DAT_02191464);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xd0),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xd4));
  FUN_02188950(param_1,&local_1c);
  FUN_02188c90(param_1);
  FUN_02188cd8(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xd8),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xdc));
  FUN_02188de0(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xe8),0,(undefined4 *)(uintptr_t)(iVar1 + 0x80),DAT_02191468)
  ;
  FUN_02188e24(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xec),DAT_02191468);
  *(undefined4 *)(param_1 + DAT_0219146c) = 0;
  return;
}

