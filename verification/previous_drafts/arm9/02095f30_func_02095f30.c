/* Decompiled C draft; module arm9; ROM address 02095f30. No matching claim. */
#include "types.h"
#include "deps/02095f30_func_02095f30.h"

uint func_02095f30(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0xb4U & 3;
  uVar2 = *(uint *)(param_1 + 0xb4U & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

