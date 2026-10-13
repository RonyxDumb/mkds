/* Decompiled C draft; module arm9_ov000; ROM address 0218f960. No matching claim. */
#include "types.h"
#include "deps/0218f960_FUN_0218f960.h"

undefined4 FUN_0218f960(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 *local_18 [2];
  
  iVar4 = *param_1;
  iVar1 = FUN_02194934(param_1,param_2,(int *)(void *)(local_18));
  if (iVar1 == 0) {
    FUN_02196590(param_1,DAT_0218fa60);
    return 2;
  }
  FUN_02190b80((undefined4)(uintptr_t)(param_1),iVar4 + DAT_0218fa64,DAT_0218fa68);
  FUN_02190b80((undefined4)(uintptr_t)(param_1),iVar4 + DAT_0218fa64,DAT_0218fa6c);
  FUN_02190b58(param_1,iVar4 + DAT_0218fa64,*(undefined4 *)(iVar4 + DAT_0218fa70));
  FUN_02190b80((undefined4)(uintptr_t)(param_1),iVar4 + DAT_0218fa64,DAT_0218fa74);
  FUN_02190b58(param_1,iVar4 + DAT_0218fa64,*local_18[0]);
  FUN_02190b80((undefined4)(uintptr_t)(param_1),iVar4 + DAT_0218fa64,DAT_0218fa78);
  if ((int *)local_18[0][2] != (int *)0x0) {
    iVar1 = *(int *)local_18[0][2];
    if (iVar1 < 0) {
      func_0x0213442c(DAT_0218fa7c,DAT_0218fa80,0,DAT_0218fa84);
    }
    FUN_021a3668(*(undefined4 *)(local_18[0][2] + 8));
    *(undefined4 *)(local_18[0][2] + 8) = 0;
    FUN_021a3668(*(undefined4 *)(local_18[0][2] + 0xc));
    *(undefined4 *)(local_18[0][2] + 0xc) = 0;
    FUN_021a3668(local_18[0][2]);
    local_18[0][2] = 0;
    iVar2 = FUN_021947e4((int)(uintptr_t)(local_18[0]));
    if (iVar2 != 0) {
      FUN_021948f8(param_1,local_18[0]);
    }
    piVar3 = (int *)(iVar4 + DAT_0218fa88);
    *piVar3 = *piVar3 + -1;
    if (*piVar3 < 0) {
      func_0x0213442c(DAT_0218fa8c,DAT_0218fa80,0,DAT_0218fa90);
    }
    FUN_02194840(param_1,DAT_0218fa94,iVar1);
  }
  return 0;
}

