/* Decompiled C draft; module arm9_ov000; ROM address 02189e80. No matching claim. */
#include "types.h"
#include "deps/02189e80_FUN_02189e80.h"

int FUN_02189e80(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = FUN_02188584(0x10);
  iVar2 = FUN_02188528();
  iVar3 = FUN_021a5bfc();
  if ((iVar2 == 2) && (iVar3 == 3)) {
    iVar2 = FUN_02189cdc(uVar1);
  }
  else if (iVar2 == 6) {
    iVar2 = FUN_021898dc(uVar1,6);
  }
  else if (((iVar3 == 3) || (iVar3 == 6)) && (iVar2 = FUN_021898dc(uVar1,iVar2), iVar2 != 7)) {
    if (iVar2 == 3) {
      iVar2 = FUN_02189c50(uVar1);
    }
    else if (iVar2 == 4) {
      iVar2 = FUN_02189b28(uVar1);
    }
    else if (iVar2 == 5) {
      iVar2 = FUN_02189a28(uVar1);
    }
  }
  return iVar2;
}

