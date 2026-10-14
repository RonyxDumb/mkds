/* Decompiled C draft; module arm7; ROM address 0600d894. No matching claim. */
#include "types.h"
#include "deps/0600d894_FUN_0600d894.h"

void FUN_0600d894(void)

{
  uint uVar1;
  
  uVar1 = *(uint *)(DAT_0600d918 & 0xfffffffc) >> (DAT_0600d918 & 3) * 8 |
          *(uint *)(DAT_0600d918 & 0xfffffffc) << (DAT_0600d918 & 3) * -8 + 0x20;
  *DAT_0600d91c = 0x8000;
  if ((((*(short *)(uVar1 + 0x34c) == 0x40) && (*(short *)(uVar1 + 0x3c2) != 0)) &&
      (*(short *)(uVar1 + 0x3b6) == *(short *)(uVar1 + 0x3b4))) &&
     (*(short *)(uVar1 + 0x3c4) = *(short *)(uVar1 + 0x3c4) + 1,
     *(ushort *)(uVar1 + 0x3c2) < *(ushort *)(uVar1 + 0x3c4))) {
    *(undefined2 *)(uVar1 + 0x3c4) = 0;
    FUN_06008a8c(1,0xd);
  }
  *(undefined2 *)(uVar1 + 0x354) = 1;
  return;
}

