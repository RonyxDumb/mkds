/* Decompiled C draft; module arm9; ROM address 020cc5d8. No matching claim. */
#include "types.h"
#include "deps/020cc5d8_GetCurrentRaceRules.h"

uint GetCurrentRaceRules(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020cc5e8 & 0xfffffffc) >> (uRam020cc5e8 & 3) * 8 |
          *(uint *)(uRam020cc5e8 & 0xfffffffc) << (uRam020cc5e8 & 3) * -8 + 0x20) + 0x1c;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

