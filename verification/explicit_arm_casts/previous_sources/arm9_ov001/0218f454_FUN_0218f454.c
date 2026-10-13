/* Decompiled C draft; module arm9_ov001; ROM address 0218f454. No matching claim. */
#include "types.h"
#include "deps/0218f454_FUN_0218f454.h"

void FUN_0218f454(int param_1)

{
  int iVar1;
  
  iVar1 = func_0x0207a974((short)*(char *)(*DAT_0218f4ec + 0x62));
  FUN_02187218(param_1,5,DAT_0218f4f0);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218f4f4),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218f4f8));
  FUN_02188cd8(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218f4fc),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218f500));
  FUN_02188c48(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218f504),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218f508));
  FUN_02188998(param_1,iVar1 + 0x80);
  FUN_021889c8(param_1);
  FUN_02188e24(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218f50c),DAT_0218f510);
  FUN_02188200(param_1,DAT_0218f514);
  func_0x020d2774(param_1,DAT_0218f518);
  return;
}

