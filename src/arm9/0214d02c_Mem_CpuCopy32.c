/* Decompiled C draft; module arm9; ROM address 0214d02c. No matching claim. */
#include "types.h"
#include "deps/0214d02c_Mem_CpuCopy32.h"

void Mem_CpuCopy32(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  
  param_3 = (int)param_2 + param_3;
  for (; (int)param_2 < param_3; param_2 = param_2 + 1) {
    uVar1 = *param_1;
    param_1 = param_1 + 1;
    *param_2 = uVar1;
  }
  return;
}

