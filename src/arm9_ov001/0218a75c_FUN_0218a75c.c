/* Decompiled C draft; module arm9_ov001; ROM address 0218a75c. No matching claim. */
#include "types.h"
#include "deps/0218a75c_FUN_0218a75c.h"

void FUN_0218a75c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_02188158(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218a800),
                       *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218a804));
  if (iVar1 != 0) {
    FUN_02187218(param_1,3,0);
    FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218a808),
                 *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218a80c));
    uVar2 = *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218a810);
    FUN_02188c48(param_1,uVar2,uVar2);
    FUN_02188998(param_1,(undefined4 *)(uintptr_t)(iVar1 + 0x50));
    FUN_02188cec(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218a814));
    FUN_02188de0(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218a81c),
                 *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218a820),(undefined4 *)(uintptr_t)(iVar1 + 0x50),DAT_0218a818)
    ;
    FUN_02188e24(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218a824),0);
    FUN_0218b278(param_1);
  }
  return;
}

