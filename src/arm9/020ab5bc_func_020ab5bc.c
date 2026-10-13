/* Decompiled C draft; module arm9; ROM address 020ab5bc. No matching claim. */
#include "types.h"
#include "deps/020ab5bc_func_020ab5bc.h"

void func_020ab5bc(ushort *param_1)

{
  *param_1 = *param_1 + 1;
  if ((*param_1 == param_1[1]) || (*param_1 == param_1[2])) {
    param_1[3] = 1;
  }
  if (param_1[2] < *param_1) {
    *param_1 = param_1[1] + 1;
  }
  return;
}

