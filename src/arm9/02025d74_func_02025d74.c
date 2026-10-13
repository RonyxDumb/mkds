/* Decompiled C draft; module arm9; ROM address 02025d74. No matching claim. */
#include "types.h"
#include "deps/02025d74_func_02025d74.h"

int func_02025d74(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(iRam02025d88 + param_1 * 4);
  if (iVar1 != -1) {
    iVar1 = iVar1 + -0x1a;
  }
  return iVar1;
}

