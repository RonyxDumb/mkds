/* Decompiled C draft; module arm9; ROM address 02079b74. No matching claim. */
#include "types.h"
#include "deps/02079b74_GetSomeAD00Sh.h"

int GetSomeAD00Sh(void)

{
  return (*(uint *)(uRam02079b84 & 0xfffffffc) >> (uRam02079b84 & 3) * 8 |
         *(uint *)(uRam02079b84 & 0xfffffffc) << (uRam02079b84 & 3) * -8 + 0x20) + 0x98;
}

