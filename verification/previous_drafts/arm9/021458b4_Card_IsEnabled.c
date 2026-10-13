/* Decompiled C draft; module arm9; ROM address 021458b4. No matching claim. */
#include "types.h"
#include "deps/021458b4_Card_IsEnabled.h"

uint Card_IsEnabled(void)

{
  return *(uint *)(uRam021458c0 & 0xfffffffc) >> (uRam021458c0 & 3) * 8 |
         *(uint *)(uRam021458c0 & 0xfffffffc) << (uRam021458c0 & 3) * -8 + 0x20;
}

