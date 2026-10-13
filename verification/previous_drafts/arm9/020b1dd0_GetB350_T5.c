/* Decompiled C draft; module arm9; ROM address 020b1dd0. No matching claim. */
#include "types.h"
#include "deps/020b1dd0_GetB350_T5.h"

uint GetB350_T5(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(uRam020b1de0 & 0xfffffffc) >> (uRam020b1de0 & 3) * 8 |
          *(uint *)(uRam020b1de0 & 0xfffffffc) << (uRam020b1de0 & 3) * -8 + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

