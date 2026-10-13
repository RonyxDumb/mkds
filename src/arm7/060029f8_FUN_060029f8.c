/* Decompiled C draft; module arm7; ROM address 060029f8. No matching claim. */
#include "types.h"
#include "deps/060029f8_FUN_060029f8.h"

undefined2 * FUN_060029f8(undefined2 *param_1,undefined4 param_2,undefined2 param_3)

{
  ushort uVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 5;
  param_1[7] = 4;
  thunk_FUN_037fb230(param_2,param_1 + 8,6);
  param_1[0xb] = param_3;
  uVar1 = param_1[7];
  param_1[uVar1 + 8] = param_1[6];
  param_1[uVar1 + 9] = 4;
  FUN_060005e8((undefined4)(uintptr_t)(param_1));
  return param_1 + uVar1 + 8;
}

