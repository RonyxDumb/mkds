/* Decompiled C draft; module arm9; ROM address 020887d8. No matching claim. */
#include "types.h"
#include "deps/020887d8_FormatCharacterEmblemNsbmdPath.h"

char * FormatCharacterEmblemNsbmdPath(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = uRam02088868;
  if (param_2 == 0) {
    uVar4 = iRam0208886c + param_1 * 0xc;
    uVar3 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar4 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  }
  else {
    uVar4 = iRam02088864 + param_1 * 0xc;
    uVar3 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar4 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  }
  uVar3 = iRam02088874 + param_1 * 4;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  _snprintf(pcRam0208887c,0x100,pcRam02088880,
            *(uint *)(uRam02088878 & 0xfffffffc) >> (uRam02088878 & 3) * 8 |
            *(uint *)(uRam02088878 & 0xfffffffc) << (uRam02088878 & 3) * -8 + 0x20,
            *(uint *)(uRam02088870 & 0xfffffffc) >> (uRam02088870 & 3) * 8 |
            *(uint *)(uRam02088870 & 0xfffffffc) << (uRam02088870 & 3) * -8 + 0x20,
            uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  _snprintf(pcRam0208887c,0x100,pcRam02088884,pcRam0208887c,uVar4,uVar2);
  return pcRam0208887c;
}

