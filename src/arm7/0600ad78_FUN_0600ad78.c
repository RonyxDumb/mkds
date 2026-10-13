/* Decompiled C draft; module arm7; ROM address 0600ad78. No matching claim. */
#include "types.h"
#include "deps/0600ad78_FUN_0600ad78.h"

void FUN_0600ad78(void)

{
  uint uVar1;
  
  if (*(short *)((*(uint *)(DAT_0600add8 & 0xfffffffc) >> (DAT_0600add8 & 3) * 8 |
                 *(uint *)(DAT_0600add8 & 0xfffffffc) << (DAT_0600add8 & 3) * -8 + 0x20) + 0x5f8) ==
      2) {
    FUN_06009e30(DAT_0600addc);
  }
  uVar1 = FUN_06009e98(0x1e);
  FUN_06009e58(0x1e,uVar1 | 0x3f);
  *DAT_0600ade4 = (short)DAT_0600ade0;
  *DAT_0600ade8 = 1;
  return;
}

