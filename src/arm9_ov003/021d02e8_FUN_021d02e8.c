/* Decompiled C draft; module arm9_ov003; ROM address 021d02e8. No matching claim. */
#include "types.h"
#include "deps/021d02e8_FUN_021d02e8.h"

void FUN_021d02e8(int param_1)

{
  int iVar1;
  
  if (*(short *)(param_1 + 2) != 0) {
    FUN_021d079c();
    FUN_021cfb80();
    return;
  }
  iVar1 = FUN_021d02c0();
  if (iVar1 == 0) {
    if ((code *)*DAT_021d0320 != (code *)0x0) {
      (*(code *)*DAT_021d0320)(DAT_021d0324,DAT_021d0328);
    }
    FUN_021cfb80();
  }
  return;
}

