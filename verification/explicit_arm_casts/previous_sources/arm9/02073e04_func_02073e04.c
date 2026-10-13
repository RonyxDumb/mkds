/* Decompiled C draft; module arm9; ROM address 02073e04. No matching claim. */
#include "types.h"
#include "deps/02073e04_func_02073e04.h"

int func_02073e04(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_18 [12];
  
  iVar1 = GetGlobalHD4();
  VecFx32_Subtract(param_1,iVar1 + 0x24,auStack_18);
  iVar2 = VecFx32_CrossProduct_0(iVar1 + 0xc,auStack_18);
  return *(short *)(iVar1 + 0x26c) * iVar2;
}

