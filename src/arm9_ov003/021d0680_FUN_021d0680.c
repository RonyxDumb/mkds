/* Decompiled C draft; module arm9_ov003; ROM address 021d0680. No matching claim. */
#include "types.h"
#include "deps/021d0680_FUN_021d0680.h"

void FUN_021d0680(int param_1)

{
  int iVar1;
  
  if (*(short *)(param_1 + 2) != 0) {
    FUN_021d079c();
    FUN_021d07b0(9);
    return;
  }
  iVar1 = FUN_021d0630();
  if (iVar1 == 0) {
    FUN_021d07b0(9);
  }
  return;
}

