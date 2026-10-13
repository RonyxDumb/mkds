/* Decompiled C draft; module arm7; ROM address 060001b4. No matching claim. */
#include "types.h"
#include "deps/060001b4_FUN_060001b4.h"

undefined4 FUN_060001b4(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 8) {
    return 0;
  }
  if (0xd < param_1) {
    if (param_1 < 0x14) {
      uVar1 = 2;
    }
    else {
      uVar1 = 3;
    }
    return uVar1;
  }
  return 1;
}

