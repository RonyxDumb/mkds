/* Decompiled C draft; module arm9; ROM address 020ada7c. No matching claim. */
#include "types.h"
#include "deps/020ada7c_StructHU_IncrementSomeCounter.h"

void StructHU_IncrementSomeCounter(int *param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  if ((int)uVar1 < 0x7fffffff) {
    *param_1 = uVar1 + 1;
  }
  return;
}

