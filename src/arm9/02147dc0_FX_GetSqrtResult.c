/* Decompiled C draft; module arm9; ROM address 02147dc0. No matching claim. */
#include "types.h"
#include "deps/02147dc0_FX_GetSqrtResult.h"

uint FX_GetSqrtResult(void)

{
  do {
  } while ((*puRam02147de4 & 0x8000) != 0);
  return (*(uint *)(uRam02147de8 & 0xfffffffc) >> (uRam02147de8 & 3) * 8 |
         *(uint *)(uRam02147de8 & 0xfffffffc) << (uRam02147de8 & 3) * -8 + 0x20) + 0x200 >> 10;
}

