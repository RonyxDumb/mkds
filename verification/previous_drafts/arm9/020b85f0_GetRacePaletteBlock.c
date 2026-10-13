/* Decompiled C draft; module arm9; ROM address 020b85f0. No matching claim. */
#include "types.h"
#include "deps/020b85f0_GetRacePaletteBlock.h"

int GetRacePaletteBlock(int param_1)

{
  return (*(uint *)(uRam020b8608 & 0xfffffffc) >> (uRam020b8608 & 3) * 8 |
         *(uint *)(uRam020b8608 & 0xfffffffc) << (uRam020b8608 & 3) * -8 + 0x20) + iRam020b860c +
         param_1 * 0x10;
}

