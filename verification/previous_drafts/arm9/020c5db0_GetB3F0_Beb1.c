/* Decompiled C draft; module arm9; ROM address 020c5db0. No matching claim. */
#include "types.h"
#include "deps/020c5db0_GetB3F0_Beb1.h"

uint GetB3F0_Beb1(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020c5dc0 & 0xfffffffc) >> (uRam020c5dc0 & 3) * 8 |
          *(uint *)(uRam020c5dc0 & 0xfffffffc) << (uRam020c5dc0 & 3) * -8 + 0x20) + 4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

