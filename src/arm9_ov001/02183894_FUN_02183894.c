/* Decompiled C draft; module arm9_ov001; ROM address 02183894. No matching claim. */
#include "types.h"
#include "deps/02183894_FUN_02183894.h"

void FUN_02183894(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0xa0);
  uVar1 = FUN_02187fc0();
  iVar2 = FUN_021881a8(param_1,uVar1,*(undefined4 *)(iVar2 + 0xac),*(undefined4 *)(iVar2 + 0xb0));
  if (iVar2 == 0) {
    FUN_02187e78(param_1);
    FUN_02187218(param_1,1,0);
    FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x9c),
                 *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xa0));
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xa8);
    FUN_02188c48(param_1,uVar1,uVar1);
    uVar1 = FUN_02187fc0(param_1);
    FUN_02188998(param_1,(undefined4 *)(uintptr_t)(uVar1));
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xa4);
    FUN_02188cd8(param_1,uVar1,uVar1);
    iVar2 = *(int *)(param_1 + 0xa0);
    uVar1 = FUN_02187fc0(param_1);
    FUN_02188de0(param_1,*(undefined4 *)(iVar2 + 0xac),*(undefined4 *)(iVar2 + 0xb0),(undefined4 *)(uintptr_t)(uVar1),0);
  }
  else {
    FUN_02187218(param_1,1,0);
    FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xb8),
                 *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xbc));
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xc4);
    FUN_02188b2c(param_1,uVar1,uVar1,0);
    uVar1 = FUN_02187fc0(param_1);
    FUN_02188998(param_1,(undefined4 *)(uintptr_t)(uVar1));
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xc0);
    FUN_02188cd8(param_1,uVar1,uVar1);
    FUN_02188e24(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 200),0);
  }
  FUN_02184e6c(param_1);
  return;
}

