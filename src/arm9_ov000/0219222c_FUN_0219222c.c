/* Decompiled C draft; module arm9_ov000; ROM address 0219222c. No matching claim. */
#include "types.h"
#include "deps/0219222c_FUN_0219222c.h"

int FUN_0219222c(int *param_1,undefined4 param_2,int param_3,int param_4,int param_5,
                undefined4 param_6)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  
  local_24 = 0;
  if ((((param_5 == 0) || (*(int *)(*param_1 + DAT_02192324) == 0 || param_3 != 1)) ||
      (iVar1 = FUN_02194934(param_1,param_2,&local_28), iVar1 == 0)) ||
     (*(int *)(local_28 + 0xc) == 0)) {
    iVar1 = FUN_021938cc(param_1,2,0,&local_24,param_4,param_5,param_6);
    if (iVar1 != 0) {
      return iVar1;
    }
    uVar3 = *(undefined4 *)(local_24 + 0x18);
    iVar1 = FUN_02192330(param_1,param_2,uVar3);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  else {
    puVar2 = (undefined4 *)FUN_021a3690(DAT_02192328);
    if (puVar2 == (undefined4 *)0x0) {
      FUN_02196590(param_1,DAT_0219232c);
      return 1;
    }
    FUN_0219338c((int *)(uintptr_t)(*(undefined4 *)(local_28 + 0xc)),(int)(uintptr_t)(puVar2));
    *puVar2 = 0;
    puVar2[1] = param_2;
    local_20 = param_5;
    local_1c = param_6;
    iVar1 = FUN_021938cc(param_1,2,0,&local_24,1,param_5,param_6);
    if (iVar1 != 0) {
      return iVar1;
    }
    uVar3 = *(undefined4 *)(local_24 + 0x18);
    iVar1 = FUN_02190ed4(param_1,local_20,local_1c,(undefined4)(uintptr_t)(puVar2),local_24,0);
    if (iVar1 != 0) {
      return iVar1;
    }
    FUN_02193818(param_1,local_24);
  }
  if ((param_4 == 0) || (iVar1 = FUN_0218f2e8(param_1,uVar3), iVar1 == 0)) {
    iVar1 = 0;
  }
  return iVar1;
}

