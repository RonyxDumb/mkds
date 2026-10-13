/* Decompiled C draft; module arm9; ROM address 020930a0. No matching claim. */
#include "types.h"
#include "deps/020930a0_func_020930a0.h"

uint func_020930a0(int param_1,int param_2)

{
  return (uint)((longlong)param_1 * (longlong)param_2) >> 0xc |
         (int)((ulonglong)((longlong)param_1 * (longlong)param_2) >> 0x20) << 0x14;
}

