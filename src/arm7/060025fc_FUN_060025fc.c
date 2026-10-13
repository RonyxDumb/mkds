/* Decompiled C draft; module arm7; ROM address 060025fc. No matching claim. */
#include "types.h"
#include "deps/060025fc_FUN_060025fc.h"

undefined2 * FUN_060025fc(undefined2 *param_1,undefined2 param_2)

{
  ushort uVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0x104;
  param_1[7] = 1;
  param_1[8] = param_2;
  uVar1 = param_1[7];
  param_1[uVar1 + 8] = param_1[6];
  param_1[uVar1 + 9] = 1;
  FUN_060005e8();
  return param_1 + uVar1 + 8;
}

