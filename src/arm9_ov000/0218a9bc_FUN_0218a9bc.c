/* Decompiled C draft; module arm9_ov000; ROM address 0218a9bc. No matching claim. */
#include "types.h"
#include "deps/0218a9bc_FUN_0218a9bc.h"

void FUN_0218a9bc(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = FUN_0218e8c4();
  iVar1 = DAT_0218aa10;
  iVar3 = *(int *)(param_1 + 8);
  while ((iVar3 != 0 && ((uint)(*(int *)(iVar3 + 0x1c) + iVar1) < uVar2))) {
    *(byte *)(iVar3 + 0x15) = *(byte *)(iVar3 + 0x15) | 0x10;
    *(int *)(*(int *)(param_1 + 8) + 0x1c) = iVar1;
    *(byte *)(*(int *)(param_1 + 8) + 0x15) = *(byte *)(*(int *)(param_1 + 8) + 0x15) & 0xd3;
    (**(code **)(param_1 + 0x44))
              (param_1,1,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x48));
    FUN_0218aea4((int *)(uintptr_t)(param_1 + 8));
    iVar3 = *(int *)(param_1 + 8);
  }
  return;
}

