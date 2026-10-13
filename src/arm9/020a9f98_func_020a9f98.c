/* Decompiled C draft; module arm9; ROM address 020a9f98. No matching claim. */
#include "types.h"
#include "deps/020a9f98_func_020a9f98.h"

void func_020a9f98(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 *puVar1;
  
  puVar1 = puRam020a9fbc;
  *puRam020a9fbc = 0;
  puVar1[1] = 0;
  func_020aa028(param_1,param_2,0,4,param_3,*puRam020a9fc0);
  return;
}

