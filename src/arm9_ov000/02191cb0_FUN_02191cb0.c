/* Decompiled C draft; module arm9_ov000; ROM address 02191cb0. No matching claim. */
#include "types.h"
#include "deps/02191cb0_FUN_02191cb0.h"

int FUN_02191cb0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,char *param_6,char *param_7,int param_8,int param_9,
                undefined4 param_10,undefined4 param_11,undefined4 param_12,undefined4 param_13)

{
  int iVar1;
  int iVar2;
  int local_18;
  
  iVar2 = *param_1;
  if ((*(int *)(iVar2 + DAT_02191e20) != 4) || (iVar1 = FUN_0218f654(), iVar1 == 0)) {
    if (*(int *)(iVar2 + DAT_02191e20) != 0) {
      FUN_02196590(param_1,DAT_02191e24);
      return 2;
    }
    if (param_9 == 0) {
      *(undefined4 *)(iVar2 + DAT_02191e28) = 0;
    }
    else {
      if (param_9 != 1) {
        FUN_02196590(param_1,DAT_02191e2c);
        return 2;
      }
      *(undefined4 *)(iVar2 + DAT_02191e28) = 1;
    }
    *(undefined4 *)(iVar2 + DAT_02191e28) = 1;
    FUN_02196914(iVar2 + DAT_02191e30,param_2,0x1f);
    FUN_02196914(iVar2 + DAT_02191e34,param_3,0x15);
    FUN_02196914(iVar2 + DAT_02191e38,param_4,0x33);
    FUN_02196914(iVar2 + DAT_02191e3c,param_5,0x1f);
    FUN_0218e850((char *)(uintptr_t)(iVar2 + DAT_02191e38));
    iVar2 = FUN_021a3690(DAT_02191e40);
    if (iVar2 == 0) {
      FUN_02196590(param_1,DAT_02191e44);
      return 1;
    }
    func_0x02134de0(iVar2,0,DAT_02191e40);
    *(undefined4 *)(iVar2 + DAT_02191e48) = param_10;
    if ((*param_6 != '\0') && (*param_7 != '\0')) {
      FUN_02196914(iVar2 + 0xc2,(int)(uintptr_t)(param_6),DAT_02191e4c);
      FUN_02196914(iVar2 + DAT_02191e50,(int)(uintptr_t)(param_7),DAT_02191e4c);
    }
    if (param_8 != 0) {
      FUN_02196914(iVar2 + DAT_02191e54,param_8,0x41);
    }
    iVar1 = FUN_021938cc(param_1,0,iVar2,&local_18,param_11,param_12,param_13);
    if (iVar1 == 0) {
      iVar2 = FUN_02191e58(param_1,local_18);
      if (iVar2 != 0) {
        *(int *)(local_18 + 0x1c) = iVar2;
        FUN_02193954(param_1,(undefined4 *)(uintptr_t)(local_18));
        FUN_02190ff8(param_1,0);
        return iVar2;
      }
      if ((*(int *)(local_18 + 8) == 0) ||
         (iVar1 = FUN_0218f2e8(param_1,*(undefined4 *)(local_18 + 0x18)), iVar1 == 0)) {
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}

