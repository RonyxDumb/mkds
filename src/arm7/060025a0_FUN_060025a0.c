/* Decompiled C draft; module arm7; ROM address 060025a0. No matching claim. */
#include "types.h"
#include "deps/060025a0_FUN_060025a0.h"

undefined2 * FUN_060025a0(undefined2 *param_1)

{
  ushort uVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0x200;
  param_1[7] = 0x48;
  uVar1 = param_1[7];
  param_1[uVar1 + 8] = param_1[6];
  param_1[uVar1 + 9] = 1;
  FUN_060005e8();
  return param_1 + uVar1 + 8;
}

