/* Decompiled C draft; module arm9_ov000; ROM address 02197ddc. No matching claim. */
#include "types.h"
#include "deps/02197ddc_FUN_02197ddc.h"

void FUN_02197ddc(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  if (param_1[1] < param_1[2] + 2) {
    func_0x0213442c(DAT_02197e18,DAT_02197e1c,0,0x2e);
  }
  iVar1 = param_1[2];
  param_1[2] = iVar1 + 1;
  *(char *)(*param_1 + iVar1) = (char)((uint)param_2 >> 8);
  iVar1 = param_1[2];
  param_1[2] = iVar1 + 1;
  *(char *)(*param_1 + iVar1) = (char)param_2;
  return;
}

