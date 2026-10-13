/* Decompiled C draft; module arm7; ROM address 038010c4. No matching claim. */
#include "types.h"
#include "deps/038010c4_FUN_038010c4.h"

uint FUN_038010c4(void)

{
  if (*(uint *)(DAT_0380110c & 0xfffffffc) >> (DAT_0380110c & 3) * 8 == 0 &&
      *(uint *)(DAT_0380110c & 0xfffffffc) << (DAT_0380110c & 3) * -8 + 0x20 == 0) {
    if ((*DAT_03801110 & 1) == 0) {
      FUN_03801030();
    }
    else {
      FUN_0380105c();
    }
  }
  return *(uint *)(DAT_0380110c & 0xfffffffc) >> (DAT_0380110c & 3) * 8 |
         *(uint *)(DAT_0380110c & 0xfffffffc) << (DAT_0380110c & 3) * -8 + 0x20;
}

