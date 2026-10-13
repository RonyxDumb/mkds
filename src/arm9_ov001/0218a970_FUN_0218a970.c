/* Decompiled C draft; module arm9_ov001; ROM address 0218a970. No matching claim. */
#include "types.h"
#include "deps/0218a970_FUN_0218a970.h"

void FUN_0218a970(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_02188104(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xc0),
                       *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xc4));
  if (iVar1 != 0) {
    FUN_02187218(param_1,3,0);
    FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218aa28),
                 *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218aa2c));
    uVar2 = *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xbc);
    FUN_02188c48(param_1,uVar2,uVar2);
    FUN_02188998(param_1,(undefined4 *)(uintptr_t)(iVar1 + 0x80));
    FUN_02188cec(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xb8));
    FUN_02188de0(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xcc),
                 *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xd0),(undefined4 *)(uintptr_t)(iVar1 + 0x80),DAT_0218aa30);
    FUN_02188e24(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 200),0);
    FUN_0218b278(param_1);
    return;
  }
  FUN_02188e88(param_1);
  return;
}

