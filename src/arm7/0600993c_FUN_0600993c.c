/* Decompiled C draft; module arm7; ROM address 0600993c. No matching claim. */
#include "types.h"
#include "deps/0600993c_FUN_0600993c.h"

void FUN_0600993c(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(DAT_060099b8 & 0xfffffffc) >> (DAT_060099b8 & 3) * 8 |
          *(uint *)(DAT_060099b8 & 0xfffffffc) << (DAT_060099b8 & 3) * -8 + 0x20;
  uVar1 = uVar3 + 0x3ec & 3;
  uVar2 = *(uint *)(uVar3 + 0x3ec & 0xfffffffc);
  *(uint *)(uVar3 + 0x3ec) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 1;
  FUN_06008a8c(1,10);
  FUN_06008a8c(2,0x12);
  FUN_06008a8c(1,0x11);
  if (*(short *)(uVar3 + 0x1fc) != 0) {
    FUN_06008a8c(2,0x13);
  }
  if (*(short *)(uVar3 + 0x3f4) != 0) {
    FUN_06008a8c(2,0x15);
  }
  return;
}

