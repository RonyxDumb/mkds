/* Decompiled C draft; module arm9_ov000; ROM address 0218dd38. No matching claim. */
#include "types.h"
#include "deps/0218dd38_FUN_0218dd38.h"

void FUN_0218dd38(int param_1)

{
  undefined4 uVar1;
  
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + *(int *)(param_1 + 0xc);
  uVar1 = FUN_021a3678(*(undefined4 *)(param_1 + 0x14),*(int *)(param_1 + 8) * *(int *)(param_1 + 4)
                      );
  *(undefined4 *)(param_1 + 0x14) = uVar1;
  if (*(int *)(param_1 + 0x14) == 0) {
    func_0x0213442c(DAT_0218dd6c,DAT_0218dd70,0,0x41);
  }
  return;
}

