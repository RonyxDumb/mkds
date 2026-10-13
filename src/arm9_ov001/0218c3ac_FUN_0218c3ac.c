/* Decompiled C draft; module arm9_ov001; ROM address 0218c3ac. No matching claim. */
#include "types.h"
#include "deps/0218c3ac_FUN_0218c3ac.h"

void FUN_0218c3ac(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_02188220();
  if (iVar1 == 0) {
    FUN_02188cd8(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xa4),
                 *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xa8));
    FUN_02188c48(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xac),
                 *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xb0));
  }
  else {
    iVar1 = FUN_02188220(param_1);
    if (iVar1 == 1) {
      FUN_02188cd8(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xbc),
                   *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xc0));
      FUN_02188c48(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xc4),
                   *(undefined4 *)(*(int *)(param_1 + 0xa0) + 200));
    }
    else {
      FUN_02188cd8(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xcc),
                   *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xd0));
      FUN_02188c48(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xd4),
                   *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xd8));
    }
  }
  uVar2 = FUN_02187fc0(param_1);
  FUN_02188998(param_1,(undefined4 *)(uintptr_t)(uVar2));
  FUN_02188e24(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xb8),0);
  uVar2 = FUN_02187fc0(param_1);
  FUN_02188de0(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xb4),0,(undefined4 *)(uintptr_t)(uVar2),0);
  return;
}

