/* Decompiled C draft; module arm9_ov001; ROM address 0218a60c. No matching claim. */
#include "types.h"
#include "deps/0218a60c_FUN_0218a60c.h"

void FUN_0218a60c(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_02187e78();
  FUN_02187218(param_1,2,0);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x84),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x88));
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x90);
  FUN_02188c48(param_1,uVar1,uVar1);
  uVar1 = FUN_02187fc0(param_1);
  FUN_02188998(param_1,uVar1);
  FUN_02188cec(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x8c));
  FUN_02188e24(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x9c),DAT_0218a6a8);
  iVar2 = *(int *)(param_1 + 0xa0);
  uVar1 = FUN_02187fc0(param_1);
  FUN_02188de0(param_1,*(undefined4 *)(iVar2 + 0x94),*(undefined4 *)(iVar2 + 0x98),uVar1,
               DAT_0218a6ac);
  FUN_0218b278(param_1);
  return;
}

