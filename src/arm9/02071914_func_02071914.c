/* Decompiled C draft; module arm9; ROM address 02071914. No matching claim. */
#include "types.h"
#include "deps/02071914_func_02071914.h"

void func_02071914(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = func_02109078(param_1,param_2,0x7f,0);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x488) = param_2;
  }
  return;
}

