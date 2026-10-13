/* Decompiled C draft; module arm9; ROM address 0203a8f4. No matching claim. */
#include "types.h"
#include "deps/0203a8f4_GetCurrentRaceMode_1.h"

uint GetCurrentRaceMode_1(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam0203a904 & 0xfffffffc) >> (uRam0203a904 & 3) * 8 |
          *(uint *)(uRam0203a904 & 0xfffffffc) << (uRam0203a904 & 3) * -8 + 0x20) + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

