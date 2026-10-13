/* Decompiled C draft; module arm9; ROM address 020364e8. No matching claim. */
#include "types.h"
#include "deps/020364e8_GetActiveExecutionContext.h"

uint GetActiveExecutionContext(void)

{
  return *(uint *)(uRam020364f4 & 0xfffffffc) >> (uRam020364f4 & 3) * 8 |
         *(uint *)(uRam020364f4 & 0xfffffffc) << (uRam020364f4 & 3) * -8 + 0x20;
}

