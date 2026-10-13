/* Decompiled C draft; module arm9; ROM address 020b83f4. No matching claim. */
#include "types.h"
#include "deps/020b83f4_GetB3C4_Cell_RaceGoalMrM.h"

uint GetB3C4_Cell_RaceGoalMrM(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020b8408 & 0xfffffffc) >> (uRam020b8408 & 3) * 8 |
          *(uint *)(uRam020b8408 & 0xfffffffc) << (uRam020b8408 & 3) * -8 + 0x20) + param_1 * 4 +
          0x2b8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

