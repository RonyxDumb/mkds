/* Decompiled C draft; module arm9; ROM address 021202f0. No matching claim. */
#include "types.h"
#include "deps/021202f0_GetSomeBTKFriendCode.h"

int GetSomeBTKFriendCode(int param_1)

{
  return param_1 * 0x244 +
         (*(uint *)(uRam02120308 & 0xfffffffc) >> (uRam02120308 & 3) * 8 |
         *(uint *)(uRam02120308 & 0xfffffffc) << (uRam02120308 & 3) * -8 + 0x20) + 0x440;
}

