/* Decompiled C draft; module arm9; ROM address 020cc690. No matching claim. */
#include "types.h"
#include "deps/020cc690_GetCurrentCupIndex.h"

uint GetCurrentCupIndex(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020cc6a0 & 0xfffffffc) >> (uRam020cc6a0 & 3) * 8 |
          *(uint *)(uRam020cc6a0 & 0xfffffffc) << (uRam020cc6a0 & 3) * -8 + 0x20) + 4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

