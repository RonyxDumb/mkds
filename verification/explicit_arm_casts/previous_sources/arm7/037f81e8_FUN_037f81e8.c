/* Decompiled C draft; module arm7; ROM address 037f81e8. No matching claim. */
#include "types.h"
#include "deps/037f81e8_FUN_037f81e8.h"

undefined4 FUN_037f81e8(void)

{
  undefined4 uVar1;
  byte local_8 [8];
  
  FUN_03804bbc(0x1d,1,local_8);
  if (local_8[0] == 0xff) {
    uVar1 = 0;
  }
  else if ((local_8[0] & 0x40) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

