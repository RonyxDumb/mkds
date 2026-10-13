/* Decompiled C draft; module arm9_ov000; ROM address 0219a09c. No matching claim. */
#include "types.h"
#include "deps/0219a09c_FUN_0219a09c.h"

undefined4 FUN_0219a09c(int param_1)

{
  int iVar1;
  undefined4 local_10 [2];
  
  local_10[0] = FUN_0218e8c4();
  iVar1 = FUN_0218dd8c(*(undefined4 *)(param_1 + 0xc),DAT_0219a0cc,local_10);
  if (iVar1 == 0) {
    return 1;
  }
  return 0;
}

