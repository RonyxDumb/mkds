/* Decompiled C draft; module arm9_ov001; ROM address 0218f57c. No matching claim. */
#include "types.h"
#include "deps/0218f57c_FUN_0218f57c.h"

void FUN_0218f57c(int param_1)

{
  int iVar1;
  
  iVar1 = func_0x0207a974((short)*(char *)(*DAT_0218f60c + 0x62));
  FUN_02187218(param_1,5,DAT_0218f610);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218f614),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218f618));
  FUN_02188cd8(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218f61c),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218f620));
  FUN_02188bc4(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218f624),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218f628));
  FUN_02188998(param_1,iVar1 + 0x80);
  FUN_021889c8(param_1);
  FUN_02188e24(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218f62c),0);
  FUN_02188200(param_1,DAT_0218f630);
  return;
}

