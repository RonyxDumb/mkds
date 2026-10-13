/* Decompiled C draft; module arm9; ROM address 020b83ac. No matching claim. */
#include "types.h"
#include "deps/020b83ac_GetB3C4_Cell_RaceGoalTeamS.h"

uint GetB3C4_Cell_RaceGoalTeamS(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020b83c0 & 0xfffffffc) >> (uRam020b83c0 & 3) * 8 |
          *(uint *)(uRam020b83c0 & 0xfffffffc) << (uRam020b83c0 & 3) * -8 + 0x20) + param_1 * 4 +
          0x6ac;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

