/* Decompiled C draft; module arm9; ROM address 02142a8c. No matching claim. */
#include "types.h"
#include "deps/02142a8c_Wm_CheckInitialized.h"

undefined4 Wm_CheckInitialized(void)

{
  undefined4 uVar1;
  
  if (*psRam02142aa4 == 0) {
    uVar1 = 3;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

