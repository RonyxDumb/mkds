/* Decompiled C draft; module arm9_ov003; ROM address 021bf8c0. No matching claim. */
#include "types.h"
#include "deps/021bf8c0_FUN_021bf8c0.h"

void FUN_021bf8c0(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_021d285c(0xc0,4);
  *DAT_021bf90c = uVar1;
  FUN_021bf620(DAT_021bf910,DAT_021bf914);
  iVar2 = FUN_021c20c0();
  if (iVar2 == 0) {
    FUN_021bf620(*DAT_021bf918,DAT_021bf91c);
    return;
  }
  if (iVar2 != 1) {
    return;
  }
  FUN_021bf620(DAT_021bf918[1],DAT_021bf91c);
  return;
}

