/* Decompiled C draft; module arm9; ROM address 020884bc. No matching claim. */
#include "types.h"
#include "deps/020884bc_FormatKartShadowNsbmdPath.h"

char * FormatKartShadowNsbmdPath(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = iRam02088508 + param_1 * 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  _snprintf(pcRam02088510,0x100,pcRam02088514,
            *(uint *)(uRam0208850c & 0xfffffffc) >> (uRam0208850c & 3) * 8 |
            *(uint *)(uRam0208850c & 0xfffffffc) << (uRam0208850c & 3) * -8 + 0x20,
            *(uint *)(uRam02088504 & 0xfffffffc) >> (uRam02088504 & 3) * 8 |
            *(uint *)(uRam02088504 & 0xfffffffc) << (uRam02088504 & 3) * -8 + 0x20,
            uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  return pcRam02088510;
}

