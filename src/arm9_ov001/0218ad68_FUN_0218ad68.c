/* Decompiled C draft; module arm9_ov001; ROM address 0218ad68. No matching claim. */
#include "types.h"
#include "deps/0218ad68_FUN_0218ad68.h"

void FUN_0218ad68(int param_1)

{
  FUN_0218aef4();
  FUN_02187218(param_1,3,0);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218adbc),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218adc0));
  FUN_02188c90(param_1);
  FUN_02188cec(param_1,0);
  FUN_02188e24(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218adc4),DAT_0218adc8);
  *(undefined4 *)(param_1 + DAT_0218adcc) = 0;
  return;
}

