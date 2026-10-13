/* Decompiled C draft; module arm9_ov003; ROM address 021c3534. No matching claim. */
#include "types.h"
#include "deps/021c3534_FUN_021c3534.h"

void FUN_021c3534(void)

{
  FUN_021bf620(DAT_021c357c,DAT_021c3580);
  *DAT_021c3584 = *DAT_021c3584 & 0xfffc | 3;
  *DAT_021c3588 = *DAT_021c3588 & 0xfffc | 3;
  *DAT_021c358c = *DAT_021c358c & 0xfffc | 3;
  *DAT_021c3590 = *DAT_021c3590 & 0xfffc | 3;
  *DAT_021c3594 = *DAT_021c3594 & 0xfffc | 3;
  return;
}

