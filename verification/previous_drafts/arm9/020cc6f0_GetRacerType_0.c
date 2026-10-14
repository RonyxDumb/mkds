/* Decompiled C draft; module arm9; ROM address 020cc6f0. No matching claim. */
#include "types.h"
#include "deps/020cc6f0_GetRacerType_0.h"

uint GetRacerType_0(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 * 0x30 +
          (*(uint *)(uRam020cc708 & 0xfffffffc) >> (uRam020cc708 & 3) * 8 |
          *(uint *)(uRam020cc708 & 0xfffffffc) << (uRam020cc708 & 3) * -8 + 0x20) + 0x70;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

