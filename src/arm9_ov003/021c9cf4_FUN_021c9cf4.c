/* Decompiled C draft; module arm9_ov003; ROM address 021c9cf4. No matching claim. */
#include "types.h"
#include "deps/021c9cf4_FUN_021c9cf4.h"

void FUN_021c9cf4(void)

{
  int iVar1;
  
  iVar1 = FUN_021c2938();
  if (iVar1 == 3) {
    *DAT_021c9d88 = 1;
    FUN_021cdbd0();
    FUN_021c2918();
    FUN_021c212c(DAT_021c9d8c);
    return;
  }
  if (iVar1 != 4) {
    if (iVar1 != 5) {
      return;
    }
    *DAT_021c9d88 = 0;
    FUN_021cdbd0();
    FUN_021cdc10(0x12);
    FUN_021cefc0(0x42,1,1,0xffffffff,0);
    FUN_021bf2d0();
    FUN_021c212c(DAT_021c9d90);
    return;
  }
  *DAT_021c9d88 = 0;
  FUN_021cdbd0();
  FUN_021cdc10(9);
  FUN_021cefc0(0x41,1,1,0xffffffff,0);
  FUN_021bf2d0();
  FUN_021c212c(DAT_021c9d90);
  return;
}

