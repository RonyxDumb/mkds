/* Decompiled C draft; module arm9; ROM address 020cecdc. No matching claim. */
#include "types.h"
#include "deps/020cecdc_func_020cecdc.h"

void func_020cecdc(void)

{
  int iVar1;
  
  iVar1 = func_020cccc0();
  if (iVar1 != 0) {
    func_020ceb70(0x18);
    ConfigureDispcntDisplay(1,0,0);
    GXS_SetGraphicsMode__mkds_ceb54(0x12);
    SetDispcntSubBgMode(0);
  }
  func_02032138();
  return;
}

