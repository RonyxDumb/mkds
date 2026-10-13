/* Decompiled C draft; module arm9_ov001; ROM address 0218add0. No matching claim. */
#include "types.h"
#include "deps/0218add0_FUN_0218add0.h"

void FUN_0218add0(int param_1)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = 0;
  local_10 = 0;
  local_14 = *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ae44);
  FUN_02187218(param_1,3);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ae48),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ae4c));
  FUN_02188950(param_1,&local_18);
  FUN_02188c90(param_1);
  FUN_02188cec(param_1,0);
  FUN_02188db8(param_1,DAT_0218ae50);
  *(undefined4 *)(param_1 + DAT_0218ae54) = 1;
  func_0x020d2774(param_1,DAT_0218ae58);
  FUN_02188200(param_1,DAT_0218ae5c);
  return;
}

