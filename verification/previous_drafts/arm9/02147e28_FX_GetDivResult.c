/* Decompiled C draft; module arm9; ROM address 02147e28. No matching claim. */
#include "types.h"
#include "deps/02147e28_FX_GetDivResult.h"

uint FX_GetDivResult(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  do {
  } while ((*puRam02147e5c & 0x8000) != 0);
  uVar3 = *(uint *)(uRam02147e60 & 0xfffffffc) >> (uRam02147e60 & 3) * 8 |
          *(uint *)(uRam02147e60 & 0xfffffffc) << (uRam02147e60 & 3) * -8 + 0x20;
  uVar1 = uRam02147e60 + 4 & 3;
  uVar2 = *(uint *)(uRam02147e60 + 4 & 0xfffffffc);
  return uVar3 + 0x80000 >> 0x14 |
         ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + (uint)(0xfff7ffff < uVar3)) * 0x1000;
}

