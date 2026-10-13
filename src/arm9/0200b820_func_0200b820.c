/* Decompiled C draft; module arm9; ROM address 0200b820. No matching claim. */
#include "types.h"
#include "deps/0200b820_func_0200b820.h"

void func_0200b820(undefined2 param_1,undefined2 param_2)

{
  undefined2 local_8;
  undefined2 local_6;
  
  if (*(int *)(*piRam0200b848 + iRam0200b84c) != 0) {
    local_8 = param_1;
    local_6 = param_2;
    (**(code **)(*piRam0200b848 + iRam0200b84c))(2,&local_8);
  }
  return;
}

