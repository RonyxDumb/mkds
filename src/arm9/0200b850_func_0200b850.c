/* Decompiled C draft; module arm9; ROM address 0200b850. No matching claim. */
#include "types.h"
#include "deps/0200b850_func_0200b850.h"

void func_0200b850(undefined4 param_1,int param_2,undefined2 param_3)

{
  undefined2 local_18 [2];
  int local_14;
  int local_10;
  
  if (*(int *)(*piRam0200b888 + iRam0200b88c) != 0) {
    if (param_2 == 0) {
      local_14 = 0;
      local_10 = 0;
    }
    else {
      local_10 = param_2 + iRam0200b890;
      local_14 = param_2;
    }
    local_18[0] = param_3;
    (**(code **)(*piRam0200b888 + iRam0200b88c))(param_1,local_18);
  }
  return;
}

