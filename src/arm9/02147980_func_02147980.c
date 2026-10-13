/* Decompiled C draft; module arm9; ROM address 02147980. No matching claim. */
#include "types.h"
#include "deps/02147980_func_02147980.h"

undefined8 func_02147980(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = param_1[1];
  uVar2 = param_1[2];
  *param_2 = *param_1;
  param_2[1] = uVar1;
  param_2[2] = uVar2;
  uVar1 = param_1[5];
  uVar2 = param_1[6];
  param_2[3] = param_1[4];
  param_2[4] = uVar1;
  param_2[5] = uVar2;
  uVar1 = param_1[9];
  uVar2 = param_1[10];
  param_2[6] = param_1[8];
  param_2[7] = uVar1;
  param_2[8] = uVar2;
  uVar1 = param_1[0xd];
  uVar2 = param_1[0xe];
  param_2[9] = param_1[0xc];
  param_2[10] = uVar1;
  param_2[0xb] = uVar2;
  return CONCAT44(param_2 + 0xc,param_1 + 0x10);
}

