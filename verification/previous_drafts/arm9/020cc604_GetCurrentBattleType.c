/* Decompiled C draft; module arm9; ROM address 020cc604. No matching claim. */
#include "types.h"
#include "deps/020cc604_GetCurrentBattleType.h"

uint GetCurrentBattleType(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020cc614 & 0xfffffffc) >> (uRam020cc614 & 3) * 8 |
          *(uint *)(uRam020cc614 & 0xfffffffc) << (uRam020cc614 & 3) * -8 + 0x20) + 0x18;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

