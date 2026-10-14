/* Decompiled C draft; module arm7; ROM address 06002a7c. No matching claim. */
#include "types.h"
#include "deps/06002a7c_FUN_06002a7c.h"

undefined2 *
FUN_06002a7c(undefined2 *param_1,undefined4 param_2,undefined2 param_3,undefined2 param_4)

{
  ushort uVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 4;
  param_1[7] = 5;
  thunk_FUN_037fb230(param_2,param_1 + 8,6);
  param_1[0xb] = param_3;
  param_1[0xc] = param_4;
  uVar1 = param_1[7];
  param_1[uVar1 + 8] = param_1[6];
  param_1[uVar1 + 9] = 6;
  FUN_060005e8((undefined4)(uintptr_t)(param_1));
  return param_1 + uVar1 + 8;
}

