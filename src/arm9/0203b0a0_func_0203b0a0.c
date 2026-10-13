/* Decompiled C draft; module arm9; ROM address 0203b0a0. No matching claim. */
#include "types.h"
#include "deps/0203b0a0_func_0203b0a0.h"

bool func_0203b0a0(byte *param_1,byte *param_2)

{
  if (*param_1 < *param_2) {
    return true;
  }
  if (*param_2 < *param_1) {
    return false;
  }
  if (param_1[1] < param_2[1]) {
    return true;
  }
  if (param_1[1] <= param_2[1]) {
    return param_1[2] < param_2[2];
  }
  return false;
}

