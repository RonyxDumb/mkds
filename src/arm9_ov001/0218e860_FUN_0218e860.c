/* Decompiled C draft; module arm9_ov001; ROM address 0218e860. No matching claim. */
#include "types.h"
#include "deps/0218e860_FUN_0218e860.h"

void FUN_0218e860(int param_1)

{
  FUN_02187218(param_1,5,DAT_0218e89c);
  FUN_0218f850(param_1);
  FUN_02188e24(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218e8a0),DAT_0218e8a4);
  if (*DAT_0218e8a8 != 3) {
    *DAT_0218e8ac = *DAT_0218e8a8;
  }
  *DAT_0218e8a8 = 3;
  return;
}

