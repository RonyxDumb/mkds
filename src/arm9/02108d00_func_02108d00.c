/* Decompiled C draft; module arm9; ROM address 02108d00. No matching claim. */
#include "types.h"
#include "deps/02108d00_func_02108d00.h"

void func_02108d00(void)

{
  undefined4 uVar1;
  
  func_0212c6f0(uRam02108d68,1);
  uVar1 = uRam02108d70;
  *puRam02108d6c = 0;
  func_0212c6f0(uVar1,1);
  Sound_MaybeSetActiveSdat(uRam02108d74);
  Sound_MaybeSetActiveSdat(uRam02108d74);
  NNSi_MaybeSndPlayerStartSeq(uRam02108d78,0,1);
  Sound_MaybeSetActiveSdat(uRam02108d7c);
  Sound_MaybeSetActiveSdat(uRam02108d7c);
  return;
}

