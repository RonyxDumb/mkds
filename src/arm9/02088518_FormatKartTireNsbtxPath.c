/* Decompiled C draft; module arm9; ROM address 02088518. No matching claim. */
#include "types.h"
#include "deps/02088518_FormatKartTireNsbtxPath.h"

char * FormatKartTireNsbtxPath(undefined4 param_1,undefined4 param_2)

{
  _snprintf(pcRam0208856c,0x100,pcRam02088570,
            *(uint *)(uRam02088568 & 0xfffffffc) >> (uRam02088568 & 3) * 8 |
            *(uint *)(uRam02088568 & 0xfffffffc) << (uRam02088568 & 3) * -8 + 0x20,
            *(uint *)(uRam02088560 & 0xfffffffc) >> (uRam02088560 & 3) * 8 |
            *(uint *)(uRam02088560 & 0xfffffffc) << (uRam02088560 & 3) * -8 + 0x20,param_2,
            uRam02088564);
  return pcRam0208856c;
}

