/* Decompiled C draft; module arm9_ov003; ROM address 021c321c. No matching claim. */
#include "types.h"
#include "deps/021c321c_FUN_021c321c.h"

void FUN_021c321c(void)

{
  int iVar1;
  
  iVar1 = FUN_021bf334();
  if (iVar1 == 0) {
    FUN_021cdc10(7);
    FUN_021c212c(DAT_021c3268);
    return;
  }
  if (iVar1 != 1) {
    return;
  }
  FUN_021cdc10(6);
  FUN_021cefc0(0x56,0,1,0xffffffff,0);
  FUN_021bf2d0();
  FUN_021c212c(DAT_021c326c);
  return;
}

