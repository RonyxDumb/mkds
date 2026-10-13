/* Decompiled C draft; module arm9; ROM address 02006380. No matching claim. */
#include "types.h"
#include "deps/02006380_func_02006380.h"

bool func_02006380(int param_1,uint param_2)

{
  return (*(uint *)(*(int *)(param_1 + 0x14) + ((int)param_2 >> 5) * 4) & 1 << (param_2 & 0x1f)) !=
         0;
}

