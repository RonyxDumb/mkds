/* Decompiled C draft; module arm9; ROM address 0203f280. No matching claim. */
#include "types.h"
#include "deps/0203f280_func_0203f280.h"

short func_0203f280(void)

{
  return (short)*(char *)((*(uint *)(uRam0203f29c & 0xfffffffc) >> (uRam0203f29c & 3) * 8 |
                          *(uint *)(uRam0203f29c & 0xfffffffc) << (uRam0203f29c & 3) * -8 + 0x20) +
                         0x474);
}

