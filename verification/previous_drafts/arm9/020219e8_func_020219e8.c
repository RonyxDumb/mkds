/* Decompiled C draft; module arm9; ROM address 020219e8. No matching claim. */
#include "types.h"
#include "deps/020219e8_func_020219e8.h"

uint func_020219e8(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x38U & 3;
  uVar2 = *(uint *)(param_1 + 0x38U & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

