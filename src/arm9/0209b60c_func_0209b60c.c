/* Decompiled C draft; module arm9; ROM address 0209b60c. No matching claim. */
#include "types.h"
#include "deps/0209b60c_func_0209b60c.h"

uint func_0209b60c(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 + 0x20U & 3;
  uVar1 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar2 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 0xc;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) << 4) >> 0x10;
}

