/* Decompiled C draft; module arm9; ROM address 020b57b4. No matching claim. */
#include "types.h"
#include "deps/020b57b4_func_020b57b4.h"

int func_020b57b4(uint param_1,uint param_2,int param_3)

{
  return param_3 * param_1 +
         param_2 * ((int)param_1 >> 0x1f) + (int)((ulonglong)param_1 * (ulonglong)param_2 >> 0x20) +
         (uint)(0x7fffffff < (uint)((ulonglong)param_1 * (ulonglong)param_2));
}

