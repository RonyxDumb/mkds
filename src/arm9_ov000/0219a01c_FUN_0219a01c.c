/* Decompiled C draft; module arm9_ov000; ROM address 0219a01c. No matching claim. */
#include "types.h"
#include "deps/0219a01c_FUN_0219a01c.h"

void FUN_0219a01c(int param_1,int param_2,undefined4 param_3)

{
  *(char *)(param_1 + param_2) = (char)((uint)param_3 >> 8);
  *(char *)(param_1 + param_2 + 1) = (char)param_3;
  return;
}

