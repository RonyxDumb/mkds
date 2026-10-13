/* Decompiled C draft; module arm7; ROM address 0600b7ac. No matching claim. */
#include "types.h"
#include "deps/0600b7ac_FUN_0600b7ac.h"

undefined4 FUN_0600b7ac(uint param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_1 < 4) {
    if (param_2 < 0x40) {
      FUN_06009e58(0x13,param_1);
      FUN_06009e58(0x35,param_2);
      uVar1 = 0;
    }
    else {
      uVar1 = 5;
    }
  }
  else {
    uVar1 = 5;
  }
  return uVar1;
}

