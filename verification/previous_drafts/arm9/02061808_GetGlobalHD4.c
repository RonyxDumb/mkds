/* Decompiled C draft; module arm9; ROM address 02061808. No matching claim. */
#include "types.h"
#include "deps/02061808_GetGlobalHD4.h"

uint GetGlobalHD4(void)

{
  return *(uint *)(uRam02061814 & 0xfffffffc) >> (uRam02061814 & 3) * 8 |
         *(uint *)(uRam02061814 & 0xfffffffc) << (uRam02061814 & 3) * -8 + 0x20;
}

