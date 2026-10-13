/* Decompiled C draft; module arm9; ROM address 020222e0. No matching claim. */
#include "types.h"
#include "deps/020222e0_func_020222e0.h"

uint func_020222e0(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

