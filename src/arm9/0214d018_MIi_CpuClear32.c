/* Decompiled C draft; module arm9; ROM address 0214d018. No matching claim. */
#include "types.h"
#include "deps/0214d018_MIi_CpuClear32.h"

void MIi_CpuClear32(undefined4 param_1,undefined4 *param_2,int param_3)

{
  param_3 = (int)param_2 + param_3;
  for (; (int)param_2 < param_3; param_2 = param_2 + 1) {
    *param_2 = param_1;
  }
  return;
}

