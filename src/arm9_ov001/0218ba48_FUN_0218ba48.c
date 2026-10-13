/* Decompiled C draft; module arm9_ov001; ROM address 0218ba48. No matching claim. */
#include "types.h"
#include "deps/0218ba48_FUN_0218ba48.h"

void FUN_0218ba48(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_02187218(param_1,8,DAT_0218bb58);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xdc),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xe0));
  FUN_0219b1c4(*(undefined4 *)(param_1 + DAT_0218bb5c),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xe4),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xe0),0);
  FUN_02188cd8(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xe8),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xec));
  FUN_02188c48(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xf0),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xf4));
  uVar1 = FUN_02187fc0(param_1);
  FUN_02188998(param_1,(undefined4 *)(uintptr_t)(uVar1));
  FUN_02188e24(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218bb60),DAT_0218bb64);
  FUN_02188d08(param_1,*(int *)(param_1 + 0x1c) + *(int *)(*(int *)(param_1 + 0xa0) + 0xf8),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xfc));
  FUN_02188cec(param_1,0);
  uVar1 = FUN_02188220(param_1);
  func_0x0209b688(*(undefined4 *)(param_1 + DAT_0218bb5c),uVar1);
  iVar2 = FUN_02188220(param_1);
  if (iVar2 == 0) {
    FUN_0218c6b4(param_1);
    FUN_0218756c(param_1,0,DAT_0218bb6c,0,DAT_0218bb68,0);
    return;
  }
  iVar2 = FUN_02188220(param_1);
  if (iVar2 == 1) {
    FUN_0218c63c(param_1);
    FUN_0218756c(param_1,0,DAT_0218bb6c,0,DAT_0218bb70,0);
  }
  return;
}

