/* Decompiled C draft; module arm9; ROM address 0200b9e0. No matching claim. */
#include "types.h"
#include "deps/0200b9e0_func_0200b9e0.h"

void func_0200b9e0(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = piRam0200ba20;
  *(undefined4 *)(*piRam0200ba20 + iRam0200ba24) = param_1;
  *(undefined4 *)(*piVar1 + iRam0200ba28) = param_2;
  *(undefined2 *)(*piVar1 + iRam0200ba2c) = 0;
  *(int *)(*piVar1 + iRam0200ba34) = *piVar1 + iRam0200ba30;
  *(undefined4 *)(*piVar1 + iRam0200ba38) = 1;
  *(undefined4 *)(*piVar1 + iRam0200ba3c) = 0;
  *(undefined2 *)(*piVar1 + iRam0200ba40) = 0;
  func_0200b934();
  return;
}

