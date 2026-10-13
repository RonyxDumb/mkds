/* Decompiled C draft; module arm9; ROM address 02027e78. No matching claim. */
#include "types.h"
#include "deps/02027e78_func_02027e78.h"

void func_02027e78(void)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0x16;
  iVar1 = func_02025ebc(*piRam02027f14 + 0xec);
  if (*(int *)(*piRam02027f14 + 0x94) != 8) {
    uVar2 = 0x1e;
  }
  func_02028074(0x19);
  GXS_SetGraphicsMode__mkds_28058(uVar2);
  func_0202802c(0,-iVar1);
  func_02028010(2);
  func_02027fd4(0,0x3f,6,10);
  if ((iVar1 == 0) || (*(int *)(*piRam02027f14 + 0x94) == 8)) {
    GXS_SetGraphicsMode(0);
  }
  else {
    GXS_SetGraphicsMode(1);
    func_02027f90(0x1f,1);
    func_02027f68(7,1);
    func_02027f1c(0,0,0xff,iVar1 + 0xc0);
  }
  if (*(int *)(*piRam02027f14 + iRam02027f18) != 0) {
    func_0202ba14();
  }
  return;
}

