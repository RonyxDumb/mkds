/* Decompiled C draft; module arm9_ov001; ROM address 0218ab04. No matching claim. */
#include "types.h"
#include "deps/0218ab04_FUN_0218ab04.h"

void FUN_0218ab04(int param_1)

{
  undefined4 uVar1;
  
  FUN_02187e78();
  FUN_02187218(param_1,3,0);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ab80),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ab84));
  FUN_02188c48(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ab88),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ab8c));
  uVar1 = FUN_02187fc0(param_1);
  FUN_02188998(param_1,(undefined4 *)(uintptr_t)(uVar1));
  FUN_02188cd8(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ab90),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ab94));
  FUN_02188e24(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ab98),DAT_0218ab9c);
  FUN_0218b278(param_1);
  return;
}

