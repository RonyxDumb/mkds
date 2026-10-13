/* Decompiled C draft; module arm9_ov000; ROM address 0218dfb4. No matching claim. */
#include "types.h"
#include "deps/0218dfb4_FUN_0218dfb4.h"

void FUN_0218dfb4(int *param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == (int *)0x0) {
    func_0x0213442c(DAT_0218dffc,DAT_0218e000,0,0x51);
  }
  else {
    iVar2 = 0;
    if (0 < param_1[1]) {
      iVar1 = 0;
      do {
        FUN_0218dc48((int *)(uintptr_t)(*(undefined4 *)(*param_1 + iVar1)));
        iVar1 = iVar1 + 4;
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_1[1]);
    }
    FUN_021a3668(*param_1);
    FUN_021a3668((undefined4)(uintptr_t)(param_1));
  }
  return;
}

