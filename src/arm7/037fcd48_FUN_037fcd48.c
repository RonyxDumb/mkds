/* Decompiled C draft; module arm7; ROM address 037fcd48. No matching claim. */
#include "types.h"
#include "deps/037fcd48_FUN_037fcd48.h"

undefined4 FUN_037fcd48(byte *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 < 0xe) {
    uVar1 = 0;
  }
  else if (*param_1 < 0x10) {
    param_1[1] = 2;
    *(short *)(param_1 + 0x3c) = (short)DAT_037fcd90;
    FUN_037fc5e4();
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

