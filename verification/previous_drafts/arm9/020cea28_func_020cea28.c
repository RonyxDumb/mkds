/* Decompiled C draft; module arm9; ROM address 020cea28. No matching claim. */
#include "types.h"
#include "deps/020cea28_func_020cea28.h"

void func_020cea28(void)

{
  int iVar1;
  
  iVar1 = func_020cccc0();
  if (iVar1 != 0) {
    func_020ce760(0xb);
    ConfigureDispcntDisplay(1,0,1);
    GXS_SetGraphicsMode__mkds_ce744(8);
    SetDispcntSubBgMode(0);
  }
  GXS_SetGraphicsMode__mkds_ce744(0x12);
  func_02026058();
  return;
}

