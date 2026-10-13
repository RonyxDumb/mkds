/* Decompiled C draft; module arm9; ROM address 020ce9c4. No matching claim. */
#include "types.h"
#include "deps/020ce9c4_func_020ce9c4.h"

void func_020ce9c4(void)

{
  int iVar1;
  
  iVar1 = func_020cccc0();
  if (iVar1 != 0) {
    func_020ce760(0xb);
    ConfigureDispcntDisplay(1,0,1);
  }
  GXS_SetGraphicsMode__mkds_ce744(0x12);
  func_02027e78();
  return;
}

