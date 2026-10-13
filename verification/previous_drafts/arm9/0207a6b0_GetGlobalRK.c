/* Decompiled C draft; module arm9; ROM address 0207a6b0. No matching claim. */
#include "types.h"
#include "deps/0207a6b0_GetGlobalRK.h"

uint GetGlobalRK(void)

{
  return *(uint *)(uRam0207a6bc & 0xfffffffc) >> (uRam0207a6bc & 3) * 8 |
         *(uint *)(uRam0207a6bc & 0xfffffffc) << (uRam0207a6bc & 3) * -8 + 0x20;
}

