/* Decompiled C draft; module arm9; ROM address 0214d0e0. No matching claim. */
#include "types.h"
#include "deps/0214d0e0_asm_MI_Copy32B.h"

undefined8 asm_MI_Copy32B(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = param_1[1];
  uVar2 = param_1[2];
  *param_2 = *param_1;
  param_2[1] = uVar1;
  param_2[2] = uVar2;
  uVar1 = param_1[4];
  uVar2 = param_1[5];
  param_2[3] = param_1[3];
  param_2[4] = uVar1;
  param_2[5] = uVar2;
  uVar1 = param_1[7];
  param_2[6] = param_1[6];
  param_2[7] = uVar1;
  return CONCAT44(param_2 + 8,param_1 + 8);
}

