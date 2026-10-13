/* Decompiled C draft; module arm9_ov003; ROM address 021d0708. No matching claim. */
#include "types.h"
#include "deps/021d0708_FUN_021d0708.h"

void FUN_021d0708(int param_1)

{
  int iVar1;
  
  if (*(short *)(param_1 + 2) != 0) {
    FUN_021d079c();
    FUN_021d07b0(9);
    return;
  }
  if (*(int *)(*DAT_021d0758 + DAT_021d075c) == 0) {
    iVar1 = FUN_021d0630();
    if (iVar1 == 0) {
      FUN_021d07b0(9);
    }
  }
  else {
    iVar1 = FUN_021d06b0();
    if (iVar1 == 0) {
      FUN_021d07b0(9);
      return;
    }
  }
  return;
}

