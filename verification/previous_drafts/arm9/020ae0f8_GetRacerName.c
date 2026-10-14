/* Decompiled C draft; module arm9; ROM address 020ae0f8. No matching claim. */
#include "types.h"
#include "deps/020ae0f8_GetRacerName.h"

uint GetRacerName(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 * 0x30 +
          (*(uint *)(uRam020ae110 & 0xfffffffc) >> (uRam020ae110 & 3) * 8 |
          *(uint *)(uRam020ae110 & 0xfffffffc) << (uRam020ae110 & 3) * -8 + 0x20) + 0x88;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

