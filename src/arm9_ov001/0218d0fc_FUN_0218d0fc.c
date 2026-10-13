/* Decompiled C draft; module arm9_ov001; ROM address 0218d0fc. No matching claim. */
#include "types.h"
#include "deps/0218d0fc_FUN_0218d0fc.h"

undefined4 FUN_0218d0fc(int param_1)

{
  int iVar1;
  
  iVar1 = func_0x0209b620(*(undefined4 *)(param_1 + DAT_0218d158));
  if (iVar1 == 0x33) {
    FUN_02187af4(param_1);
    FUN_021875c0(param_1,DAT_0218d160,0,DAT_0218d164,DAT_0218d15c,0);
  }
  else {
    iVar1 = func_0x0209b620(*(undefined4 *)(param_1 + DAT_0218d158));
    if (iVar1 == 0x66) {
      FUN_02187af4(param_1);
      FUN_021875c0(param_1,DAT_0218d168,0,DAT_0218d164,DAT_0218d15c,0);
    }
  }
  return 0;
}

