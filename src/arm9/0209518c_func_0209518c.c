/* Decompiled C draft; module arm9; ROM address 0209518c. No matching claim. */
#include "types.h"
#include "deps/0209518c_func_0209518c.h"

uint func_0209518c(int param_1,int param_2)

{
  return (uint)((longlong)param_1 * (longlong)param_2) >> 0xc |
         (int)((ulonglong)((longlong)param_1 * (longlong)param_2) >> 0x20) << 0x14;
}

