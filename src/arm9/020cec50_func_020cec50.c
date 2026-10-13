/* Decompiled C draft; module arm9; ROM address 020cec50. No matching claim. */
#include "types.h"
#include "deps/020cec50_func_020cec50.h"

void func_020cec50(void)

{
  int iVar1;
  
  iVar1 = func_020cccc0();
  if (iVar1 != 0) {
    func_020ceb70(0xb);
    ConfigureDispcntDisplay(1,0,1);
    GXS_SetGraphicsMode__mkds_ceb54(8);
    SetDispcntSubBgMode(0);
  }
  GXS_SetGraphicsMode__mkds_ceb54(0x12);
  func_02026058();
  return;
}

