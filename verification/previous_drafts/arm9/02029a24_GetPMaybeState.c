/* Decompiled C draft; module arm9; ROM address 02029a24. No matching claim. */
#include "types.h"
#include "deps/02029a24_GetPMaybeState.h"

uint GetPMaybeState(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam02029a34 & 0xfffffffc) >> (uRam02029a34 & 3) * 8 |
          *(uint *)(uRam02029a34 & 0xfffffffc) << (uRam02029a34 & 3) * -8 + 0x20) + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

