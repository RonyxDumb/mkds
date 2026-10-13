/* Decompiled C draft; module arm9; ROM address 020748a8. No matching claim. */
#include "types.h"
#include "deps/020748a8_GetGlobalHD5.h"

uint GetGlobalHD5(void)

{
  return *(uint *)(uRam020748b4 & 0xfffffffc) >> (uRam020748b4 & 3) * 8 |
         *(uint *)(uRam020748b4 & 0xfffffffc) << (uRam020748b4 & 3) * -8 + 0x20;
}

