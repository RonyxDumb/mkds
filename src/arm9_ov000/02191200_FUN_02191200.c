/* Decompiled C draft; module arm9_ov000; ROM address 02191200. No matching claim. */
#include "types.h"
#include "deps/02191200_FUN_02191200.h"

int FUN_02191200(int *param_1)

{
  int iVar1;
  int iVar2;
  int local_10;
  
  iVar2 = *param_1;
  iVar1 = FUN_02196714((undefined4)(uintptr_t)(param_1),*(undefined4 *)(iVar2 + DAT_02191268),&local_10);
  if (iVar1 == 0) {
    if (local_10 == 4) {
      FUN_021965a0(param_1,DAT_0219126c,DAT_02191270);
      FUN_02190f4c(param_1,4,1);
      return 4;
    }
    if (local_10 == 0) {
      return 0;
    }
    if (local_10 != 3) {
      func_0x0213442c(DAT_02191274,DAT_02191278,0,DAT_0219127c);
    }
    *(undefined4 *)(iVar2 + DAT_02191280) = 2;
    iVar1 = 0;
  }
  return iVar1;
}

