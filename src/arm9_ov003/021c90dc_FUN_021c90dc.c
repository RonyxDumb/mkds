/* Decompiled C draft; module arm9_ov003; ROM address 021c90dc. No matching claim. */
#include "types.h"
#include "deps/021c90dc_FUN_021c90dc.h"

void FUN_021c90dc(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_021c8904();
  if (iVar1 == 0) {
    FUN_021cdc10(9);
    return;
  }
  switch(param_1) {
  case 2:
  case 3:
    FUN_021cdc10(6);
    FUN_021c9084(param_1 != 3);
    return;
  case 7:
  case 8:
    FUN_021cdc10(6);
    FUN_021c9058(param_1 != 8);
    return;
  }
  *(char *)(*DAT_021c91ec + 0x40) = (char)param_1;
  if (param_1 - 0xbU < 2) {
    FUN_021c7ec4();
    iVar1 = FUN_021c7d8c();
    if (iVar1 == 0) {
      FUN_021cdc10(9);
      FUN_021cefc0(0x2f,1,1,0xffffffff,0);
      FUN_021c212c(DAT_021c91f0);
      return;
    }
    if (param_1 == 0xb) {
      FUN_021cdc10(6);
    }
    else {
      FUN_021cdc10(0xe);
    }
  }
  else if (param_1 == 0xd) {
    FUN_021c7ec4();
    FUN_021cdc10(7);
  }
  else {
    FUN_021cdc10(6);
    uVar2 = FUN_021c83cc(*(undefined1 *)(DAT_021c91f4 + param_1));
    FUN_021c8838(0,1,uVar2);
    FUN_021c85a0();
  }
  FUN_021cce38();
  FUN_021c212c(DAT_021c91f8);
  return;
}

