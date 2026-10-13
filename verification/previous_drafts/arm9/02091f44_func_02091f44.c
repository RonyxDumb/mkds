/* Decompiled C draft; module arm9; ROM address 02091f44. No matching claim. */
#include "types.h"
#include "deps/02091f44_func_02091f44.h"

uint func_02091f44(int param_1,int param_2)

{
  return (uint)((longlong)param_1 * (longlong)param_2) >> 0xc |
         (int)((ulonglong)((longlong)param_1 * (longlong)param_2) >> 0x20) << 0x14;
}

