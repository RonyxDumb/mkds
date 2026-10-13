/* Decompiled C draft; module arm9_ov001; ROM address 02184d9c. No matching claim. */
#include "types.h"
#include "deps/02184d9c_FUN_02184d9c.h"

void FUN_02184d9c(int param_1)

{
  int iVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  iVar1 = FUN_0218820c();
  if (iVar1 != 0) {
    local_18 = 0;
    local_10 = 0;
    local_14 = *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02184e08);
    FUN_02187218(param_1,5);
    FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02184e0c),
                 *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02184e10));
    FUN_02188950(param_1,&local_18);
    FUN_02188db8(param_1,DAT_02184e14);
    return;
  }
  FUN_02187218(param_1,0,0);
  return;
}

