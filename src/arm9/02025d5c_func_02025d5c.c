/* Decompiled C draft; module arm9; ROM address 02025d5c. No matching claim. */
#include "types.h"
#include "deps/02025d5c_func_02025d5c.h"

int func_02025d5c(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(iRam02025d70 + param_1 * 4);
  if (iVar1 != -1) {
    iVar1 = iVar1 + 4;
  }
  return iVar1;
}

