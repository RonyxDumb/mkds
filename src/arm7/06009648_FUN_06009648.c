/* Decompiled C draft; module arm7; ROM address 06009648. No matching claim. */
#include "types.h"
#include "deps/06009648_FUN_06009648.h"

undefined2 FUN_06009648(void)

{
  uint uVar1;
  
  uVar1 = *(uint *)(DAT_06009674 & 0xfffffffc) >> (DAT_06009674 & 3) * 8 |
          *(uint *)(DAT_06009674 & 0xfffffffc) << (DAT_06009674 & 3) * -8 + 0x20;
  *(short *)(uVar1 + 0x5f4) =
       *(short *)(uVar1 + 0x5f4) * *(short *)(uVar1 + 0x5f0) + *(short *)(uVar1 + 0x5f2);
  return *(undefined2 *)(uVar1 + 0x5f4);
}

