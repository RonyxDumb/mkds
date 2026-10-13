/* Decompiled C draft; module arm9; ROM address 02022a90. No matching claim. */
#include "types.h"
#include "deps/02022a90_func_02022a90.h"

int func_02022a90(int param_1)

{
  return param_1 * 0x30 +
         (*(uint *)(uRam02022aa4 & 0xfffffffc) >> (uRam02022aa4 & 3) * 8 |
         *(uint *)(uRam02022aa4 & 0xfffffffc) << (uRam02022aa4 & 3) * -8 + 0x20);
}

