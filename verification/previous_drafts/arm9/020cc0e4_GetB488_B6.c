/* Decompiled C draft; module arm9; ROM address 020cc0e4. No matching claim. */
#include "types.h"
#include "deps/020cc0e4_GetB488_B6.h"

uint GetB488_B6(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020cc0f4 & 0xfffffffc) >> (uRam020cc0f4 & 3) * 8 |
          *(uint *)(uRam020cc0f4 & 0xfffffffc) << (uRam020cc0f4 & 3) * -8 + 0x20) + 0x14;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

