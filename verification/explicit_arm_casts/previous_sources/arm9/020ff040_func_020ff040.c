/* Decompiled C draft; module arm9; ROM address 020ff040. No matching claim. */
#include "types.h"
#include "deps/020ff040_func_020ff040.h"

undefined1 * func_020ff040(undefined1 *param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  
  if (param_2 != 0) {
    if (param_3 == 0) {
      func_020f36a0(*param_1,param_2);
    }
    else {
      uVar1 = func_020f36d8(param_2);
      *param_1 = uVar1;
    }
  }
  return param_1 + 1;
}

