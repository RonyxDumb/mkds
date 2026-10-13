/* Decompiled C draft; module arm9_ov001; ROM address 0218bcc4. No matching claim. */
#include "types.h"
#include "deps/0218bcc4_FUN_0218bcc4.h"

void FUN_0218bcc4(int param_1)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = 0;
  local_10 = 0;
  local_14 = *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218bd58);
  FUN_02187218(param_1,7);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218bd5c),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218bd60));
  FUN_0219b1c4(*(undefined4 *)(param_1 + DAT_0218bd64),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218bd68),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218bd60),0);
  FUN_02188950(param_1,&local_18);
  FUN_02188c90(param_1);
  FUN_02188cd8(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218bd6c),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218bd70));
  FUN_02188db8(param_1,DAT_0218bd74);
  func_0x020d2774(param_1,DAT_0218bd78);
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *DAT_0218bd7c;
  return;
}

