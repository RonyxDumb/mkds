/* Decompiled C draft; module arm9; ROM address 020b1d34. No matching claim. */
#include "types.h"
#include "deps/020b1d34_func_020b1d34.h"

int func_020b1d34(void)

{
  return (*(uint *)(uRam020b1d48 & 0xfffffffc) >> (uRam020b1d48 & 3) * 8 |
         *(uint *)(uRam020b1d48 & 0xfffffffc) << (uRam020b1d48 & 3) * -8 + 0x20) + iRam020b1d4c;
}

