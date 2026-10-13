/* Decompiled C draft; module arm9; ROM address 020ae3d8. No matching claim. */
#include "types.h"
#include "deps/020ae3d8_func_020ae3d8.h"

int func_020ae3d8(void)

{
  return (*(uint *)(uRam020ae3ec & 0xfffffffc) >> (uRam020ae3ec & 3) * 8 |
         *(uint *)(uRam020ae3ec & 0xfffffffc) << (uRam020ae3ec & 3) * -8 + 0x20) + iRam020ae3f0;
}

