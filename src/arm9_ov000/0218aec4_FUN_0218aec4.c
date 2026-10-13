/* Decompiled C draft; module arm9_ov000; ROM address 0218aec4. No matching claim. */
#include "types.h"
#include "deps/0218aec4_FUN_0218aec4.h"

void FUN_0218aec4(int *param_1,int param_2)

{
  *(int *)(param_2 + 0x20) = *param_1;
  *param_1 = param_2;
  if (param_1[1] == 0) {
    param_1[1] = param_2;
  }
  param_1[2] = param_1[2] + 1;
  return;
}

