/* Decompiled C draft; module arm7; ROM address 037fb24c. No matching claim. */
#include "types.h"
#include "deps/037fb24c_FUN_037fb24c.h"

void FUN_037fb24c(undefined4 param_1,undefined4 *param_2,int param_3)

{
  param_3 = (int)param_2 + param_3;
  for (; (int)param_2 < param_3; param_2 = param_2 + 1) {
    *param_2 = param_1;
  }
  return;
}

