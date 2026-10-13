/* Decompiled C draft; module arm9_ov003; ROM address 021c30f0. No matching claim. */
#include "types.h"
#include "deps/021c30f0_FUN_021c30f0.h"

void FUN_021c30f0(void)

{
  int iVar1;
  
  iVar1 = FUN_021cef80();
  if (iVar1 == 0) {
    FUN_021cdc10(7);
  }
  else {
    if (iVar1 != 1) {
      return;
    }
    FUN_021cdc10(0xe);
    *DAT_021c3124 = 1;
  }
  FUN_021cef90();
  FUN_021c212c(DAT_021c3128);
  return;
}

