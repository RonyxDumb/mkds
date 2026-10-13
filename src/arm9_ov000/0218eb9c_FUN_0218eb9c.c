/* Decompiled C draft; module arm9_ov000; ROM address 0218eb9c. No matching claim. */
#include "types.h"
#include "deps/0218eb9c_FUN_0218eb9c.h"

undefined4 FUN_0218eb9c(int *param_1,undefined4 param_2)

{
  int iVar1;
  int local_8 [2];
  
  if ((param_1 == (int *)0x0) || (*param_1 == 0)) {
    return 0;
  }
  if (*(int *)(*param_1 + DAT_0218ebe4) != 0) {
    return 0;
  }
  iVar1 = FUN_02194934(param_1,param_2,local_8);
  if ((iVar1 != 0) && (*(int *)(local_8[0] + 8) != 0)) {
    return 1;
  }
  return 0;
}

