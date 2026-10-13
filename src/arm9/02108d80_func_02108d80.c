/* Decompiled C draft; module arm9; ROM address 02108d80. No matching claim. */
#include "types.h"
#include "deps/02108d80_func_02108d80.h"

void func_02108d80(void)

{
  undefined4 uVar1;
  
  Sound_MaybeSetActiveSdat(uRam02108dc8);
  func_0212c6f0(uRam02108dcc,0xd);
  uVar1 = uRam02108dd4;
  *puRam02108dd0 = 0;
  func_0212c6f0(uVar1,1);
  Sound_MaybeSetActiveSdat(uRam02108dd8);
  return;
}

