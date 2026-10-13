/* Decompiled C draft; module arm9; ROM address 020e6b14. No matching claim. */
#include "types.h"
#include "deps/020e6b14_func_020e6b14.h"

int func_020e6b14(void)

{
  return (*(uint *)(uRam020e6b24 & 0xfffffffc) >> (uRam020e6b24 & 3) * 8 |
         *(uint *)(uRam020e6b24 & 0xfffffffc) << (uRam020e6b24 & 3) * -8 + 0x20) + 0x18;
}

