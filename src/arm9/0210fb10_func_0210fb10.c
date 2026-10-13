/* Decompiled C draft; module arm9; ROM address 0210fb10. No matching claim. */
#include "types.h"
#include "deps/0210fb10_func_0210fb10.h"

void func_0210fb10(void)

{
  undefined4 uVar1;
  
  uVar1 = uRam0210fb50;
  *puRam0210fb4c = 2;
  NNS_SndPlayerSetTrackMute(uVar1,1,1);
  func_0212c494(uRam0210fb50,0xd9);
  return;
}

