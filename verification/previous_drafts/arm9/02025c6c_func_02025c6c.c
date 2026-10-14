/* Decompiled C draft; module arm9; ROM address 02025c6c. No matching claim. */
#include "types.h"
#include "deps/02025c6c_func_02025c6c.h"

void func_02025c6c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  
  puVar1 = (undefined2 *)func_0201ea30(param_3,param_1);
  puVar2 = (undefined2 *)func_0201ea30(param_3,param_2);
  *puVar1 = *puVar2;
  puVar1[1] = puVar2[1];
  return;
}

