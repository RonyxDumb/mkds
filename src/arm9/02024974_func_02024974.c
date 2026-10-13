/* Decompiled C draft; module arm9; ROM address 02024974. No matching claim. */
#include "types.h"
#include "deps/02024974_func_02024974.h"

int func_02024974(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  if (param_2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = 4;
  }
  if (param_1 == 0) {
    if (param_3 == param_4) {
      iVar1 = 0;
    }
    else if (param_3 == param_4 + 1) {
      iVar1 = 1;
    }
    else {
      iVar1 = 2;
    }
    iVar2 = iVar2 + iVar1;
  }
  else {
    iVar2 = iVar2 + 3;
  }
  return iVar2 + 0x130;
}

