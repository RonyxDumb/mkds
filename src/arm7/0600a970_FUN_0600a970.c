/* Decompiled C draft; module arm7; ROM address 0600a970. No matching claim. */
#include "types.h"
#include "deps/0600a970_FUN_0600a970.h"

void FUN_0600a970(uint param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(DAT_0600aa04 & 0xfffffffc) >> (DAT_0600aa04 & 3) * 8 |
          *(uint *)(DAT_0600aa04 & 0xfffffffc) << (DAT_0600aa04 & 3) * -8 + 0x20;
  if (*(ushort *)(uVar1 + 0x34c) != param_1) {
    if (*(ushort *)(uVar1 + 0x34c) == 0x40) {
      FUN_0600983c();
    }
    if (param_1 == 0) {
      FUN_0600ad78();
    }
    else if (param_1 == 0x10) {
      FUN_0600adec(0);
      FUN_06009ecc();
      FUN_0600ace4();
    }
    else if (param_1 == 0x40) {
      if (*(short *)(uVar1 + 0x350) == 2) {
        FUN_0600abf8();
      }
      FUN_060099e0(100,DAT_0600aa08);
    }
    *(short *)(uVar1 + 0x34c) = (short)param_1;
  }
  return;
}

