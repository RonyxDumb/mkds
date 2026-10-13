/* Decompiled C draft; module arm9_ov003; ROM address 021ca20c. No matching claim. */
#include "types.h"
#include "deps/021ca20c_FUN_021ca20c.h"

void FUN_021ca20c(void)

{
  int iVar1;
  
  iVar1 = FUN_021c2938();
  if (iVar1 == 1) {
    *DAT_021ca264 = 1;
    FUN_021c212c(DAT_021ca268);
    return;
  }
  if (iVar1 != 4) {
    return;
  }
  *DAT_021ca264 = 0;
  FUN_021cdbd0();
  FUN_021cdc10(9);
  FUN_021cefc0(0x41,1,1,0xffffffff,0);
  FUN_021bf2d0();
  FUN_021c212c(DAT_021ca26c);
  return;
}

