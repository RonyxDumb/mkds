/* Decompiled C draft; module arm9; ROM address 020cc67c. No matching claim. */
#include "types.h"
#include "deps/020cc67c_GetCurrentRaceCpuMode.h"

uint GetCurrentRaceCpuMode(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020cc68c & 0xfffffffc) >> (uRam020cc68c & 3) * 8 |
          *(uint *)(uRam020cc68c & 0xfffffffc) << (uRam020cc68c & 3) * -8 + 0x20) + 0x14;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

