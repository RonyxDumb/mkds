/* Decompiled C draft; module arm9_ov001; ROM address 0218e7d0. No matching claim. */
#include "types.h"
#include "deps/0218e7d0_FUN_0218e7d0.h"

void FUN_0218e7d0(int param_1)

{
  FUN_02187218(param_1,1,0);
  FUN_021888a4(param_1,0,DAT_0218e840);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218e844),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218e848));
  FUN_02188d1c(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218e84c),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218e850));
  FUN_02188cec(param_1,0);
  FUN_02188c90(param_1);
  if (*DAT_0218e854 != 3) {
    *DAT_0218e858 = *DAT_0218e854;
  }
  *DAT_0218e854 = 3;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *DAT_0218e85c;
  return;
}

