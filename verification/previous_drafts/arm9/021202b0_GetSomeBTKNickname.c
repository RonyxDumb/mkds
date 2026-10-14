/* Decompiled C draft; module arm9; ROM address 021202b0. No matching claim. */
#include "types.h"
#include "deps/021202b0_GetSomeBTKNickname.h"

int GetSomeBTKNickname(int param_1)

{
  return param_1 * 0x244 +
         (*(uint *)(uRam021202c8 & 0xfffffffc) >> (uRam021202c8 & 3) * 8 |
         *(uint *)(uRam021202c8 & 0xfffffffc) << (uRam021202c8 & 3) * -8 + 0x20) + 0x228;
}

