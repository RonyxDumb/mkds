/* Decompiled C draft; module arm7; ROM address 06002b84. No matching claim. */
#include "types.h"
#include "deps/06002b84_FUN_06002b84.h"

undefined2 *
FUN_06002b84(undefined2 *param_1,uint param_2,undefined4 param_3,undefined2 param_4,
            undefined4 param_5,undefined2 param_6,undefined4 param_7,undefined2 param_8)

{
  ushort uVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 2;
  param_1[7] = 0x1f;
  thunk_FUN_037fb230(param_3,param_1 + 8,6);
  param_1[0xb] = param_4;
  thunk_FUN_037fb230(param_5,param_1 + 0xc,0x20);
  param_1[0x1c] = param_6;
  thunk_FUN_037fb230(param_7,param_1 + 0x1d,0x10);
  param_1[0x25] = param_8;
  param_1[0x26] = 0;
  uVar1 = param_1[7];
  param_1[uVar1 + 8] = param_1[6];
  param_1[uVar1 + 9] = (short)(param_2 >> 1) + -0x2c;
  FUN_060005e8((undefined4)(uintptr_t)(param_1));
  return param_1 + uVar1 + 8;
}

