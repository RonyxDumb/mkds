/* Decompiled C draft; module arm9; ROM address 020b19a0. No matching claim. */
#include "types.h"
#include "deps/020b19a0_func_020b19a0.h"

uint func_020b19a0(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020b19b0 & 0xfffffffc) >> (uRam020b19b0 & 3) * 8 |
          *(uint *)(uRam020b19b0 & 0xfffffffc) << (uRam020b19b0 & 3) * -8 + 0x20) + 0x908;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

