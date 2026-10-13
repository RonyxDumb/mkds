/* Decompiled C draft; module arm9; ROM address 020cc0f8. No matching claim. */
#include "types.h"
#include "deps/020cc0f8_GetB488_B5.h"

uint GetB488_B5(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020cc108 & 0xfffffffc) >> (uRam020cc108 & 3) * 8 |
          *(uint *)(uRam020cc108 & 0xfffffffc) << (uRam020cc108 & 3) * -8 + 0x20) + 0x10;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

