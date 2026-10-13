/* Decompiled C draft; module arm9_ov001; ROM address 0218b850. No matching claim. */
#include "types.h"
#include "deps/0218b850_FUN_0218b850.h"

undefined4 FUN_0218b850(int param_1)

{
  int iVar1;
  
  iVar1 = func_0x0209b620(*(undefined4 *)(param_1 + DAT_0218b8bc));
  if (iVar1 == 0x4d) {
    FUN_02187af4(param_1);
    FUN_02187518(param_1,DAT_0218b8c4,0,DAT_0218b8c4,DAT_0218b8c0,0);
    func_0x020d2774(param_1,DAT_0218b8c8);
  }
  else {
    iVar1 = func_0x0209b620(*(undefined4 *)(param_1 + DAT_0218b8bc));
    if (iVar1 == 0x68) {
      FUN_02187af4(param_1);
      FUN_02187518(param_1,DAT_0218b8c4,0,DAT_0218b8c4,DAT_0218b8cc,0);
      func_0x020d2774(param_1,DAT_0218b8d0);
    }
  }
  return 0;
}

