/* Decompiled C draft; module arm9; ROM address 020b2a4c. No matching claim. */
#include "types.h"
#include "deps/020b2a4c_IsRaceEnded.h"

uint IsRaceEnded(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020b2a5c & 0xfffffffc) >> (uRam020b2a5c & 3) * 8 |
          *(uint *)(uRam020b2a5c & 0xfffffffc) << (uRam020b2a5c & 3) * -8 + 0x20) + 0x4cc;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

