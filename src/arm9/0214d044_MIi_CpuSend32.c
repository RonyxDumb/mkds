/* Decompiled C draft; module arm9; ROM address 0214d044. No matching claim. */
#include "types.h"
#include "deps/0214d044_MIi_CpuSend32.h"

void MIi_CpuSend32(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  param_3 = (int)param_1 + param_3;
  for (; (int)param_1 < param_3; param_1 = param_1 + 1) {
    *param_2 = *param_1;
  }
  return;
}

