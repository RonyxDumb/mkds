/* Decompiled C draft; module arm7; ROM address 060028a4. No matching claim. */
#include "types.h"
#include "deps/060028a4_FUN_060028a4.h"

undefined2 *
FUN_060028a4(undefined2 *param_1,undefined2 param_2,undefined4 param_3,undefined2 param_4,
            undefined2 param_5,undefined2 param_6,undefined2 param_7,undefined2 param_8,
            ushort param_9,undefined4 param_10)

{
  ushort uVar1;
  short sVar2;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 9;
  sVar2 = thunk_FUN_03806b2c(param_9 + 1,2);
  param_1[7] = sVar2 + 0x17;
  param_1[8] = param_2;
  thunk_FUN_037fb230(param_3,param_1 + 9,0x20);
  param_1[0x19] = param_4;
  param_1[0x1a] = param_5;
  param_1[0x1b] = param_6;
  param_1[0x1c] = param_7;
  param_1[0x1d] = param_8;
  param_1[0x1e] = param_9;
  thunk_FUN_037fb230(param_10,param_1 + 0x1f);
  uVar1 = param_1[7];
  param_1[uVar1 + 8] = param_1[6];
  param_1[uVar1 + 9] = 1;
  FUN_060005e8((undefined4)(uintptr_t)(param_1));
  return param_1 + uVar1 + 8;
}

