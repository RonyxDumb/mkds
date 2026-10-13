/* Decompiled C draft; module arm9; ROM address 020ff0b0. No matching claim. */
#include "types.h"
#include "deps/020ff0b0_func_020ff0b0.h"

char * func_020ff0b0(char *param_1,undefined4 param_2,int param_3,int param_4)

{
  char *pcVar1;
  int iVar2;
  char *pcStack_20;
  int iStack_1c;
  int iStack_18;
  
  if (param_3 != 0) {
    pcVar1 = param_1;
    if (param_4 != 0) {
      pcVar1 = (char *)VecFx32_Subtract(param_3,param_2,&pcStack_20);
    }
    if (param_4 != 0) {
      pcVar1 = pcStack_20;
    }
    if (param_4 != 0) {
      *param_1 = (char)((int)pcVar1 >> 10);
    }
    else {
      pcStack_20 = (char *)((int)*param_1 << 10);
    }
    if (param_4 != 0) {
      iVar2 = iStack_1c >> 9;
      param_1[1] = (char)iVar2;
    }
    else {
      iVar2 = (int)param_1[1];
    }
    if (param_4 != 0) {
      param_1[2] = (char)(iStack_18 >> 10);
    }
    else {
      iStack_1c = iVar2 << 9;
      iStack_18 = (int)param_1[2] << 10;
      VecFx32_Add(&pcStack_20,param_2,param_3);
    }
  }
  return param_1 + 3;
}

