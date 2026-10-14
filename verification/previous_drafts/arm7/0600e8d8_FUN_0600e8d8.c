/* Decompiled C draft; module arm7; ROM address 0600e8d8. No matching claim. */
#include "types.h"
#include "deps/0600e8d8_FUN_0600e8d8.h"

uint FUN_0600e8d8(uint param_1)

{
  return (int)(uint)*(ushort *)
                     ((*(uint *)(DAT_0600e8f4 & 0xfffffffc) >> (DAT_0600e8f4 & 3) * 8 |
                      *(uint *)(DAT_0600e8f4 & 0xfffffffc) << (DAT_0600e8f4 & 3) * -8 + 0x20) +
                     0x52e) >> (param_1 & 0xff) & 1;
}

