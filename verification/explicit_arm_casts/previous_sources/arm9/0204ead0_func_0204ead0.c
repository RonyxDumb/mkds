/* Decompiled C draft; module arm9; ROM address 0204ead0. No matching claim. */
#include "types.h"
#include "deps/0204ead0_func_0204ead0.h"

void func_0204ead0(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 local_8 [2];
  
  piVar1 = piRam0204eb00;
  *(undefined4 *)(*piRam0204eb00 + 0xc) = 0x2e;
  *(undefined4 *)(*piVar1 + 0x10) = 1;
  local_8[0] = param_2;
  iVar2 = func_02006d3c(param_1,local_8,4,uRam0204eb04);
  if (iVar2 == 0) {
    *(undefined4 *)(*piRam0204eb00 + 0x10) = 0;
  }
  return;
}

