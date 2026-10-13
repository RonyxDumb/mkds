/* Decompiled C draft; module arm9; ROM address 0205a50c. No matching claim. */
#include "types.h"
#include "deps/0205a50c_func_0205a50c.h"

bool func_0205a50c(uint param_1)

{
  return ((uint)*(byte *)((*(uint *)(uRam0205a530 & 0xfffffffc) >> (uRam0205a530 & 3) * 8 |
                          *(uint *)(uRam0205a530 & 0xfffffffc) << (uRam0205a530 & 3) * -8 + 0x20) +
                         0x749) & 1 << (param_1 & 0xff)) != 0;
}

