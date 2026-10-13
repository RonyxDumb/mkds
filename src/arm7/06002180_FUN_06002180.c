/* Decompiled C draft; module arm7; ROM address 06002180. No matching claim. */
#include "types.h"
#include "deps/06002180_FUN_06002180.h"

undefined2 * FUN_06002180(undefined2 *param_1,int param_2,undefined4 param_3)

{
  ushort uVar1;
  short sVar2;
  
  FUN_06000680();
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = (short)DAT_06002210;
  sVar2 = thunk_FUN_03806b2c(param_2 + 1,2);
  param_1[7] = sVar2 + 1;
  param_1[8] = (short)param_2;
  thunk_FUN_037fb230(param_3,param_1 + 9,param_2);
  uVar1 = param_1[7];
  param_1[uVar1 + 8] = param_1[6];
  param_1[uVar1 + 9] = 1;
  FUN_060005e8((undefined4)(uintptr_t)(param_1));
  return param_1 + uVar1 + 8;
}

