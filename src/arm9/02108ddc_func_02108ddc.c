/* Decompiled C draft; module arm9; ROM address 02108ddc. No matching claim. */
#include "types.h"
#include "deps/02108ddc_func_02108ddc.h"

void func_02108ddc(void)

{
  undefined4 uVar1;
  
  Sound_MaybeSetActiveSdat(uRam02108e24);
  func_0212c6f0(uRam02108e28,1);
  func_0212c6f0(uRam02108e2c,1);
  uVar1 = uRam02108e34;
  *puRam02108e30 = 1;
  Sound_MaybeSetActiveSdat(uVar1);
  return;
}

