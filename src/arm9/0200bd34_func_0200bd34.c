/* Decompiled C draft; module arm9; ROM address 0200bd34. No matching claim. */
#include "types.h"
#include "deps/0200bd34_func_0200bd34.h"

void func_0200bd34(undefined2 *param_1)

{
  undefined2 local_8;
  short local_6;
  
  local_6 = param_1[1];
  if (local_6 == 0) {
    if (*(code **)*puRam0200bd74 != (code *)0x0) {
      (**(code **)*puRam0200bd74)(0xf,0);
    }
  }
  else {
    local_8 = *param_1;
    if (*(int *)*puRam0200bd74 != 0) {
      (**(code **)*puRam0200bd74)(uRam0200bd78,&local_8);
      return;
    }
  }
  return;
}

