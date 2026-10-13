/* Decompiled C draft; module arm9; ROM address 020cec00. No matching claim. */
#include "types.h"
#include "deps/020cec00_func_020cec00.h"

void func_020cec00(void)

{
  int iVar1;
  
  iVar1 = func_020cccc0();
  if (iVar1 != 0) {
    GXS_SetGraphicsMode__mkds_ceb54(0x1f);
    SetDispcntSubBgMode(0);
  }
  func_0211a794();
  return;
}

