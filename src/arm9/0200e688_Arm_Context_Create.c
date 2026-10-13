/* Decompiled C draft; module arm9; ROM address 0200e688. No matching claim. */
#include "types.h"
#include "deps/0200e688_Arm_Context_Create.h"

void Arm_Context_Create(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  param_1[0x10] = param_2 + 4U;
  param_1[0x11] = param_3;
  param_1[0xe] = param_3 + -0x40;
  if ((param_2 + 4U & 1) == 0) {
    uVar1 = 0x1f;
  }
  else {
    uVar1 = 0x3f;
  }
  *param_1 = uVar1;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xf] = 0;
  return;
}

