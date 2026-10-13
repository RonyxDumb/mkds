/* Decompiled C draft; module arm9; ROM address 02122778. No matching claim. */
#include "types.h"
#include "deps/02122778_func_02122778.h"

int func_02122778(int param_1)

{
  return (int)*(char *)((*(uint *)(uRam02122790 & 0xfffffffc) >> (uRam02122790 & 3) * 8 |
                        *(uint *)(uRam02122790 & 0xfffffffc) << (uRam02122790 & 3) * -8 + 0x20) +
                        param_1 + 0x1f4e);
}

