/* Decompiled C draft; module arm7; ROM address 037fb260. No matching claim. */
#include "types.h"
#include "deps/037fb260_FUN_037fb260.h"

void FUN_037fb260(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  
  param_3 = (int)param_2 + param_3;
  for (; (int)param_2 < param_3; param_2 = param_2 + 1) {
    uVar1 = *param_1;
    param_1 = param_1 + 1;
    *param_2 = uVar1;
  }
  return;
}

