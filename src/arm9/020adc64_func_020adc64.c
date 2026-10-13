/* Decompiled C draft; module arm9; ROM address 020adc64. No matching claim. */
#include "types.h"
#include "deps/020adc64_func_020adc64.h"

int func_020adc64(int param_1)

{
  if (param_1 < 0) {
    param_1 = 0;
  }
  if (5 < param_1) {
    param_1 = 5;
  }
  return (int)*(short *)(iRam020adc78 + param_1 * 2);
}

