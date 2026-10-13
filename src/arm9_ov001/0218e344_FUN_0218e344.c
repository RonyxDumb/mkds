/* Decompiled C draft; module arm9_ov001; ROM address 0218e344. No matching claim. */
#include "types.h"
#include "deps/0218e344_FUN_0218e344.h"

void FUN_0218e344(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_021871f8(param_1,5);
  if (iVar1 != 0) {
    FUN_0218edc8(param_1);
  }
  *(undefined4 *)(param_1 + DAT_0218e37c) = 0xd;
  FUN_02188200(param_1,DAT_0218e380);
  if (*(int *)(param_1 + DAT_0218e384) == 0) {
    func_0x020d2774(param_1,DAT_0218e388);
  }
  return;
}

