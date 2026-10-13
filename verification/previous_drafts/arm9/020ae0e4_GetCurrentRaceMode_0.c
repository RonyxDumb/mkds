/* Decompiled C draft; module arm9; ROM address 020ae0e4. No matching claim. */
#include "types.h"
#include "deps/020ae0e4_GetCurrentRaceMode_0.h"

uint GetCurrentRaceMode_0(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020ae0f4 & 0xfffffffc) >> (uRam020ae0f4 & 3) * 8 |
          *(uint *)(uRam020ae0f4 & 0xfffffffc) << (uRam020ae0f4 & 3) * -8 + 0x20) + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

