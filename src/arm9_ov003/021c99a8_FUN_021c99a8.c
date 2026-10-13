/* Decompiled C draft; module arm9_ov003; ROM address 021c99a8. No matching claim. */
#include "types.h"
#include "deps/021c99a8_FUN_021c99a8.h"

void FUN_021c99a8(void)

{
  int iVar1;
  
  iVar1 = FUN_021c2938();
  if (iVar1 == 2) {
    *DAT_021c9a00 = 1;
    FUN_021c212c(DAT_021c9a04);
    return;
  }
  if (iVar1 != 4) {
    return;
  }
  *DAT_021c9a00 = 0;
  FUN_021cdbd0();
  FUN_021cdc10(9);
  FUN_021cefc0(0x41,1,1,0xffffffff,0);
  FUN_021bf2d0();
  FUN_021c212c(DAT_021c9a08);
  return;
}

