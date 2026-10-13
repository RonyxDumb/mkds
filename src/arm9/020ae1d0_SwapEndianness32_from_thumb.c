/* Decompiled C draft; module arm9; ROM address 020ae1d0. No matching claim. */
#include "types.h"
#include "deps/020ae1d0_SwapEndianness32_from_thumb.h"

int SwapEndianness32_from_thumb(uint param_1)

{
  return (param_1 >> 0x18) +
         (param_1 >> 0x10 & 0xff) * 0x100 + param_1 * 0x1000000 + (param_1 >> 8 & 0xff) * 0x10000;
}

