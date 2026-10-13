/* Decompiled C draft; module arm9_ov001; ROM address 0218e760. No matching claim. */
#include "types.h"
#include "deps/0218e760_FUN_0218e760.h"

void FUN_0218e760(int param_1)

{
  FUN_02187218(param_1,5,DAT_0218e79c);
  FUN_0218f850(param_1);
  FUN_02188e24(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218e7a0),DAT_0218e7a4);
  if (*DAT_0218e7a8 != 3) {
    *DAT_0218e7ac = *DAT_0218e7a8;
  }
  *DAT_0218e7a8 = 3;
  return;
}

