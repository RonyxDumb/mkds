/* Decompiled C draft; module arm9; ROM address 0210e4ec. No matching claim. */
#include "types.h"
#include "deps/0210e4ec_func_0210e4ec.h"

void func_0210e4ec(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = puRam0210e508[1];
  uVar2 = puRam0210e508[2];
  *param_1 = *puRam0210e508;
  param_1[1] = uVar1;
  param_1[2] = uVar2;
  param_1[3] = 0xff00;
  return;
}

