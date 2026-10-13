/* Decompiled C draft; module arm9; ROM address 0213c9f8. No matching claim. */
#include "types.h"
#include "deps/0213c9f8_func_0213c9f8.h"

uint func_0213c9f8(int param_1,uint param_2)

{
  uint uVar1;
  int local_18;
  uint local_14;
  undefined4 local_10;
  
  local_10 = 0;
  local_18 = param_1;
  local_14 = param_2;
  uVar1 = func_0213cae0(uRam0213ca60,&local_18);
  if (-1 < (int)uVar1) {
    if (uVar1 < param_2) {
      *(undefined2 *)(param_1 + uVar1 * 2) = 0;
    }
    else {
      *(undefined2 *)(param_1 + param_2 * 2 + -2) = 0;
      uVar1 = 0xffffffff;
    }
    return uVar1;
  }
  return uVar1;
}

