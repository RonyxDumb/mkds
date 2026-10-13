/* Decompiled C draft; module arm9_ov000; ROM address 021a71a4. No matching claim. */
#include "types.h"
#include "deps/021a71a4_FUN_021a71a4.h"

int FUN_021a71a4(int param_1,int *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = param_1;
  if (param_3 == 0) {
    iVar1 = 0;
  }
  param_2[1] = iVar1;
  *param_2 = param_3;
  iVar1 = FUN_021a8a54(param_3);
  return param_1 + iVar1;
}

