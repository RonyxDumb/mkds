/* Decompiled C draft; module arm9; ROM address 02024a28. No matching claim. */
#include "types.h"
#include "deps/02024a28_func_02024a28.h"

void func_02024a28(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  uint uVar1;
  
  if (param_4 == 2) {
    uVar1 = ((param_3 << 7) >> 0xc & 0xffU) + 0x14 & 0xff;
    if (uVar1 < 0x80) {
      if (uVar1 < 0x32) {
        uVar1 = 0x32;
      }
    }
    else {
      uVar1 = 0x7f;
    }
  }
  else {
    uVar1 = 0x7f;
  }
  StructMQRacerEntry_SomeFn_6(param_1,0,param_2,uVar1,0);
  return;
}

