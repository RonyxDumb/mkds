/* Decompiled C draft; module arm9; ROM address 020b6b18. No matching claim. */
#include "types.h"
#include "deps/020b6b18_func_020b6b18.h"

void func_020b6b18(int *param_1,int *param_2,int param_3,int param_4,short param_5,short param_6)

{
  *param_1 = param_3 << 0xc;
  param_1[1] = param_4 << 0xc;
  *param_2 = (int)param_5 << 0xc;
  param_2[1] = (int)param_6 << 0xc;
  return;
}

