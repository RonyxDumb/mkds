/* Decompiled C draft; module arm9; ROM address 0214c728. No matching claim. */
#include "types.h"
#include "deps/0214c728_CopySingle384.h"

undefined4 * CopySingle384(undefined4 *param_1,undefined4 *param_2)

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
  *param_2 = param_1[3];
  param_2[1] = uVar1;
  param_2[2] = uVar2;
  uVar1 = param_1[7];
  uVar2 = param_1[8];
  *param_2 = param_1[6];
  param_2[1] = uVar1;
  param_2[2] = uVar2;
  uVar1 = param_1[10];
  uVar2 = param_1[0xb];
  *param_2 = param_1[9];
  param_2[1] = uVar1;
  param_2[2] = uVar2;
  return param_1 + 0xc;
}

