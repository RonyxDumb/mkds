/* Decompiled C draft; module arm9_ov001; ROM address 0218f850. No matching claim. */
#include "types.h"
#include "deps/0218f850_FUN_0218f850.h"

void FUN_0218f850(int param_1)

{
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218f8dc),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218f8e0));
  FUN_02188d1c(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218f8e4),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218f8e8));
  FUN_02188cec(param_1,0);
  FUN_02188c90(param_1);
  FUN_021875c0(param_1,0,0,0,DAT_0218f8ec,0);
  FUN_021875c0(param_1,0,0,0,DAT_0218f8f0,0);
  FUN_021875c0(param_1,0,0,0,DAT_0218f8f4,0);
  func_0x020d2774(param_1,DAT_0218f8f8);
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *DAT_0218f8fc;
  return;
}

