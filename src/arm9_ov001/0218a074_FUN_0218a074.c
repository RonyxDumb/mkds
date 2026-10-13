/* Decompiled C draft; module arm9_ov001; ROM address 0218a074. No matching claim. */
#include "types.h"
#include "deps/0218a074_FUN_0218a074.h"

void FUN_0218a074(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  
  if (*(int *)(*DAT_0218a11c + 8) == 4) {
    iVar1 = func_0x020a126c();
  }
  else {
    iVar1 = 0;
  }
  if (iVar1 == 0) {
    iVar1 = FUN_021871f8(param_2,3);
    if ((iVar1 != 0) && (uVar2 = FUN_02188220(param_2), 1 < uVar2)) {
      FUN_0218ab04(param_2);
    }
    iVar1 = FUN_021871f8(param_2,3);
    if (iVar1 != 0) {
      FUN_0218a75c(param_2);
    }
    iVar1 = FUN_021871f8(param_2,2);
    if (iVar1 != 0) {
      FUN_0218a60c(param_2);
    }
  }
  else {
    iVar1 = FUN_021871f8(param_2,1);
    if (iVar1 != 0) {
      if (*(int *)(*DAT_0218a11c + 8) == 4) {
        iVar1 = func_0x020a1084((short)*(char *)(*DAT_0218a11c + 0x62));
      }
      else {
        iVar1 = 0;
      }
      if (iVar1 == 0) {
        FUN_0218a2dc(param_2);
      }
      else {
        FUN_0218a3ec(param_2);
      }
    }
  }
  FUN_021864ac(param_1,param_2);
  return;
}

