/* Decompiled C draft; module arm9; ROM address 020b8454. No matching claim. */
#include "types.h"
#include "deps/020b8454_GetB3C4_Cell_RaceGoalM.h"

uint GetB3C4_Cell_RaceGoalM(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020b8468 & 0xfffffffc) >> (uRam020b8468 & 3) * 8 |
          *(uint *)(uRam020b8468 & 0xfffffffc) << (uRam020b8468 & 3) * -8 + 0x20) + param_1 * 4 +
          0xe0;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

