/* Decompiled C draft; module arm9; ROM address 02025f54. No matching claim. */
#include "types.h"
#include "deps/02025f54_func_02025f54.h"

void func_02025f54(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  switch(*param_1) {
  case 0:
  case 3:
    param_1[1] = 0;
    return;
  case 1:
  case 2:
    param_1[1] = param_1[2];
  }
  return;
}

