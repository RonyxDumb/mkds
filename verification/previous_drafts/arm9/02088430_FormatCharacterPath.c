/* Decompiled C draft; module arm9; ROM address 02088430. No matching claim. */
#include "types.h"
#include "deps/02088430_FormatCharacterPath.h"

char * FormatCharacterPath(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = iRam0208847c + param_1 * 4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  _snprintf(pcRam02088484,0x100,pcRam02088488,
            *(uint *)(uRam02088480 & 0xfffffffc) >> (uRam02088480 & 3) * 8 |
            *(uint *)(uRam02088480 & 0xfffffffc) << (uRam02088480 & 3) * -8 + 0x20,
            *(uint *)(uRam02088478 & 0xfffffffc) >> (uRam02088478 & 3) * 8 |
            *(uint *)(uRam02088478 & 0xfffffffc) << (uRam02088478 & 3) * -8 + 0x20,
            uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  return pcRam02088484;
}

