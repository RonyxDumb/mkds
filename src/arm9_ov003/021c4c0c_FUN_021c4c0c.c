/* Decompiled C draft; module arm9_ov003; ROM address 021c4c0c. No matching claim. */
#include "types.h"
#include "deps/021c4c0c_FUN_021c4c0c.h"

void FUN_021c4c0c(void)

{
  int iVar1;
  
  FUN_021c4c08();
  FUN_021c4c04();
  iVar1 = FUN_021cef80();
  if (iVar1 == 0) {
    *DAT_021c4c5c = 0;
    FUN_021cdc10(7);
  }
  else {
    if (iVar1 != 1) {
      return;
    }
    *DAT_021c4c5c = 1;
    FUN_021cdc10(0xe);
  }
  FUN_021c27d0(0);
  FUN_021cef90();
  FUN_021c212c(DAT_021c4c60);
  return;
}

