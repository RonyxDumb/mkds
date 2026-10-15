/* Decompiled C draft; module arm9; ROM address 020adbe4. No matching claim. */
#include "types.h"
#include "deps/020adbe4_GetCurrentMissionLevel.h"

int GetCurrentMissionLevel(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(uRam020adc00 & 0xfffffffc) >> (uRam020adc00 & 3) * 8 |
          *(uint *)(uRam020adc00 & 0xfffffffc) << (uRam020adc00 & 3) * -8 + 0x20;
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

