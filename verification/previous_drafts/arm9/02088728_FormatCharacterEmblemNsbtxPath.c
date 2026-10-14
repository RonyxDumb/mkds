/* Decompiled C draft; module arm9; ROM address 02088728. No matching claim. */
#include "types.h"
#include "deps/02088728_FormatCharacterEmblemNsbtxPath.h"

char * FormatCharacterEmblemNsbtxPath(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = uRam020887b8;
  if (param_2 == 0) {
    uVar4 = iRam020887bc + param_1 * 0xc;
    uVar3 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar4 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  }
  else {
    uVar4 = iRam020887b4 + param_1 * 0xc;
    uVar3 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar4 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  }
  uVar3 = iRam020887c4 + param_1 * 4;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  _snprintf(pcRam020887cc,0x100,pcRam020887d0,
            *(uint *)(uRam020887c8 & 0xfffffffc) >> (uRam020887c8 & 3) * 8 |
            *(uint *)(uRam020887c8 & 0xfffffffc) << (uRam020887c8 & 3) * -8 + 0x20,
            *(uint *)(uRam020887c0 & 0xfffffffc) >> (uRam020887c0 & 3) * 8 |
            *(uint *)(uRam020887c0 & 0xfffffffc) << (uRam020887c0 & 3) * -8 + 0x20,
            uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  _snprintf(pcRam020887cc,0x100,pcRam020887d4,pcRam020887cc,uVar4,uVar2);
  return pcRam020887cc;
}

