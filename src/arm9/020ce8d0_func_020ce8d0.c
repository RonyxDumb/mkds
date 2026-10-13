/* Decompiled C draft; module arm9; ROM address 020ce8d0. No matching claim. */
#include "types.h"
#include "deps/020ce8d0_func_020ce8d0.h"

void func_020ce8d0(void)

{
  int iVar1;
  
  iVar1 = func_020cccc0();
  if (iVar1 != 0) {
    iVar1 = func_020ce778();
    if (iVar1 == 0) {
      func_020ce760(0x19);
      ConfigureDispcntDisplay(1,0,0);
      GXS_SetGraphicsMode__mkds_ce744(0x16);
      SetDispcntSubBgMode(0);
    }
    else {
      func_020ce760(0x18);
      ConfigureDispcntDisplay(1,0,0);
      GXS_SetGraphicsMode__mkds_ce744(0x12);
      SetDispcntSubBgMode(0);
    }
  }
  func_021173e4();
  return;
}

