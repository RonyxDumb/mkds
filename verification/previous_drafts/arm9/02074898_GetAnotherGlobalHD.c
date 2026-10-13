/* Decompiled C draft; module arm9; ROM address 02074898. No matching claim. */
#include "types.h"
#include "deps/02074898_GetAnotherGlobalHD.h"

uint GetAnotherGlobalHD(void)

{
  return *(uint *)(uRam020748a4 & 0xfffffffc) >> (uRam020748a4 & 3) * 8 |
         *(uint *)(uRam020748a4 & 0xfffffffc) << (uRam020748a4 & 3) * -8 + 0x20;
}

