/* Decompiled C draft; module arm9; ROM address 0203f320. No matching claim. */
#include "types.h"
#include "deps/0203f320_GetCurrentRacerCount.h"

undefined1 GetCurrentRacerCount(void)

{
  return *(undefined1 *)
          ((*(uint *)(uRam0203f330 & 0xfffffffc) >> (uRam0203f330 & 3) * 8 |
           *(uint *)(uRam0203f330 & 0xfffffffc) << (uRam0203f330 & 3) * -8 + 0x20) + 0x3d0);
}

