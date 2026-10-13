/* Decompiled C draft; module arm9_ov000; ROM address 0218ed74. No matching claim. */
#include "types.h"
#include "deps/0218ed74_FUN_0218ed74.h"

undefined4 FUN_0218ed74(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int local_10;
  
  if ((param_1 == (int *)0x0) || (iVar2 = *param_1, iVar2 == 0)) {
    return 2;
  }
  if (*(int *)(iVar2 + DAT_0218ee0c) != 0) {
    return 0;
  }
  if (*(int *)(iVar2 + DAT_0218ee10) == 4) {
    FUN_02196590(param_1,DAT_0218ee14);
    return 2;
  }
  iVar1 = FUN_02194934(param_1,param_2,&local_10);
  if (iVar1 == 0) {
    return 0;
  }
  *(int *)(local_10 + 0x14) = *(int *)(local_10 + 0x14) + -1;
  if ((*(int *)(iVar2 + DAT_0218ee18) == 0) && (*(int *)(local_10 + 0x14) < 1)) {
    FUN_021a3668(*(undefined4 *)(local_10 + 0x10));
    *(undefined4 *)(local_10 + 0x10) = 0;
    iVar2 = FUN_021947e4(local_10);
    if (iVar2 != 0) {
      FUN_021948f8(param_1,local_10);
    }
  }
  return 0;
}

