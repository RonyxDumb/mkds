/* Decompiled C draft; module arm9; ROM address 02000920. No matching claim. */
#include "types.h"
#include "deps/02000920_Crt0_MemorySet32.h"

void Crt0_MemorySet32(undefined4 param_1,undefined4 *param_2,int param_3)

{
  param_3 = (int)param_2 + param_3;
  for (; (int)param_2 < param_3; param_2 = param_2 + 1) {
    *param_2 = param_1;
  }
  return;
}

