/* Decompiled C draft; module arm9; ROM address 02025edc. No matching claim. */
#include "types.h"
#include "deps/02025edc_func_02025edc.h"

void func_02025edc(int *param_1)

{
  if (*param_1 == 0) {
    param_1[1] = param_1[1] + 1;
    if (param_1[2] < param_1[1]) {
      param_1[1] = param_1[2];
      *param_1 = 1;
      return;
    }
  }
  else {
    if (*param_1 != 2) {
      return;
    }
    param_1[1] = param_1[1] + -1;
    if (param_1[1] < 0) {
      param_1[1] = 0;
      *param_1 = 3;
    }
  }
  return;
}

