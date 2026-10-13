/* Decompiled C draft; module arm9; ROM address 020be930. No matching claim. */
#include "types.h"
#include "deps/020be930_func_020be930.h"

void func_020be930(int param_1)

{
  *(undefined4 *)
   (param_1 * 0xc +
    (*(uint *)(uRam020be94c & 0xfffffffc) >> (uRam020be94c & 3) * 8 |
    *(uint *)(uRam020be94c & 0xfffffffc) << (uRam020be94c & 3) * -8 + 0x20) + 0xfc) = 0;
  return;
}

