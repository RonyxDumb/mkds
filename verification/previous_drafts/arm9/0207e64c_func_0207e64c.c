/* Decompiled C draft; module arm9; ROM address 0207e64c. No matching claim. */
#include "types.h"
#include "deps/0207e64c_func_0207e64c.h"

uint func_0207e64c(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0xb4U & 3;
  uVar2 = *(uint *)(param_1 + 0xb4U & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

