/* Decompiled C draft; module arm9; ROM address 020f82c4. No matching claim. */
#include "types.h"
#include "deps/020f82c4_func_020f82c4.h"

void func_020f82c4(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = piRam020f82e4;
  iVar1 = iRam020f82e0;
  *piRam020f82e4 = iRam020f82e0;
  if (param_1 != 0) {
    *piVar2 = iVar1 + 300;
  }
  return;
}

