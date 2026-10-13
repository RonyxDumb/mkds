/* Decompiled C draft; module arm9; ROM address 020cc668. No matching claim. */
#include "types.h"
#include "deps/020cc668_GetRacerCount.h"

undefined1 GetRacerCount(void)

{
  return *(undefined1 *)
          ((*(uint *)(uRam020cc678 & 0xfffffffc) >> (uRam020cc678 & 3) * 8 |
           *(uint *)(uRam020cc678 & 0xfffffffc) << (uRam020cc678 & 3) * -8 + 0x20) + 0x3d0);
}

