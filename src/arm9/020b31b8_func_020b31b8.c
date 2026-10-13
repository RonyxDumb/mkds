/* Decompiled C draft; module arm9; ROM address 020b31b8. No matching claim. */
#include "types.h"
#include "deps/020b31b8_func_020b31b8.h"

void func_020b31b8(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = piRam020b31e0;
  param_1 = param_1 * 0x1c;
  iVar2 = *(int *)(*piRam020b31e0 + 0x50 + param_1);
  *(int *)(*piRam020b31e0 + 0x50 + param_1) = iVar2 + 1;
  *(undefined4 *)(*piVar1 + param_1 + iVar2 * 4 + 0x38) = param_2;
  return;
}

