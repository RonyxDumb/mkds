/* Decompiled C draft; module arm9_ov000; ROM address 0218e908. No matching claim. */
#include "types.h"
#include "deps/0218e908_FUN_0218e908.h"

undefined4 FUN_0218e908(int *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_1 == (int *)0x0) || (iVar2 = *param_1, iVar2 == 0)) {
    return 2;
  }
  if (*(int *)(iVar2 + DAT_0218e964) != 0) {
    return 0;
  }
  if (*(int *)(iVar2 + DAT_0218e968) == 4) {
    FUN_02196590(param_1,DAT_0218e96c);
    return 2;
  }
  if (param_3 == 0) {
    FUN_02196590(param_1,DAT_0218e970);
    return 2;
  }
  uVar1 = FUN_0218fb3c(param_1,param_2,1);
  return uVar1;
}

