/* Decompiled C draft; module arm9; ROM address 020ceeec. No matching claim. */
#include "types.h"
#include "deps/020ceeec_func_020ceeec.h"

int func_020ceeec(void)

{
  return (*(uint *)(uRam020cef00 & 0xfffffffc) >> (uRam020cef00 & 3) * 8 |
         *(uint *)(uRam020cef00 & 0xfffffffc) << (uRam020cef00 & 3) * -8 + 0x20) + iRam020cef04;
}

