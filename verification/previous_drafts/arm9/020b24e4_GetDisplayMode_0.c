/* Decompiled C draft; module arm9; ROM address 020b24e4. No matching claim. */
#include "types.h"
#include "deps/020b24e4_GetDisplayMode_0.h"

uint GetDisplayMode_0(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020b24f4 & 0xfffffffc) >> (uRam020b24f4 & 3) * 8 |
          *(uint *)(uRam020b24f4 & 0xfffffffc) << (uRam020b24f4 & 3) * -8 + 0x20) + 0xc;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

