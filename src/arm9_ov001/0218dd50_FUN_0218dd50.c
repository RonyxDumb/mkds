/* Decompiled C draft; module arm9_ov001; ROM address 0218dd50. No matching claim. */
#include "types.h"
#include "deps/0218dd50_FUN_0218dd50.h"

void FUN_0218dd50(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = FUN_02188220();
  if (1 < uVar1) {
    func_0x020d2774(param_1,DAT_0218dd90);
    return;
  }
  iVar2 = FUN_02188220(param_1);
  if (iVar2 != 0) {
    func_0x020d2774(param_1,DAT_0218dd94);
    return;
  }
  func_0x020d2774(param_1,DAT_0218dd98);
  return;
}

