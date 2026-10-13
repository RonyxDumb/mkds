/* Decompiled C draft; module arm9_ov001; ROM address 0218ec40. No matching claim. */
#include "types.h"
#include "deps/0218ec40_FUN_0218ec40.h"

void FUN_0218ec40(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  func_0x0207a974((short)*(char *)(*DAT_0218ed60 + 0x62));
  FUN_02187218(param_1,1,DAT_0218ed64);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ed68),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ed6c));
  FUN_02188d1c(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ed70),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ed74));
  iVar1 = *(int *)(param_1 + 0xa8);
  if (iVar1 == 1) {
    FUN_02188cd8(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ed78),
                 *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ed7c));
    FUN_02188c48(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ed80),
                 *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ed84));
  }
  else if (iVar1 == 2) {
    FUN_02188cd8(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ed88),
                 *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ed8c));
    FUN_02188c48(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ed90),
                 *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ed94));
  }
  else if (iVar1 == 3) {
    FUN_02188cd8(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ed98),
                 *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ed9c));
    FUN_02188c48(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218eda0),
                 *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218eda4));
  }
  uVar2 = FUN_02187fc0(param_1);
  FUN_02188998(param_1,uVar2);
  iVar1 = *(int *)(param_1 + 0xa0);
  uVar2 = FUN_02187fc0(param_1);
  FUN_02188de0(param_1,*(undefined4 *)(iVar1 + DAT_0218eda8),*(undefined4 *)(iVar1 + DAT_0218edac),
               uVar2,0);
  if (*DAT_0218edb0 != 5) {
    *DAT_0218edb4 = *DAT_0218edb0;
  }
  *DAT_0218edb0 = 5;
  return;
}

