/* Decompiled C draft; module arm9_ov000; ROM address 0219490c. No matching claim. */
#include "types.h"
#include "deps/0219490c_FUN_0219490c.h"

void FUN_0219490c(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_10 [2];
  
  iVar2 = *param_1;
  iVar1 = FUN_02194934(param_1,param_2,local_10);
  if (iVar1 != 0) {
    FUN_0218de8c(*(undefined4 *)(iVar2 + DAT_02194930),local_10[0]);
  }
  return;
}

