/* Decompiled C draft; module arm9; ROM address 02108c80. No matching claim. */
#include "types.h"
#include "deps/02108c80_func_02108c80.h"

void func_02108c80(void)

{
  undefined4 uVar1;
  
  func_0212c6f0(uRam02108ce8,1);
  uVar1 = uRam02108cf0;
  *puRam02108cec = 0;
  func_0212c6f0(uVar1,1);
  Sound_MaybeSetActiveSdat(uRam02108cf4);
  Sound_MaybeSetActiveSdat(uRam02108cf4);
  NNSi_MaybeSndPlayerStartSeq(uRam02108cf8,0,1);
  Sound_MaybeSetActiveSdat(uRam02108cfc);
  Sound_MaybeSetActiveSdat(uRam02108cfc);
  return;
}

