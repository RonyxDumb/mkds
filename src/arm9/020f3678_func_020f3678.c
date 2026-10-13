/* Decompiled C draft; module arm9; ROM address 020f3678. No matching claim. */
#include "types.h"
#include "deps/020f3678_func_020f3678.h"

void func_020f3678(int param_1,int *param_2)

{
  *param_2 = (int)*(char *)(param_1 + 0x21) << 6;
  param_2[1] = (int)*(char *)(param_1 + 0x22) << 6;
  param_2[2] = (int)*(char *)(param_1 + 0x23) << 6;
  return;
}

