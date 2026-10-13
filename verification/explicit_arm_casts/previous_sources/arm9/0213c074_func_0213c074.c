/* Decompiled C draft; module arm9; ROM address 0213c074. No matching claim. */
#include "types.h"
#include "deps/0213c074_func_0213c074.h"

int func_0213c074(int param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  int iStack_24;
  int iStack_20;
  int local_1c;
  int local_18 [3];
  
  local_18[1] = 0;
  local_18[0] = param_1;
  iVar1 = func_0213c560(param_3,0x7fffffff,uRam0213c108,local_18,&iStack_24,&iStack_20,&local_1c);
  if (param_2 != (int *)0x0) {
    *param_2 = param_1 + iStack_24;
  }
  if (local_1c == 0) {
    if (iStack_20 != 0) {
      iVar1 = -iVar1;
    }
    return iVar1;
  }
  *puRam0213c10c = 0x22;
  return -1;
}

