/* Decompiled C draft; module arm9_ov000; ROM address 02186a38. No matching claim. */
#include "types.h"
#include "deps/02186a38_FUN_02186a38.h"

undefined4 FUN_02186a38(int param_1,int *param_2,int param_3)

{
  int iVar1;
  
  if (param_3 == 0) {
    return 0;
  }
  iVar1 = (**(code **)(param_1 + 0x14))(DAT_02186a80,param_3);
  *param_2 = iVar1;
  if (*param_2 == 0) {
    return 0;
  }
  param_2[1] = *param_2;
  param_2[3] = param_3;
  param_2[2] = *param_2 + param_2[3];
  return 1;
}

