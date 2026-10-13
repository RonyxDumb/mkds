/* Decompiled C draft; module arm9; ROM address 020e0584. No matching claim. */
#include "types.h"
#include "deps/020e0584_func_020e0584.h"

void func_020e0584(int param_1,undefined4 param_2,int param_3,int *param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined1 auStack_28 [16];
  
  VecFx32_Subtract(param_2,param_1 + 4,auStack_28);
  iVar2 = VecFx32_CrossProduct_0(auStack_28,param_1 + 0x40);
  iVar3 = VecFx32_CrossProduct_0(auStack_28,param_1 + 0x34);
  iVar4 = VecFx32_CrossProduct_0(auStack_28,param_1 + 0x28);
  param_4[1] = iVar4;
  param_4[2] = iVar3;
  param_4[3] = iVar2;
  if ((param_3 == 0) ||
     (uVar1 = param_1 + 0x130U & 3, uVar5 = *(uint *)(param_1 + 0x130U & 0xfffffffc),
     uVar5 >> uVar1 * 8 == 0 && uVar5 << uVar1 * -8 + 0x20 == 0)) {
    param_4[4] = 0;
    param_4[5] = 0;
    param_4[6] = 0;
  }
  else {
    iVar2 = VecFx32_CrossProduct_0(param_3,param_1 + 0x40);
    iVar3 = VecFx32_CrossProduct_0(param_3,param_1 + 0x34);
    iVar4 = VecFx32_CrossProduct_0(param_3,param_1 + 0x28);
    param_4[4] = iVar4;
    param_4[5] = iVar3;
    param_4[6] = iVar2;
  }
  *param_4 = param_1;
  return;
}

