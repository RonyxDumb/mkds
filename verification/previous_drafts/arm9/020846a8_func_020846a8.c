/* Decompiled C draft; module arm9; ROM address 020846a8. No matching claim. */
#include "types.h"
#include "deps/020846a8_func_020846a8.h"

int func_020846a8(int param_1)

{
  return param_1 * 0x58 +
         (*(uint *)(uRam020846bc & 0xfffffffc) >> (uRam020846bc & 3) * 8 |
         *(uint *)(uRam020846bc & 0xfffffffc) << (uRam020846bc & 3) * -8 + 0x20);
}

