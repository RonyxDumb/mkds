/* Decompiled C draft; module arm9_ov001; ROM address 0218ac04. No matching claim. */
#include "types.h"
#include "deps/0218ac04_FUN_0218ac04.h"

void FUN_0218ac04(int param_1)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = 0;
  local_10 = 0;
  local_14 = *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ac8c);
  FUN_02187218(param_1,3);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ac90),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ac94));
  FUN_02188950(param_1,&local_18);
  FUN_02188cd8(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ac98),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ac9c));
  FUN_02188db8(param_1,DAT_0218aca0);
  FUN_02188e24(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218aca4),DAT_0218aca8);
  func_0x020d2774(param_1,DAT_0218acac);
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *DAT_0218acb0;
  return;
}

