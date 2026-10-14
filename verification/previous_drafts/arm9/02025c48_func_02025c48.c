/* Decompiled C draft; module arm9; ROM address 02025c48. No matching claim. */
#include "types.h"
#include "deps/02025c48_func_02025c48.h"

void func_02025c48(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = func_0201ea30(param_3,param_1);
  iVar2 = func_0201ea30(param_3,param_2);
  *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(iVar2 + 4);
  return;
}

