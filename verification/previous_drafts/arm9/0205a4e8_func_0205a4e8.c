/* Decompiled C draft; module arm9; ROM address 0205a4e8. No matching claim. */
#include "types.h"
#include "deps/0205a4e8_func_0205a4e8.h"

int func_0205a4e8(int param_1,int param_2)

{
  return param_1 * 0x88 +
         (*(uint *)(uRam0205a508 & 0xfffffffc) >> (uRam0205a508 & 3) * 8 |
         *(uint *)(uRam0205a508 & 0xfffffffc) << (uRam0205a508 & 3) * -8 + 0x20) + 0x124 +
         param_2 * 2;
}

