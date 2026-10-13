/* Decompiled C draft; module arm9; ROM address 02073e4c. No matching claim. */
#include "types.h"
#include "deps/02073e4c_func_02073e4c.h"

void func_02073e4c(undefined4 param_1)

{
  int iVar1;
  undefined1 auStack_18 [12];
  
  iVar1 = GetGlobalHD4();
  VecFx32_Subtract(param_1,iVar1 + 0x24,(int *)(void *)(auStack_18));
  VecFx32_CrossProduct_0(iVar1 + 0x15c,(uint)(uintptr_t)(auStack_18));
  return;
}

