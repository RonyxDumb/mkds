/* Decompiled C draft; module arm7; ROM address 0600aa54. No matching claim. */
#include "types.h"
#include "deps/0600aa54_FUN_0600aa54.h"

void FUN_0600aa54(void)

{
  uint uVar1;
  
  uVar1 = *(uint *)(DAT_0600aab0 & 0xfffffffc) >> (DAT_0600aab0 & 3) * 8 |
          *(uint *)(DAT_0600aab0 & 0xfffffffc) << (DAT_0600aab0 & 3) * -8 + 0x20;
  *(undefined2 *)(uVar1 + 0x3ae) = 0;
  FUN_0600f040();
  *DAT_0600aab4 = 0;
  *DAT_0600aab8 = 0;
  if (*(short *)(uVar1 + 0x3cc) != 0) {
    FUN_060145f8();
    FUN_0600ebbc(*(undefined2 *)(uVar1 + 0x3cc),0x20);
    *(undefined2 *)(uVar1 + 0x3cc) = 0;
  }
  return;
}

