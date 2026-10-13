/* Decompiled C draft; module arm7; ROM address 06011ea8. No matching claim. */
#include "types.h"
#include "deps/06011ea8_FUN_06011ea8.h"

void FUN_06011ea8(void)

{
  undefined2 *puVar1;
  
  puVar1 = DAT_06011f2c;
  if (*(short *)((*(uint *)(DAT_06011f28 & 0xfffffffc) >> (DAT_06011f28 & 3) * 8 |
                 *(uint *)(DAT_06011f28 & 0xfffffffc) << (DAT_06011f28 & 3) * -8 + 0x20) + 0x35c) !=
      0) {
    *DAT_06011f2c = 0;
    puVar1[2] = 0;
    *DAT_06011f30 = *DAT_06011f30 | 0x8000;
    return;
  }
  *DAT_06011f34 = 1;
  *DAT_06011f38 = 0;
  *DAT_06011f3c = 2;
  *DAT_06011f44 = (short)DAT_06011f40;
  *DAT_06011f48 = 0;
  *DAT_06011f4c = 0;
  return;
}

