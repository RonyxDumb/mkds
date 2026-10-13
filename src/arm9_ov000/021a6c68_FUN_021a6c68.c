/* Decompiled C draft; module arm9_ov000; ROM address 021a6c68. No matching claim. */
#include "types.h"
#include "deps/021a6c68_FUN_021a6c68.h"

undefined4 FUN_021a6c68(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_021a6c90();
  uVar2 = 0;
  if (uVar1 < 0x1c) {
    if (uVar1 < 0x16) {
      if (0xf < uVar1) {
        uVar2 = 1;
      }
    }
    else {
      uVar2 = 2;
    }
  }
  else {
    uVar2 = 3;
  }
  return uVar2;
}

