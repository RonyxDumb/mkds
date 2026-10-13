/* Decompiled C draft; module arm9; ROM address 021227f8. No matching claim. */
#include "types.h"
#include "deps/021227f8_func_021227f8.h"

uint func_021227f8(uint param_1)

{
  return (uint)*(byte *)((*(uint *)(uRam02122814 & 0xfffffffc) >> (uRam02122814 & 3) * 8 |
                         *(uint *)(uRam02122814 & 0xfffffffc) << (uRam02122814 & 3) * -8 + 0x20) +
                        0x1f55) & 1 << (param_1 & 0xff);
}

