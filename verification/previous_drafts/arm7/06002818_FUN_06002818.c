/* Decompiled C draft; module arm7; ROM address 06002818. No matching claim. */
#include "types.h"
#include "deps/06002818_FUN_06002818.h"

undefined2 *
FUN_06002818(undefined2 *param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
            undefined4 param_5)

{
  ushort uVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 10;
  param_1[7] = 0xc;
  param_1[8] = 0;
  param_1[9] = param_2;
  param_1[10] = param_3;
  param_1[0xb] = param_4;
  thunk_FUN_037fb230(param_5,param_1 + 0xc,0x10);
  uVar1 = param_1[7];
  param_1[uVar1 + 8] = param_1[6];
  param_1[uVar1 + 9] = 0x12;
  FUN_060005e8((undefined4)(uintptr_t)(param_1));
  return param_1 + uVar1 + 8;
}

