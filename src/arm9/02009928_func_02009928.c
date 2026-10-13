/* Decompiled C draft; module arm9; ROM address 02009928. No matching claim. */
#include "types.h"
#include "deps/02009928_func_02009928.h"

void func_02009928(undefined2 param_1,int param_2)

{
  undefined2 local_8;
  undefined2 local_6;
  
  if ((param_2 != 2) && (param_2 != 0)) {
    local_6 = (undefined2)param_2;
    local_8 = param_1;
    (**(code **)(*piRam02009950 + iRam02009954))(0xff,&local_8);
  }
  return;
}

