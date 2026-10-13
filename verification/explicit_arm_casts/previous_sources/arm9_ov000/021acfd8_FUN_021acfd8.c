/* Decompiled C draft; module arm9_ov000; ROM address 021acfd8. No matching claim. */
#include "types.h"
#include "deps/021acfd8_FUN_021acfd8.h"

undefined4 FUN_021acfd8(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    return 0xffffffff;
  }
  FUN_021ae270();
  FUN_021ae2d8();
  FUN_021ae290(0,0x35,param_2);
  uVar1 = FUN_021ad0a4(param_1,1,param_3);
  FUN_021ae258();
  return uVar1;
}

