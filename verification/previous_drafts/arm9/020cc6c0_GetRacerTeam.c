/* Decompiled C draft; module arm9; ROM address 020cc6c0. No matching claim. */
#include "types.h"
#include "deps/020cc6c0_GetRacerTeam.h"

uint GetRacerTeam(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 * 0x30 +
          (*(uint *)(uRam020cc6d8 & 0xfffffffc) >> (uRam020cc6d8 & 3) * 8 |
          *(uint *)(uRam020cc6d8 & 0xfffffffc) << (uRam020cc6d8 & 3) * -8 + 0x20) + 0x74;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

