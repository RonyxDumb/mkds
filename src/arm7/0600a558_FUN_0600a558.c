/* Decompiled C draft; module arm7; ROM address 0600a558. No matching claim. */
#include "types.h"
#include "deps/0600a558_FUN_0600a558.h"

uint FUN_0600a558(uint param_1)

{
  return (uint)*(ushort *)
                ((*(uint *)(DAT_0600a574 & 0xfffffffc) >> (DAT_0600a574 & 3) * 8 |
                 *(uint *)(DAT_0600a574 & 0xfffffffc) << (DAT_0600a574 & 3) * -8 + 0x20) + 0x32c) &
         1 << (param_1 & 0xff);
}

