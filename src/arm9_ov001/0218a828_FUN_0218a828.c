/* Decompiled C draft; module arm9_ov001; ROM address 0218a828. No matching claim. */
#include "types.h"
#include "deps/0218a828_FUN_0218a828.h"

void FUN_0218a828(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_02188158(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218a904),
                       *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218a908));
  if (iVar1 != 0) {
    iVar2 = FUN_02188104(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xc0),
                         *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xc4));
    if (iVar2 != 0) {
      func_0x020fd754(iVar1);
      FUN_02187c60(param_1,iVar1);
      FUN_02187218(param_1,3,0);
      FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xec),
                   *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xf0));
      uVar3 = *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xf8);
      FUN_02188c48(param_1,uVar3,uVar3);
      FUN_02188998(param_1,(undefined4 *)(uintptr_t)(iVar2 + 0x80));
      FUN_02188cec(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xf4));
      FUN_02188de0(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xcc),
                   *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xd0),(undefined4 *)(uintptr_t)(iVar2 + 0x80),DAT_0218a90c);
      FUN_0218b278(param_1);
      return;
    }
    func_0x020fd754(iVar1);
    FUN_02187c60(param_1,iVar1);
    FUN_0218a910(param_1);
  }
  return;
}

