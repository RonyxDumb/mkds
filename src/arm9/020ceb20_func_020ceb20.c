/* Decompiled C draft; module arm9; ROM address 020ceb20. No matching claim. */
#include "types.h"
#include "deps/020ceb20_func_020ceb20.h"

void func_020ceb20(void)

{
  int iVar1;
  
  iVar1 = func_020cccc0();
  if (iVar1 != 0) {
    func_020ceb70(0x1e);
    ConfigureDispcntDisplay(1,0,0);
    GXS_SetGraphicsMode__mkds_ceb54(0x1f);
    SetDispcntSubBgMode(0);
  }
  func_0x0219c784();
  return;
}

