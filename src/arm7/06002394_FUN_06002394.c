/* Decompiled C draft; module arm7; ROM address 06002394. No matching claim. */
#include "types.h"
#include "deps/06002394_FUN_06002394.h"

undefined2 *
FUN_06002394(undefined2 *param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  ushort uVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = (short)DAT_060023fc;
  param_1[7] = 3;
  param_1[8] = param_2;
  param_1[9] = param_3;
  param_1[10] = param_4;
  uVar1 = param_1[7];
  param_1[uVar1 + 8] = param_1[6];
  param_1[uVar1 + 9] = 1;
  FUN_060005e8();
  return param_1 + uVar1 + 8;
}

