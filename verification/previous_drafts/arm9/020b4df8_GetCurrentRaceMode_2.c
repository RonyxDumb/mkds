/* Decompiled C draft; module arm9; ROM address 020b4df8. No matching claim. */
#include "types.h"
#include "deps/020b4df8_GetCurrentRaceMode_2.h"

uint GetCurrentRaceMode_2(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020b4e08 & 0xfffffffc) >> (uRam020b4e08 & 3) * 8 |
          *(uint *)(uRam020b4e08 & 0xfffffffc) << (uRam020b4e08 & 3) * -8 + 0x20) + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

