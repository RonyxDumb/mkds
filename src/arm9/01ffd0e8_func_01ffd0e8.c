/* Decompiled C draft; module arm9; ROM address 01ffd0e8. No matching claim. */
#include "types.h"
#include "deps/01ffd0e8_func_01ffd0e8.h"

bool func_01ffd0e8(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  VecFx32_CrossProduct(param_2,param_3,&local_20);
  iVar1 = Vector3_DotProduct(param_2,param_3);
  iVar1 = FX_Sqrt((iVar1 + 0x1000) * 2);
  uVar2 = puRam01ffd18c[1];
  uVar3 = puRam01ffd18c[2];
  uVar4 = puRam01ffd18c[3];
  *param_1 = *puRam01ffd18c;
  param_1[1] = uVar2;
  param_1[2] = uVar3;
  param_1[3] = uVar4;
  if (0 < iVar1) {
    uVar2 = FX_Div(local_20,iVar1);
    *param_1 = uVar2;
    uVar2 = FX_Div(local_1c,iVar1);
    param_1[1] = uVar2;
    uVar2 = FX_Div(local_18,iVar1);
    param_1[2] = uVar2;
    param_1[3] = iVar1 >> 1;
  }
  return 0 < iVar1;
}

