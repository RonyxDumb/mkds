/* Decompiled C draft; module arm7; ROM address 06008e2c. No matching claim. */
#include "types.h"
#include "deps/06008e2c_FUN_06008e2c.h"

void FUN_06008e2c(undefined4 *param_1,undefined2 param_2)

{
  *param_1 = 0xffffffff;
  param_1[1] = 0xffffffff;
  *(undefined2 *)(param_1 + 2) = 0;
  *(undefined2 *)((int)param_1 + 10) = param_2;
  return;
}

