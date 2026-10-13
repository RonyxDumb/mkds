/* Decompiled C draft; module arm9; ROM address 020cc120. No matching claim. */
#include "types.h"
#include "deps/020cc120_GetB488_SinglePlayerMenuTarget.h"

uint GetB488_SinglePlayerMenuTarget(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020cc130 & 0xfffffffc) >> (uRam020cc130 & 3) * 8 |
          *(uint *)(uRam020cc130 & 0xfffffffc) << (uRam020cc130 & 3) * -8 + 0x20) + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

