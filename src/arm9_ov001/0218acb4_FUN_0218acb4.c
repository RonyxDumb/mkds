/* Decompiled C draft; module arm9_ov001; ROM address 0218acb4. No matching claim. */
#include "types.h"
#include "deps/0218acb4_FUN_0218acb4.h"

void FUN_0218acb4(int param_1)

{
  undefined4 uVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  FUN_02187e78();
  FUN_02187218(param_1,3,0);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ad44),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ad48));
  FUN_02188c48(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ad4c),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ad50));
  uVar1 = FUN_02187fc0(param_1);
  FUN_02188998(param_1,(undefined4 *)(uintptr_t)(uVar1));
  FUN_02188cd8(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ad54),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ad58));
  FUN_02188950(param_1,&local_18);
  FUN_02188e24(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ad5c),DAT_0218ad60);
  *(undefined4 *)(param_1 + DAT_0218ad64) = 0;
  return;
}

