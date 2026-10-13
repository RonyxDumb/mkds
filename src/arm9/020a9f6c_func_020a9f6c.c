/* Decompiled C draft; module arm9; ROM address 020a9f6c. No matching claim. */
#include "types.h"
#include "deps/020a9f6c_func_020a9f6c.h"

void func_020a9f6c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 *puVar1;
  
  puVar1 = puRam020a9f90;
  *puRam020a9f90 = 0;
  puVar1[1] = 0;
  func_020aa028(param_1,param_2,0,4,param_3,*puRam020a9f94);
  return;
}

