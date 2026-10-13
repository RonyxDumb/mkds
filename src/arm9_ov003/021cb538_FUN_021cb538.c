/* Decompiled C draft; module arm9_ov003; ROM address 021cb538. No matching claim. */
#include "types.h"
#include "deps/021cb538_FUN_021cb538.h"

void FUN_021cb538(void)

{
  int iVar1;
  
  iVar1 = FUN_021bf334();
  if (iVar1 == 0) {
    FUN_021cdc10(7);
  }
  else {
    if (iVar1 != 1) {
      return;
    }
    FUN_021cdc10(6);
    FUN_021cb2e0();
    *DAT_021cb574 = 1;
  }
  FUN_021c212c(DAT_021cb578);
  return;
}

