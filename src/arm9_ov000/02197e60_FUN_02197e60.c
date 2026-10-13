/* Decompiled C draft; module arm9_ov000; ROM address 02197e60. No matching claim. */
#include "types.h"
#include "deps/02197e60_FUN_02197e60.h"

undefined4 FUN_02197e60(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_021a3690(param_2);
  *param_1 = iVar1;
  if (*param_1 == 0) {
    return 0;
  }
  param_1[1] = param_2;
  return 1;
}

