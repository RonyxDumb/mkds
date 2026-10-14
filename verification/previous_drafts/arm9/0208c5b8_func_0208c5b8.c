/* Decompiled C draft; module arm9; ROM address 0208c5b8. No matching claim. */
#include "types.h"
#include "deps/0208c5b8_func_0208c5b8.h"

int func_0208c5b8(int param_1)

{
  return param_1 * 0x88 +
         (*(uint *)(uRam0208c5cc & 0xfffffffc) >> (uRam0208c5cc & 3) * 8 |
         *(uint *)(uRam0208c5cc & 0xfffffffc) << (uRam0208c5cc & 3) * -8 + 0x20);
}

