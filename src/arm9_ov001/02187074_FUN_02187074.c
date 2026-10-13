/* Decompiled C draft; module arm9_ov001; ROM address 02187074. No matching claim. */
#include "types.h"
#include "deps/02187074_FUN_02187074.h"

int FUN_02187074(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (param_3 < param_1) {
    iVar1 = param_3 + param_2;
    if (param_1 <= param_3 + param_2) {
      iVar1 = param_1;
    }
    return iVar1;
  }
  if (param_1 < param_3) {
    iVar1 = param_3 - param_2;
    if (param_3 - param_2 <= param_1) {
      iVar1 = param_1;
    }
    return iVar1;
  }
  return param_3;
}

