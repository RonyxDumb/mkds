/* Decompiled C draft; module arm9_ov000; ROM address 021907e8. No matching claim. */
#include "types.h"
#include "deps/021907e8_FUN_021907e8.h"

undefined4
FUN_021907e8(undefined4 param_1,int param_2,int *param_3,int *param_4,int *param_5,
            undefined4 param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_30;
  int local_2c;
  
  if (param_2 == -1) {
    func_0x0213442c(DAT_0219092c,DAT_02190930,0,DAT_02190934);
  }
  if (param_3 == (int *)0x0) {
    func_0x0213442c(DAT_02190938,DAT_02190930,0,DAT_0219093c);
  }
  if (param_4 == (int *)0x0) {
    func_0x0213442c(DAT_02190940,DAT_02190930,0,DAT_02190944);
  }
  if (param_5 == (int *)0x0) {
    func_0x0213442c(DAT_02190948,DAT_02190930,0,DAT_0219094c);
  }
  iVar4 = *param_3;
  iVar3 = param_3[2];
  local_30 = param_3[1];
  iVar5 = 0;
  local_2c = 0;
  do {
    iVar2 = iVar3 + DAT_02190950;
    if (local_30 < iVar2) {
      iVar4 = FUN_021a3678(iVar4,iVar2 + 1);
      local_30 = iVar2;
      if (iVar4 == 0) {
        FUN_02196590(param_1,DAT_02190954);
        return 1;
      }
    }
    iVar2 = FUN_0218e460(param_2,iVar4 + iVar3,local_30 - iVar3,0);
    if (iVar2 == -1) {
      iVar1 = FUN_0218e368(param_2);
      if (((iVar1 != -6) && (iVar1 != -0x1a)) && (iVar1 != -0x4c)) {
        FUN_02196590(param_1,DAT_02190958);
        return 3;
      }
    }
    else if (iVar2 == 0) {
      local_2c = 1;
      FUN_0219690c(param_1,DAT_0219095c,param_6);
    }
    else {
      iVar3 = iVar3 + iVar2;
      iVar5 = iVar5 + iVar2;
    }
    *(undefined1 *)(iVar4 + iVar3) = 0;
  } while (((iVar2 != -1) && (local_2c == 0)) && (iVar5 < DAT_02190960));
  if (iVar5 != 0) {
    FUN_0219690c(param_1,DAT_02190964,param_6,iVar5);
  }
  *param_3 = iVar4;
  param_3[2] = iVar3;
  param_3[1] = local_30;
  *param_4 = iVar5;
  *param_5 = local_2c;
  return 0;
}

