/* Decompiled C draft; module arm9_ov003; ROM address 021c4500. No matching claim. */
#include "types.h"
#include "deps/021c4500_FUN_021c4500.h"

void FUN_021c4500(void)

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
    *DAT_021c4538 = 1;
  }
  FUN_021c212c(DAT_021c453c);
  return;
}

