/* Decompiled C draft; module arm9; ROM address 020ce974. No matching claim. */
#include "types.h"
#include "deps/020ce974_func_020ce974.h"

void func_020ce974(void)

{
  int iVar1;
  
  iVar1 = func_020cccc0();
  if (iVar1 != 0) {
    GXS_SetGraphicsMode__mkds_ce744(0x1f);
    SetDispcntSubBgMode(0);
  }
  func_0211a794();
  return;
}

