/* Decompiled C draft; module arm7; ROM address 06014818. No matching claim. */
#include "types.h"
#include "deps/06014818_FUN_06014818.h"

void FUN_06014818(void)

{
  undefined4 uVar1;
  short *psVar2;
  
  psVar2 = (short *)((*(uint *)(DAT_060148c4 & 0xfffffffc) >> (DAT_060148c4 & 3) * 8 |
                     *(uint *)(DAT_060148c4 & 0xfffffffc) << (DAT_060148c4 & 3) * -8 + 0x20) +
                    DAT_060148c8);
  uVar1 = thunk_FUN_037f8850(0x1000000);
  if (*(short *)((*(uint *)(DAT_060148c4 & 0xfffffffc) >> (DAT_060148c4 & 3) * 8 |
                 *(uint *)(DAT_060148c4 & 0xfffffffc) << (DAT_060148c4 & 3) * -8 + 0x20) + 0x350) ==
      1) {
    *DAT_060148cc = 9;
    if (psVar2[0x14] != 0) {
      FUN_060147a0(2);
    }
    FUN_060143cc(2,1);
  }
  else {
    *DAT_060148cc = 1;
  }
  if (*psVar2 != 0) {
    FUN_060147a0(0);
  }
  FUN_060143cc(0,1);
  thunk_FUN_037f888c(uVar1);
  return;
}

