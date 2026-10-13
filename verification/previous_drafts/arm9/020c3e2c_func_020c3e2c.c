/* Decompiled C draft; module arm9; ROM address 020c3e2c. No matching claim. */
#include "types.h"
#include "deps/020c3e2c_func_020c3e2c.h"

int func_020c3e2c(int param_1)

{
  return (*(uint *)(uRam020c3e40 & 0xfffffffc) >> (uRam020c3e40 & 3) * 8 |
         *(uint *)(uRam020c3e40 & 0xfffffffc) << (uRam020c3e40 & 3) * -8 + 0x20) + 0xb8 +
         param_1 * 8;
}

