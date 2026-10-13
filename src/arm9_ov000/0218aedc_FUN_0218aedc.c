/* Decompiled C draft; module arm9_ov000; ROM address 0218aedc. No matching claim. */
#include "types.h"
#include "deps/0218aedc_FUN_0218aedc.h"

void FUN_0218aedc(int *param_1,int param_2)

{
  if (param_1[1] != 0) {
    *(int *)(param_1[1] + 0x20) = param_2;
  }
  param_1[1] = param_2;
  *(undefined4 *)(param_2 + 0x20) = 0;
  if (*param_1 == 0) {
    *param_1 = param_2;
  }
  param_1[2] = param_1[2] + 1;
  return;
}

