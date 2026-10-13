/* Decompiled C draft; module arm7; ROM address 06002540. No matching claim. */
#include "types.h"
#include "deps/06002540_FUN_06002540.h"

undefined2 * FUN_06002540(undefined2 *param_1,undefined2 param_2)

{
  ushort uVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = (short)DAT_0600259c;
  param_1[7] = 1;
  param_1[8] = param_2;
  uVar1 = param_1[7];
  param_1[uVar1 + 8] = param_1[6];
  param_1[uVar1 + 9] = 1;
  FUN_060005e8();
  return param_1 + uVar1 + 8;
}

