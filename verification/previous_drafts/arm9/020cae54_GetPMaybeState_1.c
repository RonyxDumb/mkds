/* Decompiled C draft; module arm9; ROM address 020cae54. No matching claim. */
#include "types.h"
#include "deps/020cae54_GetPMaybeState_1.h"

uint GetPMaybeState_1(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020cae64 & 0xfffffffc) >> (uRam020cae64 & 3) * 8 |
          *(uint *)(uRam020cae64 & 0xfffffffc) << (uRam020cae64 & 3) * -8 + 0x20) + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

