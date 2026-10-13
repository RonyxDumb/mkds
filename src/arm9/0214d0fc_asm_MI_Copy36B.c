/* Decompiled C draft; module arm9; ROM address 0214d0fc. No matching claim. */
#include "types.h"
#include "deps/0214d0fc_asm_MI_Copy36B.h"

undefined8 asm_MI_Copy36B(undefined4 *param_1,undefined4 *param_2)

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
  uVar2 = param_1[8];
  param_2[6] = param_1[6];
  param_2[7] = uVar1;
  param_2[8] = uVar2;
  return CONCAT44(param_2 + 9,param_1 + 9);
}

