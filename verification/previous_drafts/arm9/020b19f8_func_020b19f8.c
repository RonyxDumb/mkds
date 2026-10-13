/* Decompiled C draft; module arm9; ROM address 020b19f8. No matching claim. */
#include "types.h"
#include "deps/020b19f8_func_020b19f8.h"

uint func_020b19f8(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020b1a08 & 0xfffffffc) >> (uRam020b1a08 & 3) * 8 |
          *(uint *)(uRam020b1a08 & 0xfffffffc) << (uRam020b1a08 & 3) * -8 + 0x20) + 0x8e4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

