/* Decompiled C draft; module arm9; ROM address 0200bd7c. No matching claim. */
#include "types.h"
#include "deps/0200bd7c_func_0200bd7c.h"

void func_0200bd7c(void)

{
  int iVar1;
  undefined2 local_8;
  undefined2 local_6;
  
  iVar1 = func_02143dd0(uRam0200bdac);
  if ((iVar1 != 2) && (*(int *)*puRam0200bdb0 != 0)) {
    local_8 = 1;
    local_6 = (undefined2)iVar1;
    (**(code **)*puRam0200bdb0)(0xff,&local_8);
  }
  return;
}

