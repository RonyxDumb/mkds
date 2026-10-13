/* Decompiled C draft; module arm9_ov001; ROM address 0218a910. No matching claim. */
#include "types.h"
#include "deps/0218a910_FUN_0218a910.h"

void FUN_0218a910(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_02187c4c();
  if (iVar1 != 0) {
    FUN_02187218(param_1,3,0);
    FUN_02188d30(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xd4),
                 *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xd8),0);
    FUN_02188cec(param_1,0);
    FUN_02188e74(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xdc),DAT_0218a968);
    func_0x020d2774(param_1,DAT_0218a96c);
  }
  return;
}

