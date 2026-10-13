/* Decompiled C draft; module arm9_ov003; ROM address 021c4914. No matching claim. */
#include "types.h"
#include "deps/021c4914_FUN_021c4914.h"

void FUN_021c4914(void)

{
  int iVar1;
  
  iVar1 = FUN_021bf334();
  if (iVar1 == 0) {
    *DAT_021c494c = 0;
    FUN_021cdc10(7);
  }
  else {
    if (iVar1 != 1) {
      return;
    }
    *DAT_021c494c = 1;
    FUN_021cdc10(6);
  }
  FUN_021c212c(DAT_021c4950);
  return;
}

