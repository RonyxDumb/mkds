/* Decompiled C draft; module arm9; ROM address 020a2e60. No matching claim. */
#include "types.h"
#include "deps/020a2e60_func_020a2e60.h"

uint func_020a2e60(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0xd0U & 3;
  uVar2 = *(uint *)(param_1 + 0xd0U & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

