/* Decompiled C draft; module arm9; ROM address 0210f75c. No matching claim. */
#include "types.h"
#include "deps/0210f75c_func_0210f75c.h"

bool func_0210f75c(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = iRam0210f77c + param_1 * 0xc;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0;
}

