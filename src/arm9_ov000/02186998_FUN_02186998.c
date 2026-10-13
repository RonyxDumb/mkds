/* Decompiled C draft; module arm9_ov000; ROM address 02186998. No matching claim. */
#include "types.h"
#include "deps/02186998_FUN_02186998.h"

undefined4 FUN_02186998(int param_1,int *param_2,int param_3)

{
  int iVar1;
  
  if (param_3 < 1) {
    return 0;
  }
  iVar1 = (**(code **)(param_1 + 0x14))(0,param_2[3] + param_3);
  if (iVar1 == 0) {
    return 0;
  }
  func_0x0214d1fc((ushort *)(uintptr_t)(*param_2),(uint *)(uintptr_t)(iVar1),param_2[3]);
  (**(code **)(param_1 + 0x18))(0,*param_2,0);
  if (iVar1 == 0) {
    return 0;
  }
  param_2[1] = param_2[1] + (iVar1 - *param_2);
  param_2[3] = param_2[3] + param_3;
  *param_2 = iVar1;
  param_2[2] = iVar1 + param_2[3];
  return 1;
}

