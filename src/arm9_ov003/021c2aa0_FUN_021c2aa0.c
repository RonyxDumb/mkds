/* Decompiled C draft; module arm9_ov003; ROM address 021c2aa0. No matching claim. */
#include "types.h"
#include "deps/021c2aa0_FUN_021c2aa0.h"

void FUN_021c2aa0(void)

{
  int iVar1;
  
  iVar1 = FUN_021d1f70(1);
  if ((iVar1 == 0) && (iVar1 = FUN_021d1f70(0), iVar1 == 0)) {
    iVar1 = FUN_021c20c0();
    if (iVar1 == 0) {
      FUN_021c2120(0,1);
      FUN_021c212c(DAT_021c2af4);
      return;
    }
    if (iVar1 != 1) {
      return;
    }
    FUN_021c2120(1,1);
    FUN_021c212c(DAT_021c2af8);
  }
  return;
}

