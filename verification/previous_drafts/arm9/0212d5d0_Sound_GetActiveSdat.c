/* Decompiled C draft; module arm9; ROM address 0212d5d0. No matching claim. */
#include "types.h"
#include "deps/0212d5d0_Sound_GetActiveSdat.h"

uint Sound_GetActiveSdat(void)

{
  return *(uint *)(uRam0212d5dc & 0xfffffffc) >> (uRam0212d5dc & 3) * 8 |
         *(uint *)(uRam0212d5dc & 0xfffffffc) << (uRam0212d5dc & 3) * -8 + 0x20;
}

