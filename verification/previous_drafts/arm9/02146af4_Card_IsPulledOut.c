/* Decompiled C draft; module arm9; ROM address 02146af4. No matching claim. */
#include "types.h"
#include "deps/02146af4_Card_IsPulledOut.h"

uint Card_IsPulledOut(void)

{
  return *(uint *)(uRam02146b00 & 0xfffffffc) >> (uRam02146b00 & 3) * 8 |
         *(uint *)(uRam02146b00 & 0xfffffffc) << (uRam02146b00 & 3) * -8 + 0x20;
}

