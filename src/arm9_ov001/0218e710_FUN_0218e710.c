/* Decompiled C draft; module arm9_ov001; ROM address 0218e710. No matching claim. */
#include "types.h"
#include "deps/0218e710_FUN_0218e710.h"

void FUN_0218e710(int param_1)

{
  FUN_02187218(param_1,8,0);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x78),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x7c));
  FUN_02188c90(param_1);
  FUN_02188cec(param_1,0);
  if (*DAT_0218e758 != 6) {
    *DAT_0218e75c = *DAT_0218e758;
  }
  *DAT_0218e758 = 6;
  func_0x0206184c();
  return;
}

