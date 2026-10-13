/* Decompiled C draft; module arm9; ROM address 02088574. No matching claim. */
#include "types.h"
#include "deps/02088574_FormatKartTireNsbmdPath.h"

char * FormatKartTireNsbmdPath(undefined4 param_1,undefined4 param_2)

{
  _snprintf(pcRam020885c8,0x100,pcRam020885cc,
            *(uint *)(uRam020885c4 & 0xfffffffc) >> (uRam020885c4 & 3) * 8 |
            *(uint *)(uRam020885c4 & 0xfffffffc) << (uRam020885c4 & 3) * -8 + 0x20,
            *(uint *)(uRam020885bc & 0xfffffffc) >> (uRam020885bc & 3) * 8 |
            *(uint *)(uRam020885bc & 0xfffffffc) << (uRam020885bc & 3) * -8 + 0x20,param_2,
            uRam020885c0);
  return pcRam020885c8;
}

