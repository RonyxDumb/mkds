/* Decompiled C draft; module arm9_ov001; ROM address 0218883c. No matching claim. */
#include "types.h"
#include "deps/0218883c_FUN_0218883c.h"

void FUN_0218883c(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + DAT_0218887c) = 1;
  }
  else {
    *(undefined4 *)(param_1 + DAT_0218887c) = 2;
  }
  *(undefined4 *)(param_1 + DAT_02188880) = 0;
  *(int *)(param_1 + DAT_02188884) = param_2;
  *(undefined4 *)(param_1 + DAT_02188888) = 0;
  *(undefined4 *)(param_1 + DAT_0218888c) = param_3;
  *(undefined4 *)(param_1 + DAT_02188890) = param_4;
  *(undefined4 *)(param_1 + DAT_02188898) = DAT_02188894;
  *(undefined4 *)(param_1 + DAT_0218889c) = param_4;
  *(undefined4 *)(param_1 + DAT_021888a0) = param_5;
  return;
}

