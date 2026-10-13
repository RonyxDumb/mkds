/* Decompiled C draft; module arm9; ROM address 020cc618. No matching claim. */
#include "types.h"
#include "deps/020cc618_GetIsMirror.h"

int GetIsMirror(void)

{
  return (int)*(char *)((*(uint *)(uRam020cc628 & 0xfffffffc) >> (uRam020cc628 & 3) * 8 |
                        *(uint *)(uRam020cc628 & 0xfffffffc) << (uRam020cc628 & 3) * -8 + 0x20) +
                       0x57);
}

