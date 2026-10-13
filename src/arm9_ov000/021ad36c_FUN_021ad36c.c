/* Decompiled C draft; module arm9_ov000; ROM address 021ad36c. No matching claim. */
#include "types.h"
#include "deps/021ad36c_FUN_021ad36c.h"

undefined4 FUN_021ad36c(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  FUN_021ae270();
  FUN_021ae2d8();
  FUN_021ae290(0x44,0x43,0xffffffff);
  iVar3 = 0;
  do {
    uVar1 = FUN_021ad6c0();
    iVar2 = FUN_021ad3b8(uVar1,iVar3);
    if (iVar2 == 1) break;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  FUN_021ae258();
  if (iVar2 == 1) {
    return 1;
  }
  return 0;
}

