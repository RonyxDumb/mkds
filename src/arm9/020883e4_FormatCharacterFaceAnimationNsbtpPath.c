/* Decompiled C draft; module arm9; ROM address 020883e4. No matching claim. */
#include "types.h"
#include "deps/020883e4_FormatCharacterFaceAnimationNsbtpPath.h"

char * FormatCharacterFaceAnimationNsbtpPath(void)

{
  _snprintf(pcRam02088428,0x100,pcRam0208842c,
            *(uint *)(uRam02088424 & 0xfffffffc) >> (uRam02088424 & 3) * 8 |
            *(uint *)(uRam02088424 & 0xfffffffc) << (uRam02088424 & 3) * -8 + 0x20,
            *(uint *)(uRam02088420 & 0xfffffffc) >> (uRam02088420 & 3) * 8 |
            *(uint *)(uRam02088420 & 0xfffffffc) << (uRam02088420 & 3) * -8 + 0x20);
  return pcRam02088428;
}

