/* Decompiled C draft; module arm9_ov000; ROM address 0218faac. No matching claim. */
#include "types.h"
#include "deps/0218faac_FUN_0218faac.h"

int FUN_0218faac(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int local_10;
  
  iVar2 = *param_1;
  iVar1 = FUN_02194934(param_1,param_2,&local_10);
  if (iVar1 == 0) {
    FUN_02196590(param_1,DAT_0218fb34);
    return 2;
  }
  if (*(int *)(local_10 + 0x10) == 0) {
    FUN_02196590(param_1,DAT_0218fb34);
    return 2;
  }
  iVar1 = FUN_02190548(param_1);
  if (iVar1 == 0) {
    *(int *)(local_10 + 0x14) = *(int *)(local_10 + 0x14) + -1;
    if ((*(int *)(iVar2 + DAT_0218fb38) == 0) && (*(int *)(local_10 + 0x14) < 1)) {
      FUN_021a3668(*(undefined4 *)(local_10 + 0x10));
      *(undefined4 *)(local_10 + 0x10) = 0;
      iVar1 = FUN_021947e4(local_10);
      if (iVar1 != 0) {
        FUN_021948f8(param_1,local_10);
      }
    }
    iVar1 = 0;
  }
  return iVar1;
}

