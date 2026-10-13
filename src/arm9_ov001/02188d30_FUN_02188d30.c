/* Decompiled C draft; module arm9_ov001; ROM address 02188d30. No matching claim. */
#include "types.h"
#include "deps/02188d30_FUN_02188d30.h"

void FUN_02188d30(int param_1,undefined2 param_2,undefined4 param_3,int param_4)

{
  FUN_0219b208(*(undefined4 *)(param_1 + DAT_02188d58),param_2,param_3,1);
  if (param_4 == 0) {
    param_4 = DAT_02188d5c;
  }
  *(int *)(param_1 + DAT_02188d60) = param_4;
  return;
}

