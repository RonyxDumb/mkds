/* Decompiled C draft; module arm9_ov001; ROM address 0218aa34. No matching claim. */
#include "types.h"
#include "deps/0218aa34_FUN_0218aa34.h"

void FUN_0218aa34(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_02187c4c();
  if ((iVar1 == 0) && (iVar1 = func_0x020fd428(), iVar1 != 0)) {
    FUN_02187c60(param_1);
  }
  iVar1 = FUN_02187c4c(param_1);
  if (iVar1 != 0) {
    FUN_02187218(param_1,3,0);
    FUN_02188d30(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xd4),
                 *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xd8),0);
    FUN_02188cec(param_1,0);
    FUN_02188e74(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xdc),DAT_0218aaa4);
  }
  func_0x020d2774(param_1,DAT_0218aaa8);
  return;
}

