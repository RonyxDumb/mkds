/* Decompiled C draft; module arm9_ov001; ROM address 0218e520. No matching claim. */
#include "types.h"
#include "deps/0218e520_FUN_0218e520.h"

void FUN_0218e520(int param_1)

{
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + *(int *)(*(int *)(param_1 + 0xa0) + 0x80);
  FUN_02187218(param_1,8,0);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x4c),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x50));
  FUN_02188e24(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x54),DAT_0218e560);
  return;
}

