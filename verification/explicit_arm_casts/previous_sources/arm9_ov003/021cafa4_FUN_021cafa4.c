/* Decompiled C draft; module arm9_ov003; ROM address 021cafa4. No matching claim. */
#include "types.h"
#include "deps/021cafa4_FUN_021cafa4.h"

void FUN_021cafa4(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  iVar3 = DAT_021cb064;
  do {
    iVar1 = FUN_021d2a34(iVar3);
    if (iVar1 != 0) {
      FUN_021bf31c(1);
      *DAT_021cb068 = (char)uVar2;
      FUN_021caca8();
      return;
    }
    iVar3 = iVar3 + 8;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 7);
  iVar3 = FUN_021d2b04(1);
  if (iVar3 != 0) {
    FUN_021bf31c(1);
    return;
  }
  iVar3 = FUN_021d2b04(2);
  if (iVar3 != 0) {
    FUN_021bf31c(0);
    return;
  }
  iVar3 = FUN_021d2ae8(0x40);
  if (iVar3 != 0) {
    FUN_021cab4c(1);
    return;
  }
  iVar3 = FUN_021d2ae8(0x80);
  if (iVar3 != 0) {
    FUN_021cab4c(3);
    return;
  }
  iVar3 = FUN_021d2ae8(0x20);
  if (iVar3 != 0) {
    FUN_021cab4c(0);
    return;
  }
  iVar3 = FUN_021d2ae8(0x10);
  if (iVar3 != 0) {
    FUN_021cab4c(2);
  }
  return;
}

