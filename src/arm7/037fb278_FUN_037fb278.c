/* Decompiled C draft; module arm7; ROM address 037fb278. No matching claim. */
#include "types.h"
#include "deps/037fb278_FUN_037fb278.h"

void FUN_037fb278(undefined4 param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (int)param_2 + param_3;
  iVar2 = (int)param_2 + (param_3 & 0xffffffe0);
  for (; (int)param_2 < iVar2; param_2 = param_2 + 8) {
    *param_2 = param_1;
    param_2[1] = param_1;
    param_2[2] = param_1;
    param_2[3] = param_1;
    param_2[4] = param_1;
    param_2[5] = param_1;
    param_2[6] = param_1;
    param_2[7] = param_1;
  }
  for (; (int)param_2 < iVar1; param_2 = param_2 + 1) {
    *param_2 = param_1;
  }
  return;
}

