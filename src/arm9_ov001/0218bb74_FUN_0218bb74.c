/* Decompiled C draft; module arm9_ov001; ROM address 0218bb74. No matching claim. */
#include "types.h"
#include "deps/0218bb74_FUN_0218bb74.h"

undefined4 FUN_0218bb74(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_02188220();
  if (iVar1 == 1) {
    func_0x020d275c(param_1,DAT_0218bba4);
  }
  else {
    iVar1 = FUN_02188220(param_1);
    if (iVar1 == 2) {
      func_0x020d275c(param_1,DAT_0218bba8);
    }
  }
  return 0;
}

