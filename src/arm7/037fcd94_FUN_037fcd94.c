/* Decompiled C draft; module arm7; ROM address 037fcd94. No matching claim. */
#include "types.h"
#include "deps/037fcd94_FUN_037fcd94.h"

undefined4 FUN_037fcd94(byte *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (*param_1 < 8) {
    uVar1 = 0;
  }
  else if (*param_1 < 0xe) {
    param_1[1] = 1;
    *(undefined4 *)(param_1 + 0x44) = param_2;
    *(short *)(param_1 + 0x3c) = (short)DAT_037fcde4;
    FUN_037fc5e4((int)(uintptr_t)(param_1),param_3);
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

