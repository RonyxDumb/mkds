/* Decompiled C draft; module arm9_ov001; ROM address 0218da1c. No matching claim. */
#include "types.h"
#include "deps/0218da1c_FUN_0218da1c.h"

void FUN_0218da1c(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  FUN_02187af4();
  FUN_021875c0(param_1,0,*(int *)(param_1 + DAT_0218daa8) >> 4,0,DAT_0218daa4,0xf);
  FUN_021875c0(param_1,0,*(int *)(param_1 + DAT_0218daa8) >> 4,0,DAT_0218daac,0xf);
  func_0x020d2774(param_1,DAT_0218dab0);
  FUN_02188230(param_1);
  iVar1 = FUN_02188220(param_1);
  if (iVar1 == 2) {
    func_0x020d2774(param_1,DAT_0218dab4);
  }
  else {
    uVar2 = FUN_02188220(param_1);
    if (2 < uVar2) {
      *(undefined4 *)(param_1 + 0xac) = 0;
    }
  }
  uVar3 = FUN_02188220(param_1);
  func_0x0209b688(*(undefined4 *)(param_1 + DAT_0218dab8),uVar3);
  return;
}

