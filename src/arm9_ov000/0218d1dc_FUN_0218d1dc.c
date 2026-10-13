/* Decompiled C draft; module arm9_ov000; ROM address 0218d1dc. No matching claim. */
#include "types.h"
#include "deps/0218d1dc_FUN_0218d1dc.h"

void FUN_0218d1dc(int param_1)

{
  int iVar1;
  int local_18 [2];
  
  local_18[0] = *(int *)(param_1 + DAT_0218d214);
  if (local_18[0] != 0) {
    while (local_18[0] != 0) {
      iVar1 = FUN_0218b220(local_18[0]);
      FUN_0218b3ac(local_18);
      local_18[0] = iVar1;
    }
    *(undefined4 *)(param_1 + DAT_0218d214) = 0;
  }
  return;
}

