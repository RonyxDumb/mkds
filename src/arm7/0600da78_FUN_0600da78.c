/* Decompiled C draft; module arm7; ROM address 0600da78. No matching claim. */
#include "types.h"
#include "deps/0600da78_FUN_0600da78.h"

void FUN_0600da78(void)

{
  uint uVar1;
  
  uVar1 = *(uint *)(DAT_0600db30 & 0xfffffffc) >> (DAT_0600db30 & 3) * 8 |
          *(uint *)(DAT_0600db30 & 0xfffffffc) << (DAT_0600db30 & 3) * -8 + 0x20;
  if ((*DAT_0600db34 == 0) && (*(short *)(uVar1 + 0x1b4) != 0)) {
    *DAT_0600db38 = 8;
    FUN_0601536c(2);
  }
  else {
    if (((*(ushort *)(uVar1 + 0x52e) & ~*(ushort *)(uVar1 + 0x532)) == 0) &&
       (*DAT_0600db38 = 8, *(short *)(uVar1 + 0x1b4) != 0)) {
      FUN_0601536c(2);
    }
    *DAT_0600db38 = 5;
    if (*(short *)(uVar1 + 0x1a8) != 0) {
      FUN_0601536c(1);
    }
    if (*(short *)(uVar1 + 0x19c) != 0) {
      FUN_0601536c(0);
    }
  }
  return;
}

