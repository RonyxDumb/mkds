/* Decompiled C draft; module arm9_ov003; ROM address 021cdc4c. No matching claim. */
#include "types.h"
#include "deps/021cdc4c_FUN_021cdc4c.h"

void FUN_021cdc4c(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_8 [8];
  
  iVar1 = FUN_021d285c(0x9c,4);
  *DAT_021cdcac = iVar1;
  uVar2 = FUN_021d14b8(DAT_021cdcb0,auStack_8,0x20);
  *(undefined4 *)(*DAT_021cdcac + 0x94) = uVar2;
  func_0x0212baa8();
  func_0x0212d5f8(*DAT_021cdcac,*(undefined4 *)(*DAT_021cdcac + 0x94));
  func_0x0212edac(0);
  func_0x0212c6a0(*DAT_021cdcac + 0x90);
  uVar2 = FUN_021d3544(0,DAT_021cdcb4,0,200);
  *(undefined4 *)(*DAT_021cdcac + 0x98) = uVar2;
  return;
}

