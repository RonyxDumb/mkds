/* Decompiled C draft; module arm9; ROM address 020f82e8. No matching claim. */
#include "types.h"
#include "deps/020f82e8_func_020f82e8.h"

void func_020f82e8(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = piRam020f8308;
  iVar1 = iRam020f8304;
  *piRam020f8308 = iRam020f8304;
  if (param_1 != 0) {
    *piVar2 = iVar1 + 300;
  }
  return;
}

