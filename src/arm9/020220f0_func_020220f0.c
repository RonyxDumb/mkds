/* Decompiled C draft; module arm9; ROM address 020220f0. No matching claim. */
#include "types.h"
#include "deps/020220f0_func_020220f0.h"

uint func_020220f0(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x18 & 3;
  uVar2 = *(uint *)(param_1 + 0x18 & 0xfffffffc);
  uVar1 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0xc;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  return ((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) -
         (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20)) * 0x2000 >> 0x10;
}

