/* Decompiled C draft; module arm9; ROM address 021471e4. No matching claim. */
#include "types.h"
#include "deps/021471e4_func_021471e4.h"

undefined8 func_021471e4(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = param_1[1];
  uVar2 = param_1[2];
  *param_2 = *param_1;
  param_2[1] = uVar1;
  param_2[2] = uVar2;
  param_2[3] = 0;
  uVar1 = param_1[4];
  uVar2 = param_1[5];
  param_2[4] = param_1[3];
  param_2[5] = uVar1;
  param_2[6] = uVar2;
  param_2[7] = 0;
  uVar1 = param_1[7];
  uVar2 = param_1[8];
  param_2[8] = param_1[6];
  param_2[9] = uVar1;
  param_2[10] = uVar2;
  param_2[0xb] = 0;
  uVar1 = param_1[10];
  uVar2 = param_1[0xb];
  param_2[0xc] = param_1[9];
  param_2[0xd] = uVar1;
  param_2[0xe] = uVar2;
  param_2[0xf] = 0x1000;
  return CONCAT44(param_2 + 0x10,param_1 + 0xc);
}

