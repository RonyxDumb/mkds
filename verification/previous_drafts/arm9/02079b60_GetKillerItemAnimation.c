/* Decompiled C draft; module arm9; ROM address 02079b60. No matching claim. */
#include "types.h"
#include "deps/02079b60_GetKillerItemAnimation.h"

int GetKillerItemAnimation(void)

{
  return (*(uint *)(uRam02079b70 & 0xfffffffc) >> (uRam02079b70 & 3) * 8 |
         *(uint *)(uRam02079b70 & 0xfffffffc) << (uRam02079b70 & 3) * -8 + 0x20) + 0x10c;
}

