/* Decompiled C draft; module arm9; ROM address 020b29b0. No matching claim. */
#include "types.h"
#include "deps/020b29b0_GetPMaybeState_0.h"

uint GetPMaybeState_0(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020b29c0 & 0xfffffffc) >> (uRam020b29c0 & 3) * 8 |
          *(uint *)(uRam020b29c0 & 0xfffffffc) << (uRam020b29c0 & 3) * -8 + 0x20) + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

