/* Decompiled C draft; module arm9; ROM address 020b2f18. No matching claim. */
#include "types.h"
#include "deps/020b2f18_GetCurrentMissionLevelStage_0.h"

int GetCurrentMissionLevelStage_0(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(uRam020b2f34 & 0xfffffffc) >> (uRam020b2f34 & 3) * 8 |
          *(uint *)(uRam020b2f34 & 0xfffffffc) << (uRam020b2f34 & 3) * -8 + 0x20;
  uVar2 = uVar4 + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 4) {
    iVar3 = (int)*(char *)(uVar4 + 0x55);
  }
  else {
    iVar3 = -1;
  }
  return iVar3;
}

