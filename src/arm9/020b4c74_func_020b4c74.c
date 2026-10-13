/* Decompiled C draft; module arm9; ROM address 020b4c74. No matching claim. */
#include "types.h"
#include "deps/020b4c74_func_020b4c74.h"

void func_020b4c74(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = iRam020b4cac;
  iVar2 = (int)*(short *)(iRam020b4cac + ((param_2 >> 4) * 2 + 1) * 2);
  *param_1 = -iVar2;
  iVar1 = (int)*(short *)(iVar1 + (param_2 >> 4) * 4);
  param_1[1] = iVar1;
  param_1[2] = iVar1;
  param_1[3] = iVar2;
  return;
}

