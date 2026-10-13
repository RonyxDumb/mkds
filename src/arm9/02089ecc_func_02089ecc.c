/* Decompiled C draft; module arm9; ROM address 02089ecc. No matching claim. */
#include "types.h"
#include "deps/02089ecc_func_02089ecc.h"

void func_02089ecc(undefined2 *param_1)

{
  undefined2 uVar1;
  
  *param_1 = 10;
  uVar1 = (undefined2)uRam02089ef0;
  param_1[1] = 0xc;
  param_1[2] = uVar1;
  *(undefined4 *)(param_1 + 4) = 1;
  return;
}

