/* Decompiled C draft; module arm9; ROM address 02142aa8. No matching claim. */
#include "types.h"
#include "deps/02142aa8_Wm_GetGlobal.h"

uint Wm_GetGlobal(void)

{
  return *(uint *)(uRam02142ab4 & 0xfffffffc) >> (uRam02142ab4 & 3) * 8 |
         *(uint *)(uRam02142ab4 & 0xfffffffc) << (uRam02142ab4 & 3) * -8 + 0x20;
}

