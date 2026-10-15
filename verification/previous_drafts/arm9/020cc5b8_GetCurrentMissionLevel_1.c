/* Decompiled C draft; module arm9; ROM address 020cc5b8. No matching claim. */
#include "types.h"
#include "deps/020cc5b8_GetCurrentMissionLevel_1.h"

int GetCurrentMissionLevel_1(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(uRam020cc5d4 & 0xfffffffc) >> (uRam020cc5d4 & 3) * 8 |
          *(uint *)(uRam020cc5d4 & 0xfffffffc) << (uRam020cc5d4 & 3) * -8 + 0x20;
  uVar2 = uVar4 + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 4) {
    iVar3 = (int)*(char *)(uVar4 + 0x54);
  }
  else {
    iVar3 = -1;
  }
  return iVar3;
}

