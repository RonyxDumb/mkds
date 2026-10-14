/* Decompiled C draft; module arm9; ROM address 020ae0c8. No matching claim. */
#include "types.h"
#include "deps/020ae0c8_GetRacerCharacterId_0.h"

uint GetRacerCharacterId_0(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 * 0x30 +
          (*(uint *)(uRam020ae0e0 & 0xfffffffc) >> (uRam020ae0e0 & 3) * 8 |
          *(uint *)(uRam020ae0e0 & 0xfffffffc) << (uRam020ae0e0 & 3) * -8 + 0x20) + 0x68;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

