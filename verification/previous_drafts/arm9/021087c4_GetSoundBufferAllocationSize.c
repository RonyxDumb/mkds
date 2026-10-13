/* Decompiled C draft; module arm9; ROM address 021087c4. No matching claim. */
#include "types.h"
#include "deps/021087c4_GetSoundBufferAllocationSize.h"

undefined4 GetSoundBufferAllocationSize(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 2) {
    uVar1 = 0xaf000;
  }
  else {
    uVar1 = 0xc400;
  }
  return uVar1;
}

