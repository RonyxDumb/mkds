/* Decompiled C draft; module arm9_ov001; ROM address 021841e0. No matching claim. */
#include "types.h"
#include "deps/021841e0_FUN_021841e0.h"

void FUN_021841e0(int param_1)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = 0;
  local_10 = 0;
  local_14 = *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02184254);
  FUN_02187218(param_1,8,DAT_02184258);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218425c),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02184260));
  FUN_02188950(param_1,&local_18);
  FUN_02188c90(param_1);
  FUN_02188cd8(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02184264),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02184268));
  FUN_02188db8(param_1,DAT_0218426c);
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *DAT_02184270;
  return;
}

