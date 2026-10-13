/* Decompiled C draft; module arm9_ov000; ROM address 021a9394. No matching claim. */
#include "types.h"
#include "deps/021a9394_FUN_021a9394.h"

void FUN_021a9394(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_2 + 0xc);
  iVar1 = *(int *)(iVar2 + DAT_021a93d4);
  if ((uint)(*(int *)(iVar2 + DAT_021a93d0) - iVar1) <= param_1) {
    (*(code *)*DAT_021a93dc)(*(undefined4 *)(iVar2 + DAT_021a93d8));
    *(undefined4 *)(iVar2 + DAT_021a93d8) = 0;
    *(undefined4 *)(iVar2 + DAT_021a93d4) = *(undefined4 *)(iVar2 + DAT_021a93d0);
    return;
  }
  *(int *)(iVar2 + DAT_021a93d4) = iVar1 + param_1;
  return;
}

