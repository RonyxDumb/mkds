/* Decompiled C draft; module arm9; ROM address 0203f2a0. No matching claim. */
#include "types.h"
#include "deps/0203f2a0_GetCurrentRaceRules_0.h"

uint GetCurrentRaceRules_0(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam0203f2b0 & 0xfffffffc) >> (uRam0203f2b0 & 3) * 8 |
          *(uint *)(uRam0203f2b0 & 0xfffffffc) << (uRam0203f2b0 & 3) * -8 + 0x20) + 0x1c;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

