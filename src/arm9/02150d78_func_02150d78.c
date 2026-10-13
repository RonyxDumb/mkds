/* Decompiled C draft; module arm9; ROM address 02150d78. No matching claim. */
#include "types.h"
#include "deps/02150d78_func_02150d78.h"

void func_02150d78(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = uRam02150db8;
  *param_1 = uRam02150db4;
  uVar2 = uRam02150dbc;
  param_1[1] = uVar1;
  uVar1 = uRam02150dc0;
  param_1[2] = uVar2;
  uVar2 = uRam02150dc4;
  param_1[3] = uVar1;
  param_1[4] = uVar2;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  return;
}

