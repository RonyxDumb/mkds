/* Decompiled C draft; module arm9; ROM address 0200b7e0. No matching claim. */
#include "types.h"
#include "deps/0200b7e0_func_0200b7e0.h"

void func_0200b7e0(undefined1 *param_1)

{
  int *piVar1;
  undefined1 *puVar2;
  
  piVar1 = piRam0200b814;
  *(undefined4 *)(*piRam0200b814 + iRam0200b818) = 1;
  puVar2 = (undefined1 *)(*piVar1 + iRam0200b81c);
  *puVar2 = *param_1;
  puVar2[1] = param_1[1];
  puVar2[2] = param_1[2];
  puVar2[3] = param_1[3];
  puVar2[4] = param_1[4];
  puVar2[5] = param_1[5];
  return;
}

