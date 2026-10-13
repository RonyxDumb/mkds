/* Decompiled C draft; module arm9; ROM address 020b33f4. No matching claim. */
#include "types.h"
#include "deps/020b33f4_GetRaceStartCountdown.h"

uint GetRaceStartCountdown(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(uRam020b340c & 0xfffffffc) >> (uRam020b340c & 3) * 8 |
          *(uint *)(uRam020b340c & 0xfffffffc) << (uRam020b340c & 3) * -8 + 0x20;
  if (uVar2 == 0) {
    uVar2 = 0xffffff88;
  }
  else {
    uVar2 = uVar2 + 8;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  }
  return uVar2;
}

